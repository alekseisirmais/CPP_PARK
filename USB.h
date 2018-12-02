//---------------------------------------------------------------------------
#ifndef USBH
#define USBH
//---------------------------------------------------------------------------
#include <cfgmgr32.h>

#include <vector>

const int USB_IS_ON_DB = 1;
const int USB_IS_NOT_ON_DB = 2;
const unsigned long USB_HAS_NO_DEVINST = -1;

struct USB {
	DEVINST devInst;
	int vid;
	int pid;

  	USB(const DEVINST &_devInst, const int &_vid, const int &_pid);
	const bool operator != (const USB &_usb);
	const bool operator == (const USB &_usb);
};

bool GetUSBVidAndPid(TCHAR DeviceInstance[], int &vid, int &pid);

#endif

