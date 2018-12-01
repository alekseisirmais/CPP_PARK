#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Lines->Clear();
	ServerSocket1->Port = 9001;
	ServerSocket1->Active = false;
	Memo1->Lines->Add("Server port: 9001; Server don't run");
	Button1->Caption = "Start";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MyOnClientConnectEvent(TObject *Sender, TCustomWinSocket *Socket)

{
	Memo1->Lines->Add("Client connected");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (ServerSocket1->Active) {
		ServerSocket1->Active = false;
		Memo1->Lines->Add("Server paused");
		Button1->Caption = "Start";
	}
	else {
		ServerSocket1->Active = true;
		Memo1->Lines->Add("Server activated");
		Button1->Caption = "Stop";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	HDEVINFO deviceInfoSet = GetConnectedDevicesHandle();
	if (!deviceInfoSet) {
		Memo1->Lines->Add("ERROR: can't get devices handle");
		SetupDiDestroyDeviceInfoList(deviceInfoSet);
		return;
	}

	std::vector<USB> USBlist = GetConnectedUsbList(deviceInfoSet);
	if (USBlist.empty()) {
		Memo1->Lines->Add("USB devices not found");
		SetupDiDestroyDeviceInfoList(deviceInfoSet);
		return;
	}

	for (size_t i = 0; i < USBlist.size(); i++) {
		Memo1->Lines->Add("USB " + IntToStr((int)(i + 1)) + ":");
		Memo1->Lines->Add("   VID: " + IntToStr(USBlist[i].vid));
		Memo1->Lines->Add("   PID: " + IntToStr(USBlist[i].pid));
	}
	SetupDiDestroyDeviceInfoList(deviceInfoSet);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	DWORD error,
		dwPropertyRegDataType,
		dwSize;
	CONST GUID *pClassGuid = &GUID_DEVINTERFACE_USB_DEVICE;
	TCHAR szDeviceInstanceID [MAX_DEVICE_ID_LEN];
	PCWSTR enumerator = TEXT("USB");
	TCHAR szDesc[1024],
		szHardwareIDs[4096];
	LPTSTR pszToken,
		pszNextToken;
	TCHAR szVid[MAX_DEVICE_ID_LEN],
		szPid[MAX_DEVICE_ID_LEN],
			szMi[MAX_DEVICE_ID_LEN];
	rsize_t *strmax = NULL;

	SP_DEVINFO_DATA deviceInfoData;
	ZeroMemory(&deviceInfoData, sizeof(SP_DEVINFO_DATA));
	deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

	HDEVINFO deviceInfoSet = SetupDiGetClassDevs(
		pClassGuid,
		enumerator,
		NULL,
		// DIGCF_PRESENT Возвращайте только устройства, которые в
		// настоящее время присутствуют в системе.
		DIGCF_ALLCLASSES | DIGCF_PRESENT
	);
	if (deviceInfoSet == INVALID_HANDLE_VALUE) {
		error = GetLastError();
		Memo1->Lines->Add("INVALID_HANDLE_VALUE" + IntToStr((int)error));
		return;
	}

	for (DWORD i = 0; ; i++) {
		deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
		if (!SetupDiEnumDeviceInfo(deviceInfoSet, i, &deviceInfoData)) {
			break;
		}

		CONFIGRET status = CM_Get_Device_ID(deviceInfoData.DevInst, szDeviceInstanceID , MAX_PATH, 0);
		if (status != CR_SUCCESS) {
			continue;
		}


		if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_DEVICEDESC,
											  &dwPropertyRegDataType, (BYTE*)szDesc,
											  sizeof(szDesc),   // The size, in bytes
											  &dwSize)) {

		}

		if (WideCharToString(szDesc) != "USB Mass Storage Device") {
			continue;
		}

		int vid = 0;
		int pid = 0;
		GetUSBVidAndPid(szDeviceInstanceID, vid, pid);
		USB usb(vid, pid);

		if (USBIsOnDatabase(USBDatabaseName, usb)) {
			continue;
		}

		DEVINST DevInstParent = deviceInfoData.DevInst;
		WCHAR VetoNameW[MAX_PATH];
		PNP_VETO_TYPE VetoType = PNP_VetoTypeUnknown;
		for ( long tries=1; tries <= 10; tries++ ) {
			VetoNameW[0] = 0;
			CONFIGRET res = CM_Request_Device_EjectW(DevInstParent,
				&VetoType, VetoNameW, MAX_PATH, 0);

			bool bSuccess = ( res==CR_SUCCESS &&
				VetoType==PNP_VetoTypeUnknown );
			if ( bSuccess )  {
				Memo1->Lines->Add("USB(" + IntToStr(vid) + ", " + IntToStr(pid) + ") ejected");
				break;
			}
			Sleep(5);
		}
	}
	SetupDiDestroyDeviceInfoList(deviceInfoSet);
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int vid = 58;
	int pid = 6387;
	USB usb(vid, pid);
	AddUsbToDatabase(USBDatabaseName, usb);
}
//---------------------------------------------------------------------------

