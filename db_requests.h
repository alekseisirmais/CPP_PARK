//---------------------------------------------------------------------------

#ifndef db_requestsH
#define db_requestsH
//---------------------------------------------------------------------------
#include "USB.h"
#include <vector>


std::vector<USB> GetUSBListFromDB(const AnsiString &file);
bool USBIsOnDatabase(const AnsiString &file, USB &usb);
int AddUsbToDatabase(const AnsiString &file, USB &usb);
int DeleteUsbFromDatabase(const AnsiString &file, USB &usb);


#endif
