//---------------------------------------------------------------------------

#pragma hdrstop

#include "db_requests.h"
//---------------------------------------------------------------------------


std::vector<USB> GetUSBListFromDB(const AnsiString &file) {
	TStringList *list1 = new TStringList;
	list1->LoadFromFile(file);
	std::vector<USB> res;

	for (int i = 0; i < list1->Count; i++) {
		AnsiString str = list1[0][i];
		int StrLenInt = str.Length();
		int SpacePlaceInt = str.Pos(" ");
		int vid = StrToInt(str.SubString(1, SpacePlaceInt - 1));
		//AnsiStrings always start with 1 and not 0
		int pid = StrToInt(str.SubString(SpacePlaceInt + 1, StrLenInt));
		USB usb(vid, pid);
		res.push_back(usb);
	}
	delete list1;
	return res;
}

bool USBIsOnDatabase(const AnsiString &file, USB &usb) {
	std::vector<USB> USBList = GetUSBListFromDB(file);
	for (size_t i = 0; i < USBList.size(); i++) {
		if (USBList[i] == usb) {
			return true;
		}
	}
	return false;
}


int AddUsbToDatabase(const AnsiString &file, USB &usb) {
	if (USBIsOnDatabase(file, usb)) {
		return USB_IS_ON_DB;
	}

	TStringList *list1 = new TStringList;
	AnsiString USBstring = IntToStr(usb.vid) + " " + IntToStr(usb.pid);
	list1->Add(USBstring);
	if (!FileExists(file)) {
		list1->SaveToFile(file);
		return 0;
	}

	TStringList *list2 = new TStringList;
	list2->LoadFromFile(file);

	list2->Text = list2->Text + list1->Text;
	list2->SaveToFile(file);
	delete list1;
	delete list2;
	return 0;
}

int DeleteUsbFromDatabase(const AnsiString &file, USB &usb) {
	if (!USBIsOnDatabase(file, usb)) {
		return USB_IS_NOT_ON_DB;
	}
	TStringList *list1 = new TStringList;
	list1->LoadFromFile(file);
	std::vector<USB> res;

    int deletingStringIndex = -1;
	for (int i = 0; i < list1->Count; i++) {
		AnsiString str = list1[0][i];
		int StrLenInt = str.Length();
		int SpacePlaceInt = str.Pos(" ");
		int vid = StrToInt(str.SubString(1, SpacePlaceInt - 1));
		//AnsiStrings always start with 1 and not 0
		int pid = StrToInt(str.SubString(SpacePlaceInt + 1, StrLenInt));
		USB _usb(vid, pid);
		if (_usb == usb) {
			deletingStringIndex = i;
			break;
		}
	}
	if (deletingStringIndex != -1) {
		list1[0].Delete(deletingStringIndex);
		list1->SaveToFile(file);
	}
	delete list1;
	return 0;
}

#pragma package(smart_init)
