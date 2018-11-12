#ifndef RequestH
#define RequestH

#include <fmx.h>
#include <User.H>

/*
	GET_USERS_LIST,
	GET_USER_DECRIPTION,
	GET_USB_DEVICES_LIST,
	GET_USB_DEVICE_DESCRIPTION,
	ADD_NEW_USER,
	ADD_NEW_USB_DEVICE,
	DELETE_USER,
	DELETE_USB_DEVICE
*/

int GetUsersList(User user);
int GetUserDescription(User user);
int GetUsbDevicesList(User user);
int GetUsbDeviceDescription(User user);
int AddNewUser(User user);
int AddNewUsbDevice(User user);
int DeleteUser(User user);
int DeleteUsbDevice(User user);

// int MakeRequest(User user, int id);
#endif