//---------------------------------------------------------------------------

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
	ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ClientSocket1->Address = "127.0.0.1";
	ClientSocket1->Port = 9001;
	ClientSocket1->Active = true;
	Memo1->Lines->Add(ClientSocket1->Host);

}
//---------------------------------------------------------------------------
