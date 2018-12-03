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
	RunThread *runThr = new RunThread(true);
    runThr->Start();
	Memo1->Lines->Clear();
	ServerSocket1->Port = 9001;
	ServerSocket1->Active = false;
	Memo1->Lines->Add("Server port: 9001; Server don't run");
	Button1->Caption = "Start";
	isRunning = false;
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
		isRunning = false;
		Memo1->Lines->Add("Server paused");
		Button1->Caption = "Start";
	}
	else {
		ServerSocket1->Active = true;
        isRunning = true;
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

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Memo1->Lines->Add("");
	HDEVINFO deviceInfoSet0 = GetConnectedDevicesHandle();
	if (deviceInfoSet0 == INVALID_HANDLE_VALUE) {
		SetupDiDestroyDeviceInfoList(deviceInfoSet0);
		Memo1->Lines->Add("Error: INVALID_HANDLE_VALUE");
		return;
	}

	std::vector<USB> USBList = GetConnectedUsbList(deviceInfoSet0);
	if (USBList.empty()) {
		Memo1->Lines->Add("USB devices not found");
		SetupDiDestroyDeviceInfoList(deviceInfoSet0);
		return;
	}

	for (size_t i = 0; i < USBList.size(); i++) {
		Memo1->Lines->Add("USB сonnected list:");
		Memo1->Lines->Add("   USB [" + IntToStr((int)i) + "] :");
		if (USBIsOnDatabase(USBList[i])) {
			Memo1->Lines->Add("      Status: registered on database.");
		} else {
            Memo1->Lines->Add("      Status: unregistered on database.");
		}
		Memo1->Lines->Add("      devInst: " + IntToStr((int)USBList[i].devInst));
		Memo1->Lines->Add("      VID: " + IntToStr(USBList[i].vid));
		Memo1->Lines->Add("      PID: " + IntToStr(USBList[i].pid));
	}
	SetupDiDestroyDeviceInfoList(deviceInfoSet0);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int vid = StrToInt(Edit1->Text);
	int pid = StrToInt(Edit2->Text);
	USB usb(NULL, vid, pid);
	AddUsbToDatabase(usb);
	Memo1->Lines->Add("USB added to database:");
	Memo1->Lines->Add("      VID: " + IntToStr(usb.vid));
	Memo1->Lines->Add("      PID: " + IntToStr(usb.pid));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int vid = StrToInt(Edit1->Text);
	int pid = StrToInt(Edit2->Text);
	USB usb(NULL, vid, pid);
	DeleteUsbFromDatabase(usb);
	Memo1->Lines->Add("USB deleted from database:");
	Memo1->Lines->Add("      VID: " + IntToStr(usb.vid));
	Memo1->Lines->Add("      PID: " + IntToStr(usb.pid));
}
//---------------------------------------------------------------------------

