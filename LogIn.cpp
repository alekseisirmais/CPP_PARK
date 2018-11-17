//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "LogIn.h"
#include "SecurityPolicySettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool passed_authorization(UnicodeString username, UnicodeString password) {
	// Here should be authorization
	return true;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if ((Edit1->Text == "") || (Edit2->Text == "")) {
		ShowMessage("Both fields must be filled");
		return;
	}
	if (passed_authorization(Edit1->Text, Edit2->Text)) {
		TForm2 *f2 = new TForm2( this );
		f2->Left = this->Left;
		f2->Top = this->Top;

		Edit1->Text = "";
		Edit2->Text = "";
		this->Hide();

		f2->ShowModal();
		Form1->Left = f2->Left;
		Form1->Top = f2->Top;
		delete f2;

		this->Close();
	} else {
		ShowMessage("Your username or password is incorrect");
    }
}
//---------------------------------------------------------------------------



