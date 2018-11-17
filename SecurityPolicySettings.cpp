//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "SecurityPolicySettings.h"
#include "Settings.h"
#include "ViewLogs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	for (int i = 0; i < StringGrid1->ColumnCount; i++) {
		for (int j = 0; j < StringGrid1->RowCount; j++) {
			StringGrid1->Cells[i][j] = "";
		}
	}
}
//---------------------------------------------------------------------------





void __fastcall TForm2::ViewLogsClick(TObject *Sender)
{
	TForm3 *f3 = new TForm3( this );
	f3->Left = this->Left;
	f3->Top = this->Top;
	this->Hide();

	f3->ShowModal();
	this->Left = f3->Left;
	this->Top = f3->Top;
	delete f3;

	this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SettingsClick(TObject *Sender)
{
	TForm4 *f4 = new TForm4( this );
	f4->Left = this->Left;
	f4->Top = this->Top;
	this->Hide();

	f4->ShowModal();
	this->Left = f4->Left;
	this->Top = f4->Top;
	delete f4;

	this->Show();
}
//---------------------------------------------------------------------------

