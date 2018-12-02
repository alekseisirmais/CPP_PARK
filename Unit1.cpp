#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool isRunning;

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
	isRunning = true;
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
	if (deviceInfoSet == INVALID_HANDLE_VALUE) {
        SetupDiDestroyDeviceInfoList(deviceInfoSet);
		Memo1->Lines->Add("Error: INVALID_HANDLE_VALUE");
		return;
	}

	std::vector<USB> USBList = GetConnectedUsbList(deviceInfoSet);
	if (USBList.empty()) {
		Memo1->Lines->Add("USB devices not found");
		SetupDiDestroyDeviceInfoList(deviceInfoSet);
		return;
	}

	for (size_t i = 0; i < USBList.size(); i++) {
		Memo1->Lines->Add("USB ñonnected listÆ");
		Memo1->Lines->Add("   USB " + IntToStr((int)(i + 1)) + ":");
		Memo1->Lines->Add("      VID: " + IntToStr(USBList[i].vid));
		Memo1->Lines->Add("      PID: " + IntToStr(USBList[i].pid));
	}
	SetupDiDestroyDeviceInfoList(deviceInfoSet);
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	isRunning = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	while (isRunning) {
		HDEVINFO deviceInfoSet = GetConnectedDevicesHandle();
		if (deviceInfoSet == INVALID_HANDLE_VALUE) {
			Memo1->Lines->Add("Error: INVALID_HANDLE_VALUE");
            SetupDiDestroyDeviceInfoList(deviceInfoSet);
			return;
		}
		std::vector<USB> USBList = GetConnectedUsbList(deviceInfoSet);

		for (size_t i = 0; i < USBList.size(); i++) {
			USB usb = USBList[i];
			int vid = usb.vid;
            int pid = usb.pid;

			if (USBIsOnDatabase(usb)) {
				continue;
			}

			DEVINST DevInstParent = usb.devInst;
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
}
//---------------------------------------------------------------------------

