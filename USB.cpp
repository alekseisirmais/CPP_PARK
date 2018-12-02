//---------------------------------------------------------------------------

#pragma hdrstop

#include "USB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


USB::USB(const DEVINST &_devInst, const int &_vid, const int &_pid) {
	devInst = _devInst;
	vid = _vid;
	pid = _pid;
}

bool GetUSBVidAndPid(TCHAR DeviceInstance[], int &vid, int &pid) {
	try {
		vid = 0;
		pid = 0;
		// Example of DeviceInstance: USB\VID_058F&PID_6387\DD1BA51B
		int i = 0;
		while ((DeviceInstance[i] < '0') || (DeviceInstance[i] > '9')) {
			i++;
		}

		while ((DeviceInstance[i] >= '0') && (DeviceInstance[i] <= '9')) {
			vid = vid * 10 + DeviceInstance[i] - '0';
			i++;
		}

		while ((DeviceInstance[i] < '0') || (DeviceInstance[i] > '9')) {
			i++;
		}

		while ((DeviceInstance[i] >= '0') && (DeviceInstance[i] <= '9')) {
			pid = pid * 10 + DeviceInstance[i] - '0';
			i++;
		}
		return true;
	} catch (int e) {
		return false;
	}
	return false;
}

const bool USB::operator != (const USB &_usb) {
	if ((vid != _usb.vid) || (pid != _usb.pid)) {
		return true;
	}
	return false;
}
const bool USB::operator == (const USB &_usb) {
	if ((vid == _usb.vid) && (pid == _usb.pid)) {
		return true;
	}
	return false;
}

