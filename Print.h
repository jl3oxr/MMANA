//Copyright+LGPL

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Copyright 1999-2013 Makoto Mori, Nobuyuki Oba
//-----------------------------------------------------------------------------------------------------------------------------------------------
// This file is part of MMANA.

// MMANA is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// MMANA is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License along with MMANA.  If not, see
// <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef PrintH
#define PrintH
//---------------------------------------------------------------------------	// ja7ude 1.0
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#include "ComLib.h"
#define	COLMAX	16				// �����ł����̐�
class TPrintDlgBox : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPrintDialog *PrintDialog;
	TButton *AbortBtn;
	TLabel *Stat;
	
	void __fastcall AbortBtnClick(TObject *Sender);
private:	// ���[�U�[�錾
	int		mAbort;				// ����̒��~

    int		mColCount;			// �����̐�
    int		mRowCount;			// ����s�̐�
	int		mMaxRow;			// ���݊m�ۂ��Ă���s�̐�

    TRect	mMG;				// �}�[�W�����i�p�[�Z���g�j
	TRect	mRC;				// ����͈͂̍��W���i�s�N�Z���j
	int		mPW;				// ����͈͂̉����i�s�N�Z���j
    int		mPH;				// ����͈͂̏c���i�s�N�Z���j
	double	mXW;
    double	mYW;
	TRect	mBC;				// �g�̕`��͈�
	int		mPage;				// ���݂̃y�[�W
    int		mPageMax;			// �S�y�[�W��
    int		mPageLine;			// �P�y�[�W������̍s��
	int		mWidthP[COLMAX];	// �e��̉����i�䗦�W���j
    int		mWidth[COLMAX];		// �e��̉����i�s�N�Z���j
	int		mLeft[COLMAX];		// �e��̈���ʒu
    LPCSTR	mTitle[COLMAX];		// �^�C�g���̃��X�g
	LPCSTR	*mbp;				// �e���ڃ��X�g�̃x�[�X�|�C���^
   	SYSTEMTIME	mTime;			// ����J�n����
	AnsiString	mDocTitle;		// �h�L�������g�^�C�g��

    TCanvas	*cp;				// �o�̓f�o�C�X
private:
	LPSTR __fastcall StrDup(LPCSTR p);
	void __fastcall AllocRow(int row);
	void __fastcall Delete(void);
	int __fastcall GetCenter(int w, LPCSTR p);

	void __fastcall DispPageStat(void);
	int __fastcall InitSetup(TCanvas *p);
	void __fastcall DrawRect(void);
	void __fastcall DrawPage(void);

public:		// ���[�U�[�錾
	__fastcall TPrintDlgBox(TComponent* Owner);
	__fastcall ~TPrintDlgBox();

    int __fastcall Execute(void);
	inline void __fastcall SetDocTitle(LPCSTR pTitle){
		mDocTitle = pTitle;
    };
	void __fastcall SetMargin(int left, int top, int right, int bottom);
	void __fastcall SetWidth(int col, int w);
	void __fastcall SetTitle(int col, LPCSTR p);
	void __fastcall SetString(int row, int col, LPCSTR p);
};
//---------------------------------------------------------------------------
//extern TPrintDlgBox *PrintDlgBox;
//---------------------------------------------------------------------------
#endif
