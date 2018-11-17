//---------------------------------------------------------------------------

#ifndef ViewLogsH
#define ViewLogsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
#include <Web.HTTPApp.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser1;
	void __fastcall FormCreate(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
