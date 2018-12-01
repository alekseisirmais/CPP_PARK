//---------------------------------------------------------------------------
#ifndef USBH
#define USBH
//---------------------------------------------------------------------------
#include <vector>

const int USB_IS_ON_DB = 1;
const int USB_IS_NOT_ON_DB = 2;

struct USB {
	int vid;
	int pid;
	bool isEjected;
	USB(int _vid, int _pid);
	const bool operator != (const USB &_usb);
	const bool operator == (const USB &_usb);
};

bool GetUSBVidAndPid(TCHAR DeviceInstance[], int &vid, int &pid);

#endif
