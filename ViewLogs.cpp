//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ViewLogs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormCreate(TObject *Sender)
{
	WebBrowser1->URL = "models\c++ builder twsdl htmlpublish - Google Search";
}
//---------------------------------------------------------------------------


