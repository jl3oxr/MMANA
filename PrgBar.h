//---------------------------------------------------------------------------

#ifndef PrgBarH
#define PrgBarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProgressForm : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TProgressBar *ProgressBar1;
	TLabel *Label1;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TProgressForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
#endif
