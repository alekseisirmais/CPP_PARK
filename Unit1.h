//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>

#include <SetupAPI.h>
#include <cfgmgr32.h>
#include <initguid.h>
#include <winioctl.h>
#include <windows.h>
#include <vector>
#include <string>

#include "USB.h"
#include "win_requests.h"
#include "db_requests.h"
#include "settings.h"
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TServerSocket *ServerSocket1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button5;
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MyOnClientConnectEvent(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
