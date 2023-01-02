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

#ifndef ComLibH
#define ComLibH
#include <stdio.h>    //ja7ude 1.0
#include <stdlib.h>   //ja7ude 1.0
#include <ExtCtrls.hpp>
#include <inifiles.hpp>
#include <Grids.hpp>
//#include <vcl\comctrls.hpp>
#include <values.h>
#include <math.h>
#include <mbstring.h>
//---------------------------------------------------------------------------
#define	WMAX	512		// ���C���̐�
#define	WZMAX	4096	// �W�J���C���̐�
#define	CMAX	64		// ���d�_�̐�
#define	LMAX	100		// ���[�h�̐�
#define	EMAX	15		// ���̐�
#define	PMAX	8192	// ������p���X�̐�
#define	SMAX	12		// S-DOMAIN�̊K��

#define	PTMAX	10
#define	PPMAX	10

#define	RESMAX	10		// ���ʔ�r�̍ő�̐�

#define	VERSTR	"MMANA Ver1.77 (C) JE3HHT 1999-2000"
#define	VERSTR2	"build 20230103"
#define RESSTR	"MMANA Res1.16\x1a"	// RESVER�Ɠ����l
#define ACALSTR	"MMANA Opt1.13\x1a"	// OPTVER�Ɠ����l
#define	RESVER	116		// RES Ver��ύX�����ꍇ TMainWnd::LoadResFile()���`�F�b�N
#define	OPTVER	113

extern	LPCSTR	FreqTbl[];
extern	const char	ILLFMT[];

//enum TFontPitch { fpDefault, fpVariable, fpFixed };	//JA7UDE 0427

typedef struct {		// ���C���[�̒�`
	double	X1;
	double	Y1;
	double	Z1;
	double	X2;
	double	Y2;
	double	Z2;
	double	R;
	int		SEG;			// �Z�O�����g��

	int		PNo;			// ���C���̊J�n�p���X�ԍ�
	int		PMax;			// �p���X�̐�
}WDEF;
typedef struct {		// ���d�_�̒�`
	char	PLUS[8+1];		// �p���X�ʒu
	int		PLUSNo;			// �p���X�ԍ�
	double	EV;				// �d��
	double	DEG;			// �ʑ�
}CDEF;
typedef struct {		// ���[�h�̒�`
	int     TYPE;			// 0-L,C,Q, 1-R+jX, 2-S-Domain
	char	PLUS[8+1];		// �p���X�ʒu
	int		PLUSNo;			// �p���X�ԍ�
	int		SN;				// �K��
	double	A[SMAX];
	double	B[SMAX];
}LDEF;
typedef struct {		// ������`
	double	RR;				// �Q�Ƃq
	double	L[PPMAX];
	double	R[PPMAX];
	int		Type;			// 0-��������, 1-�n�_����
}PDEF;
typedef struct {		// ���C���[�̒�`
	double	X1;
	double	Y1;
	double	Z1;
	double	X2;
	double	Y2;
	double	Z2;
	double	R;
	int		SEG;			// �Z�O�����g��

	int		Wno;			// �Q�ƌ��̃��C���ԍ��i�O�`�j
	int		PNo;			// ���C���̊J�n�p���X�ԍ�
	int		SNo;			// ���C���̊J�n�Z�O�����g�ԍ� aX[SNo]
	int		SMax;			// �Z�O�����g�ԍ��̍ő�l
}WZDEF;
typedef struct {		// �A���e�i�̒�`
	int		Edit;			// �ҏW�t���O
	int		Flag;			// �ݒ�t���O
	char	Name[129];		// ����
	double	fq;				// �݌v���g��
	int		wmax;			// ���C���[�̐�
	WDEF	wdef[WMAX];		// ���C���[��`
	double	cfq;			// ���d���g��
	int		cmax;			// ���d�_�̐�
	int		cauto;			// ���d�d�������ݒ�
	CDEF	cdef[CMAX];		// ���d�_��`
	int		lenb;			// ���[�h�v�Z������
	int		lmax;
	LDEF	ldef[LMAX];

	int		pmax;
	PDEF	pdef[PTMAX];	// ���C���g�ݍ��킹�f�[�^

	int		wzmax;			// �W�J���C���[�̐�
	WZDEF	wzdef[WZMAX];	// �W�J���C���[��`

	double	MinZ;			// ��`���C���̍ŉ����̂y���W

	double	RMD;			// �g���i�Ɂj
	int		DM1;			// �ŏ������� 1/DM1��
	int		DM2;			// �ő啪���� 1/DM2��
	int		EC;				// �[�_�̃Z�O�����g��
	double	SC;				// �����W�� (1-2)

	int		StackVT;		// �W�J���� 0-�㉺�C�P�|������C�Q�|������
	int		StackH;
	int		StackV;
	double	StackHW;
	double	StackVW;
}ANTDEF;

typedef struct {		// �v�Z��
	int		type;			// 0-���R���, 1-���S��n, 2-���A���O�����h
	double	antheight;		// �n�㍂
	int		mmax;			// ���f�B�A�̐�
	int		mtype;			// ���f�B�A�̎�� 0-���j�A, 1-�O�����h�X�N���[��
	int		gscrcnt;		// ���f�B�A���̖{��
	double	gscrr;			// ���W�A���̔��a
	double	rel[EMAX];		//
	double	cond[EMAX];		//
	double	intval[EMAX];	// ���f�B�A�̋���
	double	height[EMAX];	// ���f�B�A�̍���

	int		fbr;			// F/B��̃o�b�N����r�͈�
	double	RO;				// SWR�̌v�Z�C���s�[�_���X
	double	JXO;			// SWR�̌v�Z�C���s�[�_���X�i���f���j
	int		WireRoss;
	int		pmax;			// �����ő�̃p���X��
	int		FontSize;		// �t�H���g�̃T�C�Y
}ENVDEF;
extern	ENVDEF	env;

typedef struct {		// �d���t�@�C���p������
	int		Flag;
	int		W;
	float	X;
	float	Y;
	float	Z;
	float	I;
	float	IJ;
	float	MAG;
	float	DEG;
}CURFILE;
typedef struct {		// �ߋ����d�E���x�t�@�C��
	FILE	*fp;
	char	Name[256];		// �t�@�C����
	int		TYPE;
	double	POW;
	double	X;
	double	XW;
	int		XN;
	double	Y;
	double	YW;
	int		YN;
	double	Z;
	double	ZW;
	int		ZN;
}NEARFILE;
typedef struct {		// �������d�E���x�t�@�C��
	FILE	*fp;
	char	Name[256];
	double	Z;
	double	ZW;
	int		ZN;
	double	A;
	double	AW;
	int		AN;
}FARFILE;
typedef struct {		// ���s���̒�`
	double	AntXc;			// �A���e�i�`��\���̒��S
	double	AntYc;			// �A���e�i�`��\���̒��S

	int		CalcDisp;		// �œK�����̉�ʍX�V
	int		CalcAbort;		// �œK�����~�t���O
	int		CalcF;			// �v�Z���s�t���O
	int		CalcLog;		// ���O�E�C���h�E�ւ̕\���t���O

	int		RmdSel;			// �G�������g�ҏW�̔g���\�L
	double	rmd;			// �݌v���g���̔g��

	int		IntPos;			// 0-�Ԋu�\�L�C1-�ʒu�\�L
	int		Wave;			// �\���Δg
	int		BwMatch;		// ���g�������̑ш�\���}�b�`���O

	int		Ant3D;			// �R�c�\�����@
	int		CurDir;			// �d�������̕\��
	int		FixFreeAngle;	// ���R��Ԃ̎��͌v�Z�p���O�x�ɌŒ�
	int		RecentMax;		// Recent File �̕\�����鐔
	int		RecentMAA;		// Recent File ��MAA�t�@�C���̂�

	int		WindowState;	// ��ʂ̏��

    int		EleWidthAll;	// �G�������g�ҏW�̍ۂ̉����A�c���̈���

	CURFILE	*pCurFile;		// �d���t�@�C��
	NEARFILE *pNearFile;	// �ߋ����d�E���x�t�B�A��
	FARFILE	*pFarFile;		// �������d�E���x�t�@�C��
}EXEENV;
extern	EXEENV	exeenv;

int GetFileVersion(LPCSTR pbf, LPCSTR pVer);
char LastC(LPCSTR p);
void SetEXT(LPSTR pName, LPSTR pExt);
LPCSTR GetEXT(LPCSTR Fname);
void ZSCopy(LPSTR t, LPCSTR p, int n);
void SetFileName(LPSTR pName);
LPCSTR GetFileName(LPCSTR pName);
LPCSTR StrCLX(double r, double x);
LPCSTR StrCLXZ(double r, double x);
LPCSTR StrCLXF(double r, double x);
LPCSTR StrDbl(double d);
LPCSTR StrDbl3(double d);
LPCSTR StrDbl2(double d);
LPCSTR StrDbl1(double d);
LPCSTR StrDblE(double d);
LPCSTR StrInt(int d);
double RoundUp(double d);
double RoundUp(double d, double s);
double RoundUpStr(double d);
double GetNormal(double d);
void SetCurDir(LPSTR t, int size);
void SetDirName(LPSTR t, LPCSTR pName);
double CalcSWR(double Rl, double Xl, double Ro, double Xo);
void CalcParaZ(double &R, double &X, double f, double L, double C, double Q);
double GetDeg(double x, double y);
void DeleteComment(LPSTR bf);
void ClipLF(LPSTR sp);
LPSTR SkipSpace(LPSTR sp);
LPCSTR SkipSpace(LPCSTR sp);
LPSTR StrDlm(LPSTR &tp, LPSTR sp);
LPSTR StrDlm(LPSTR &tp, LPSTR sp, char c);
void ErrorMB(LPCSTR fmt, ...);
void WarningMB(LPCSTR fmt, ...);
int YesNoMB(LPCSTR fmt, ...);
void Calc3DXY(double &x, double &y, double deg, double zdeg, double X, double Y, double Z);
double ReadDoubleIniFile(TIniFile *p, LPCSTR c1, LPCSTR c2, double d);
void WriteDoubleIniFile(TIniFile *p, LPCSTR c1, LPCSTR c2, double d);

PDEF *FindPP(ANTDEF *ap, double r);
int CombWire(WDEF *tbl, ANTDEF *ap, PDEF *pp, WDEF *wp);
void AddWZ(ANTDEF *ap, double x1, double y1, double z1, double x2, double y2, double z2, double R, int SEG, int wno);
void TeiAvg(ANTDEF *ap, double x1, double y1, double z1, double x2, double y2, double z2, double R, int DM, int wno);
void Tei(ANTDEF *ap, double x1, double y1, double z1, double x2, double y2, double z2, double R, int DM1, int wno);
int SetWZ(ANTDEF *ap);

LPCSTR Seg2Str(int Seg);
int Str2Seg(int &Seg, LPCSTR p);

int Str2PlusNo(ANTDEF *ap, LPCSTR s);
void AdjPlusNo(ANTDEF *ap);

int WriteAntToFp(ANTDEF *ap, AnsiString &rem, FILE *fp);
int ReadAntFromFp(ANTDEF *ap, AnsiString &rem, FILE *fp);
void AdjWireChen(WDEF *wp, double ox, double oy, double oz, double nx, double ny, double nz);
void AdjWireChen(WDEF *wp, int wmax, double ox, double oy, double oz, double nx, double ny, double nz);
void AdjWireChen(WDEF *wp, int wmax, WDEF *np, WDEF *op);
void GetWirePoll(double &WL, double &XYD, double &YZD, WDEF *wp);
int IsLine(POINT &pnt, POINT &spnt, POINT &tpnt, int Width);
int IsLine(POINT &pnt, POINT &spnt, POINT &tpnt);
int DoCalc(void);

double GetRmdVal(double d);
double SetRmdVal(double d);
double GetRmdValD(double d);
double SetRmdValD(double d);

int Calc(double &d, LPCSTR p);
int CalcI(int &d, LPCSTR p);
int CalcU(int &d, LPCSTR p);
void WriteCur(ANTDEF *ap, int W, int P, float I, float IJ, float Mag, float Deg);
void ClipXY(int &x, int &y);
double GetWireRoss(ANTDEF *ap, WDEF *wp);
double GetWireRoss(double f, WDEF *wp);
void FormCenter(TForm *tp, int XW, int YW);
void DrawWirePara(TPaintBox *tp, WDEF *wp, int w);
void DrawWirePara(TPaintBox *tp, ANTDEF *ap, int w);
void AdjPdef(ANTDEF *ap);

extern	char	BgnDir[128];
extern	char	AntDir[128];
extern	char	ResDir[128];
extern	AnsiString	antDef;			// �œK���O�̃A���e�i��`
extern	AnsiString	antSave;		// �L�������A���e�i��`

//---------------------------------------------------------------------------
#define	PAI		3.1415926535897932384626433832795
#define	PAI2	(PAI*2.0)
#define	COS30	0.866025403784438646763723170752936
#define	TAN15	0.267949192431122706472553658494128
#define	SIN15	0.258819045102520762348898837624048
#define	COS15	0.965925826289068286749743199728897
#define	TAN22R5	0.414213562373095048801688724209698
#define	SIN22R5	0.382683432365089771728459984030399
#define	COS22R5	0.923879532511286756128183189396788
#define	RUTE2	1.4142135623730950488016887242097
#define	NULLV	(1.0e-99)
#define	NULLF	float(1.2345e-37)

#define	CR		'\r'
#define	LF		'\n'
#define	TAB		'\t'

#define	ABS(c)	(((c)<0)?(-(c)):(c))
#define	SGN(c)	(((c)<0)?-1:(((c)>0)?1:0))
//---------------------------------------------------------------------------
///---------------------------------------------------------
///  �e�L�X�g�o�b�t�@�X�g���[�}�[
class StrText{
public:
	char	*Bp;
	char	*Wp;
	inline StrText(int max){
		Bp = new char[max];
		Wp = Bp;
	};
	inline ~StrText(){
		delete Bp;
	};
	inline char *Printf(char *ct, ...){
		va_list	pp;

		va_start(pp, ct);
		vsprintf(Wp, ct, pp );
		va_end(pp);
		ct = Wp;
		Wp += strlen(Wp);
		return(ct);
	};
	inline char *GetText(void){
		return Bp;
	};
	inline void Clear(void){
		Wp = Bp;
		*Wp = 0;
	};
};

///---------------------------------------------------------
///  �e�L�X�g�t�@�C���X�g���[�}�[
class CTextFile
{
private:
	char	*Bf;
	int		Len;
	int		Max;
	int		N;
	char	*rp;
	TFileStream *FP;

	inline void LoadBuf(void){
		Len = FP->Read(Bf, Max);
		rp = Bf;
		N = 0;
	}
	inline char GetChar(void){
		char c = *rp++;
		N++;
		if( N >= Len ) LoadBuf();
		return c;
	};

public:
	inline CTextFile(TFileStream *fp, int max = 16384){
		Max = max;
		Bf = new char[Max];
		Len = 0;
		FP = fp;
		LoadBuf();
	};
	inline ~CTextFile(){
		delete Bf;
	}
	inline int LoadText(LPSTR tp, int len){
		char c;
		int n = 0;
		if( !Len ) return FALSE;
		while(Len){
			c = GetChar();
			if( c == LF ){
				*tp = 0;
				return TRUE;
			}
			else if( (c != CR)&&(c != 0x1a) ){
				if( n < (len-1) ){
					*tp++ = c;
					n++;
				}
			}
		}
		*tp = 0;
		return TRUE;
	};
};

///---------------------------------------------------------
///  �e�L�X�g������X�g���[�}�[
class CTextString
{
private:
	LPCSTR	rp;
public:
	inline CTextString(LPCSTR p){
		rp = p;
	};
	inline CTextString(AnsiString &As){
		rp = As.c_str();
	};
	inline int LoadText(LPSTR tp, int len){
		char c;
		int n = 0;
		if( !(*rp) ) return FALSE;
		while(*rp){
			c = *rp++;
			if( c == LF ){
				*tp = 0;
				return TRUE;
			}
			else if( (c != CR)&&(c != 0x1a) ){
				if( n < (len-1) ){
					*tp++ = c;
					n++;
				}
			}
		}
		*tp = 0;
		return TRUE;
	};
	inline int LoadTextLoop(LPSTR tp, int len){
		while(1){
			if( LoadText(tp, len) == FALSE ) break;
			if( *tp != '*' ) return TRUE;
		}
		return FALSE;
	}
};

///---------------------------------------------------------
///  �e�L�X�g������e�h�e�n
class CTextFifo
{
private:
	LPSTR	bp, wp, rp;
	int		Cnt;
	int		Max;
	int 	Line;
public:
	inline CTextFifo(int max = 65536){
		Max = max;
		bp = new char[Max];
		wp = rp = bp;
		Cnt = 0;
		Line = 0;
	};
	inline ~CTextFifo(){
		delete bp;
	};
	inline void WriteChar(char c){
		if( Cnt < Max ){
			if( c != LF ){
				*wp = c;
				wp++;
				if( wp >= (bp+Max) ){
					wp = bp;
				}
				Cnt++;
			}
			if( c == CR ){
				Line++;
			}
		}
	}
	inline void WriteString(LPCSTR sp){
		for( ; *sp; sp++ ){
			WriteChar(*sp);
		}
	};
	inline int GetLine(void){
		return Line;
	};
	inline int LoadText(LPSTR tp, int len){
		if( !Line ) return FALSE;
		while(1){
			char c = *rp;
			rp++;
			if( rp >= (bp+Max) ) rp = bp;
			Cnt--;

			if( c == CR ){
				*tp = 0;
				Line--;
				break;
			}
			else if( (len - 1) > 0 ){
				*tp++ = c;
				len--;
			}
		}
		return TRUE;
	};
};

///----------------------------------------------------------------
///	���f�����Z�N���X
class CLX {
public:
	double	r;
	double	j;
	inline CLX(void){
		r = 0;
		j = 0;
	};
	inline CLX(const double R){
		r = R;
		j = 0;
	};
	inline CLX(const double R, const double J){
		r = R;
		j = J;
	};
	inline CLX(CLX &ref){
		r = ref.r;
		j = ref.j;
	};
	inline void Add(const CLX &ref){
		r += ref.r;
		j += ref.j;
	};
	inline void Sub(const CLX &ref){
		r -= ref.r;
		j -= ref.j;
	};
	void Mul(const CLX &ref);
	void Div(const CLX &ref);
	inline CLX& operator=(const CLX &ref){
		if( this != &ref ){
			r = ref.r;
			j = ref.j;
		}
		return *this;
	};
	inline CLX& operator+=(const CLX &ref){
		Add(ref);
		return *this;
	};
	inline CLX& operator+=(const double R){
		CLX ref(R, 0);
		Add(ref);
		return *this;
	};
	inline CLX& operator-=(const CLX &ref){
		Sub(ref);
		return *this;
	};
	inline CLX& operator-=(const double R){
		CLX ref(R, 0);
		Sub(ref);
		return *this;
	};
	inline CLX& operator*=(const CLX &ref){
		Mul(ref);
		return *this;
	};
	inline CLX& operator*=(const double R){
		CLX ref(R, 0);
		Mul(ref);
		return *this;
	};
	inline CLX& operator/=(const CLX &ref){
		Div(ref);
		return *this;
	};
	inline CLX& operator/=(const double R){
		CLX ref(R, 0);
		Div(ref);
		return *this;
	};
	inline CLX operator+(const CLX &ref) const {
		CLX a(r, j);
		a+=ref;
		return a;
	};
	inline CLX operator+(const double R) const {
		CLX a(r, j);
		a+=R;
		return a;
	};
	inline CLX operator-(const CLX &ref) const {
		CLX a(r, j);
		a-=ref;
		return a;
	};
	inline CLX operator-(const double R) const {
		CLX a(r, j);
		a-=R;
		return a;
	};
	inline CLX operator*(const CLX &ref) const {
		CLX a(r, j);
		a*=ref;
		return a;
	};
	inline CLX operator*(const double R) const {
		CLX a(r, j);
		a*=R;
		return a;
	};
	inline CLX operator/(const CLX &ref) const {
		CLX a(r, j);
		a/=ref;
		return a;
	};
	inline CLX operator/(const double R) const {
		CLX a(r, j);
		a/=R;
		return a;
	};
	friend CLX operator+(const double R, const CLX &ref);
	friend CLX operator-(const double R, const CLX &ref);
	friend CLX operator*(const double R, const CLX &ref);
	friend CLX operator/(const double R, const CLX &ref);
};

#define	BWMAX	5
#define	BWSMAX	(BWMAX-1)
#define	BWSDIMMAX	4
typedef struct {
	int		Flag;	// �L���t���O
	double	FQ;		// ���g��
	double	R;		// �q
	double	JX;		// ���w
	double	GA;
	double	FB;
}BWS;
typedef struct {
	int		Flag;	// �L���t���O
	double	FQ;		// ���g��
	double	R;		// �q
	double	JX;		// ���w
	double	GA;
	double	FB;
	int		PFlag;
	short	PtnH[3][180];
	short	PtnV[3][91];
}BW;
typedef struct {
	int		bcnt;			// ���肵����
	int		bo;				// �݌v�f�[�^�̃C���f�b�N�X
	double	fo;				// �݌v���g��
	double	fw;				// ���g����
	double	bi;				// ���g���Ԋu
	BW		bw[BWMAX];
	int		bwsdim;			// 1, 2, 3, 4
	int		bwsfull;		// 0 or 1
    BWS		bws[BWSMAX][BWSDIMMAX];
	int		MatchCenter;	// �}�b�`���O���g��
    BWS		MatchData;		// �}�b�`���O�f�[�^
}BWC;
typedef struct {		// ����
	int		TYPE;			// �v�Z����
	float	HEIGHT;			// �n�㍂
	float	FQ;
	float	R;
	float	JX;
	float	SWR;
	float	GAIN;
	float	FB;
	float	ELV;
	int		FBR;
	float	RO;				// SWR�v�Z�y
	float	JXO;			// SWR�v�ZZ
	float	MAXHP;			// �����Δg�̍ő�l
	float	MAXVP;			// �����Δg�̍ő�l
	int		Wave;			// �Δg
}RESL;
///---------------------------------------------------------
///  ���ʊǗ��N���X
#define	RMAX	128			// ���ʂ̃q�X�g��
class CRes
{
public:
	char	Name[128];		// �A���e�i�̖���

	int		RWp;			// ���̏������݈ʒu
	int		RCnt;			// ���݂̌��ʂ̐�
	RESL	Res[RMAX];		// ���ʂ̃q�X�g��

	int		CalcF;			// �v�Z�t���O

	int		PtnF;			// �p�^�[���v�Z����\
	int		Voff;
	int		DegF;
	int		DegV;
	int		DegH;
	float	PtnV[3][181];
	float	PtnH[3][360];
	float	MaxH;
	float	MaxV;
	float	MaxG;
	float	MaxEV;
	float	MaxVP;
	float	MaxHP;
	float	Elv;
	float	ElvHPtn;		// �����p�^�[���̋p

	float	Cur[PMAX];		// �d�����z��Βl�f�[�^

	int		CurN;
	BYTE	CurDir[PMAX];	// �d�������f�[�^
	double	RealMax;
	double	ImgMax;

	BWC		Bwc;
public:
	inline CRes(void){
		PtnF = CalcF = 0;
		RWp = 0;
		RCnt = 0;
		RealMax = ImgMax = 0.0;
		memset(&Bwc, 0, sizeof(Bwc));
	};
	inline ~CRes(){
	};
	inline int GetLastRes(double &R, double &X){
		if( RCnt ){
			R = Res[RWp].R;
			X = Res[RWp].JX;
			return TRUE;
		}
		return FALSE;
	};
	inline void Clear(void){
		CalcF = 0;
	};
	inline void SetCalc(LPCSTR pName){
		CalcF = 1;
		strncpy(Name, pName, sizeof(Name));
	}
	inline int IsCalc(void){
		return CalcF;
	};
	inline RESL *GetResP(void){
		return &Res[RWp];
	};
	void IncResP(void);
	RESL *GetResP(int Index);
	inline int GetCnt(void){
		return RCnt;
	};
	inline void SetVert(int off){
		DegF = 1;
		Voff = off;
	};
	inline void SetHori(void){
		Voff = 0;
		DegF = 0;
	};
	inline void SetElv(int off){
		MaxEV = MaxV;
		Voff = off * 10;
		DegF = 2;
		double dv = DegV;
		if( dv >= (90/PtnF) ) dv = (180/PtnF) - dv;
		Elv = dv*PtnF;		// �b��̃s�[�N
	}
	inline double GetElv(void){
		if( Elv >= 90 ) Elv = 180 - Elv;
		return Elv;
	};
	double GetAdjElv(void);
	void SetPtn(float s1, float s2, float s3);
	int GetHMAX(void);
	int GetVMAX(void);
	void CalcPtn(void);
	void ReCalcGain(void);
	void CalcFB(void);
	void ClearCur(void);
	inline void SetCurDir(int n, double r, double j){
		if( r < 0 ){
			CurDir[n] |= 0x01;
			r = -r;
		}
		if( j < 0 ){
			CurDir[n] |= 0x02;
			j = -j;
		}
		if( r > RealMax ) RealMax = r;
		if( j > ImgMax ) ImgMax = j;
		CurN = n;
	}
	inline void SetCur(int n, double r, double j, double d){
		SetCurDir(n, r, j);
		Cur[n] = d;
	};
	void SetCur(ANTDEF *ap, int n, double r, double j, double d);
	inline void FinishCur(void){
		BYTE	CurMask = BYTE(( RealMax > ImgMax ) ? 0x01 : 0x02);
		for( int i = 0; i <= CurN; i++ ){
			if( CurDir[i] & CurMask ) Cur[i] = -Cur[i];
		}
	};
	void DrawRes(TCanvas *tp, int X, int Y);
	void SaveCurData(FILE *fp);
	void LoadCurData(FILE *fp);
	int CopyLastRes(CRes *rp);
	int SetRes(CRes *rp);

	void InitBWC(void);
	void AddBWC(int n);
	void AddBWS(int n, int j);
	void SetBWSDim(int n);
	void UpdateCountBW(void);
	BWS	 *SearchBW(BWC *bp, double fq);
	void ClearBWC(void);
};
extern CRes	res;

///---------------------------------------------------------
///  �p�^�[���`��N���X
class CDrawPtnH
{
public:
	int		xl,yt,xr,yb;
	RECT	rc;				// �~�̐����`
	int		xc, yc;
	int		rr;
	int		ri;
	TCanvas	*tp;			// �L�����o�X�̃|�C���^

	double	Max;			// 0db == max
	TColor	gCol;
	void GetDBR(int &X, int &Y, double deg, double db);
public:
	inline CDrawPtnH(void){
		Max = 0.0;
		tp = NULL;
		gCol = clGray;
	};
	inline ~CDrawPtnH(){
	};
	void SetRect(TCanvas *pc, int x1, int y1, int x2, int y2);
	inline void SetMaxDB(double m){
		Max = m;
	};
	void DrawAngle(int Add = 1);
	void DrawGage(double deg, int i);
	void DrawPtn(float *pt, int Add, TColor Col = clBlack);
};


///---------------------------------------------------------
///  �p�^�[���`��N���X
class CDrawPtnV
{
public:
	int		xl,yt,xr,yb;
	RECT	rc;				// �~�̐����`
	int		xc, yc;
	int		rr;
	int		ri;
	TCanvas	*tp;			// �L�����o�X�̃|�C���^

	double	Max;			// 0db == max
	TColor	gCol;
	void GetDBR(int &X, int &Y, double deg, double db);
	void DrawGage(double deg, int i);
public:
	inline CDrawPtnV(void){
		Max = 0.0;
		tp = NULL;
		gCol = clGray;
	};
	inline ~CDrawPtnV(){
	};
	void SetRect(TCanvas *pc, int x1, int y1, int x2, int y2);
	inline void GetBottomPosition(int &x, int &y){
		x = xl;
		y = yc;
	};
	inline void SetMaxDB(double m){
		Max = m;
	};
	void DrawAngle(int Add = 1);
	void DrawPtn(float *pt, int Add, TColor Col = clBlack);
};

///---------------------------------------------------------
///  �R���g���[���̃A���C���̊Ǘ��N���X
class CAlign
{
private:
	int		BTop, BLeft;
	int		BWidth, BHeight;
	int		OTop, OLeft;
	int		OWidth, OHeight;
	int		OFontHeight;

	TControl	*tp;
	TFont		*fp;
public:
	inline CAlign(void){
		tp = NULL;
		fp = NULL;
	};
	inline ~CAlign(){
	};
	void InitControl(TControl *p, TControl *pB, TFont *pF = NULL);
	void InitControl(TControl *p, RECT *rp, TFont *pF = NULL);
	void NewAlign(TControl *pB);
};

///---------------------------------------------------------
///  �R���g���[���̃A���C���̊Ǘ��N���X
class CAlignList
{
private:
	int		Max;
	int		Cnt;
	CAlign	**AlignList;
	void Alloc(void);
public:
	CAlignList(void);
	~CAlignList();
	void EntryControl(TControl *tp, TControl *pB, TFont *pF = NULL);
	void EntryControl(TControl *tp, RECT *rp, TFont *pF = NULL);
	void NewAlign(TControl *pB);
};

class CAlignGrid
{
private:
	int		BWidth;
	int		BHeight;
	int		BRowHeight;

	int		Max;
	int		*bp;
public:
	inline CAlignGrid(void){
		Max = 0;
		bp = NULL;
	};
	inline ~CAlignGrid(){
		if( bp != NULL ){
			delete bp;
		}
	};
	void InitGrid(TStringGrid *p);
	void NewAlign(TStringGrid *p);
};


enum CWTYPE {
	cwNULL,		// �s��
	cwVDP,		// ����DP
	cwVSQ,		// ������
	cwVDM,		// ������
	cwVTA,		// ������
	cwVITA,		// ������
	cwVPIE,		// ������
	cwVLP,		// �������[�v
	cwHDP,		// ����DP
	cwHSQ,		// ������
	cwHDM,		// ������
	cwHTA,		// ������
	cwHITA,		// ������
	cwHLP,		// �������[�v
	cwHANT,		// �����n
	cwVANT,		// �����n
	cwVSQ2,		// �����o��
	cwVTA2,		// �����o��
};
typedef struct {
	int		ref;
	WDEF	*wp;
	double	D;				// ���C���̋���
	double	XX;
	double	YY;
	double	ZZ;
	double	VXY;
	double	VYZ;
	int		LCF;
}WREF;
typedef struct {
	double	X, Y, Z;		// ���_�̍��W
	double	VXY;
	double	VYZ;
}LOOPS;

class CWGroup
{
private:
	int		bmax;		// ���C���z��̐�
	WDEF	*pW;		// ���C����`�z��̃|�C���^
	double	YL;
	double	YH;
	double	ZL;
	double	ZH;
	double	XL;
	double	XH;
	int		XwF;		// ���[�v�A���e�i�t���O
public:
	int		Type;		// �`��
	int		bcnt;		// ���C���̐�
	int		EnbR;		// �q�ύX�\�t���O
	int		EnbSeg;		// SEG�ύX�\�t���O
	WREF	*pB;		// ���C�����X�g�̔z��

	double	BX;				// ���S�ʒu�̍��W
	double	BY;
	double	BZ;
private:
	int AnaLoop(int N, double OX, double OY, double OZ, double X, double Y, double Z);
	void AnaType(void);
	void SetPieRound(double d);
public:
	CWGroup(void);
	inline ~CWGroup(){
		Delete();
	};
	void Clear(void);
	void Init(WDEF *p);
	void Delete(void);
	void Alloc(void);
	void AddWire(int Index);
	void AnaWire(void);
	inline double GetX(void){			// �w���|�W�V�����𓾂�
		return BX;
	};
	inline double GetHeight(void){		// �����𓾂�
		return (ZH != ZL) ? ZH - ZL : (XwF == 0) ? XH - XL : 0.0;
	};
	inline double GetWidth(void){		// �����𓾂�
		return (YH != YL) ? YH - YL : (XwF == 0) ? XH - XL : 0.0;
	};
	double GetRound(void);		// �S���𓾂�
	void SetRound(double d);	// �S����ݒ肷��
	inline double GetR(void){
		if( bcnt ){
			return pB->wp->R;
		}
		else {
			return 0.005;
		}
	}
	inline int GetSEG(void){
		if( bcnt ){
			return pB->wp->SEG;
		}
		else {
			return 0;
		}
	}
	void SetXWidth(double W);
	void SetWidth(double W);
	void SetHeight(double W);
	void SetRoundAll(double d);	// �S����ݒ肷��
	void SetXWidthAll(double W);
	void SetWidthAll(double W);
	void SetHeightAll(double W);
	void SetR(double r);
	void SetSeg(int s);
	inline int EnbXw(void){
		return XwF;
	};

	void SetXWidth(int all, double W);
	void SetWidth(int all, double W);
	void SetHeight(int all, double W);
	void SetRound(int all, double d);	// �S����ݒ肷��
};

#define	CWMAX	256
class CWGroupList
{
private:
	BYTE	Con[WMAX];
	int		Edit;
	double	OffX;
public:
	int		gmax;
	CWGroup	List[CWMAX];
	int		BaseW;			// ����C���ʒu
	double	Intval[CWMAX];

	ANTDEF	*ap;
	WDEF	wdef[WMAX];
	int		wmax;
private:
	int GetNewWire(void);
	int AddWire(double x1, double y1, double z1, double x2, double y2, double z2, double r, int seg);
	void Connect(int w, double X, double Y, double Z);
	void Sort(void);
public:
	inline CWGroupList(void){
		gmax = 0;
		wmax = 0;
		memset(Intval, 0, sizeof(Intval));
	};
	inline ~CWGroupList(){
	};
	void Delete(void);
	double GetXPosition(int n);
	int SetXPosition(int n, double d);

	void SetWire(ANTDEF *p);
	void Update(void);
	void CreateWire(int w, int type);
	void InsertItem(int w);
	void DeleteItem(int n);
	void DeleteWire(int n);
	void SetNewType(int n, int type);
	int GetEleNo(int w);
	CWGroup* GetCW(int w);
	double GetXAbs(int w);
};

void DrawWirePara(TPaintBox *tp, CWGroupList *lp, int w);

enum AVTYPE {
	avWIRE,
	avELE,
	avLOAD,
	avHEIGHT,
	avFREQ,
	avWIREP,
	avFEED,
	avSTACK,
};
#define	AVMAX	128		// �����ł���œK���o���A�u���̍ő吔
// �œK���o���A�u���̔z��\��
typedef struct {
	int		Type;		// �o���A�u���̌`��  0-ܲ�, 1-�����, 2-۰��, 3-�n�㍂
	int		With;			// �֘A�ԍ�(-1:�֘A�Ȃ�, 0�` �֘A�t���̔ԍ�)
	int		Pos;			// �ϐ��̈ʒu(���C���ԍ�,����Ĕԍ�,۰�ޔԍ���)
	int		SubPos;			// �ϐ��̉ӏ�
	USHORT	Min;
	USHORT	Max;
	int		Dummy1;
	int		Dummy2;

	double	DW;				// �ϕ�
	double	DMAX;			// �œK���ő吧���̒l
	double	DMIN;			// �œK���ŏ������̒l
	double	DIO;			// �œK���̏����Ԋu
	double	DI;				// �œK���̎��s�Ԋu
	double	DC;				// ���݂̒l
}AVAL;

#define BMAX	10
typedef struct {			// ���d�_�̒�`
	double	fq;
	CDEF	cdef[4];
}BDEF;
// �ڕW�̍\��
typedef struct {
	int		TF;				// �ڕW����^�Ȃ�
	double	TG;				// �f�̃g���[�h�I�t
	double	TFB;			// �e�a�̃g���[�h�I�t
	double	TJX;			// �i�w�̃g���[�h�I�t
	double	TSWR;			// �r�v�q�̃g���[�h�I�t
	double	TELV;			// �G���x�[�V����
	double	TM;				// �V���v���}�b�`���O
	double	TI;				// �d��

	double	CG;
	double	CFB;
	double	CRR;
	double	CJX;
	double	CSWR;
	double	CELV;
	double	CM;

	double	V;				// �]���l
	double	AM;				// �O��̕]���l
	double	VM;				// �ő�̕]���l
	double	AD[AVMAX];		// �ő厞�̊e�ϐ��̒l

	int		bmax;			// �o���h�̐�
	int		bweight;
	BDEF	bdef[BMAX];		// �o���h�̒�`

	double	MaxGain;		// �ڕW�ő�Q�C��
	double	MaxFB;			// �ڕW�ő�e�a��
	double	MinJX;
	double	MinSWR;
	int		Match;
	double	TergR;
	double	TergJX;

	int		IType;			// 0-�d���ő�, 1-�d���ŏ�
	char	IPLUS[8+1];		// �d���ʒu
	double	CurCur;			// ���݂̓d���l
}ATRG;
#define	MVMAX	128			// �L�^���X�g�̐�
typedef struct {			// �L�����X�g�̍\��
	double	AD[AVMAX];			// �p�����[�^�̏��
	double	V;					// �]���l

	float	CG;					// �\���p
	float	CFB;
	float	CRR;
	float	CJX;
	float	CSWR;
	float	CELV;
	short	PtnH[180];			// 2�x����\�̐����p�^�[��
	short	PtnV[91];			// 2�x����\�̐����p�^�[��
}MVAL;
// �œK�����s�N���X
class CACal
{
public:
	AVAL	aval[AVMAX];	// �ϐ��̔z��
	int		amax;			// �o�^�����ϐ��̐�
	CWGroupList	WList;		// �G�������g�f�[�^
	ATRG	atrg;			// �ڕW�̃f�[�^
	int		PitchUnit;		// �s�b�`�̒P��
	int		DegUnit;		// �p�^�[���̕���\

	double	BV[BMAX];
	double	BVM[BMAX];

	ENVDEF	*EP;
	ANTDEF	*AP;
	CRes	maxres;			// �ő厞�̌��ʂ̃f�[�^
	char	InfoTTL[192];
	char	Info[192];
private:
	MVAL	mval[MVMAX];	// �L�����X�g�̔z��
	int		mvwp;			// ���̏������݈ʒu
	int		mvmax;			// ���݂̃f�[�^��
private:
	void WriteMV(void);
	int IsMV(double &max);

	void AdjWireChen(int w, WDEF *op, WDEF *np);
	void SetParaWire(AVAL *ap, double d);
	void SetParaEle(AVAL *ap, double d);
	void SetParaLoad(AVAL *ap, double d);
	void SetParaHeight(AVAL *ap);
	void SetParaWireP(AVAL *ap, double d);
	void SetParaFeed(AVAL *ap, double d);
	void SetParaStack(AVAL *ap, double d);
	double GetParaWire(AVAL *ap);
	double GetParaEle(AVAL *ap);
	double GetParaLoad(AVAL *ap);
	double GetParaWireP(AVAL *ap);
	double GetParaFeed(AVAL *ap);
	double GetParaStack(AVAL *ap);
	int SetMinMax(AVAL *ap, double &d);
	void SetPara(int n);
	int Exec(void);
//	int SetMax(RESL *rp);
	int IsSameMax(void);
	int _GetLastChen(int c, int n);
	void SetNowCur(RESL *rp);
	double CalcV(RESL *rp, CRes *cp);
public:
	CACal(void);
	inline ~CACal(){
	};

	inline int GetChenNo(int n){
		if( n >= 0 ){
			return n & 0x0000ffff;
		}
		else {
			return -n-2;
		}
	};
	int GetLastChen(int c, int n);
	int WriteToFp(FILE *fp);		// �Z�b�g�A�b�v�̃Z�[�u
	int ReadFromFp(FILE *fp);		// �Z�b�g�A�b�v�̃��[�h
	inline int GetMV(void){
		return mvmax;
	};
	void ReadMV(MVAL *wp, int n);

	void Init(ANTDEF *ap, ENVDEF *ep);
	int InitPara(void);
	void SetPara(int n, double d);
	void SetBand(ANTDEF *ap, int n);
	void SetTradeOff(int gain, int fb, int jx, int swr, int elv, int mch, int cur);
	int Execute(void);
	double GetNowValue(int n);
	double GetNowValue(int n, double sc);
	void AdjSetup(int n);
	int Check(void);
	void SetTradeStr(LPSTR t);
	void DispStat(TMemo *tp);
};

///-------------------------------------------------------
/// �N���b�s���O�N���X
class CClip {
private:
	int		Xl;
	int		Yt;
	int		Xr;
	int		Yb;
	inline double ClipSubV(double bx, double by, double ex, double ey, double XX){
		if( bx != ex ){
			return ey + (XX-ex)*(by-ey)/(bx-ex);
		}
		else {
			return ey;
		}
	};
	inline double ClipSubH(double bx, double by, double ex, double ey, double YY){
		if( ey != by ){
			return bx + (YY-by)*(ex-bx)/(ey-by);
		}
		else {
			return bx;
		}
	};
public:
	inline CClip(){
	};
	inline void SetClip(int x1, int y1, int x2, int y2){
		Xl = x1;
		Yt = y1;
		Xr = x2;
		Yb = y2;
	};
	int Clip(int &x1, int &y1, int &x2, int &y2);
	inline int ClipLong(long &x1, long &y1, long &x2, long &y2){
		int	xx1, xx2, yy1, yy2;
		xx1 = x1; yy1 = y1; xx2 = x2; yy2 = y2;
		int r = Clip(xx1, yy1, xx2, yy2);
		x1 = xx1; y1 = yy1; x2 = xx2; y2 = yy2;
		return r;
	}
	inline void Line(TCanvas *tp, int X1, int Y1, int X2, int Y2){
		if( Clip(X1, Y1, X2, Y2) == TRUE ){
			tp->MoveTo(X1, Y1);
			tp->LineTo(X2, Y2);
		}
	}
};

class CGraph
{
private:
	int		pcnt;
	int		flag[BWMAX+BWSMAX*BWSDIMMAX];
	double	pos[BWMAX+BWSMAX*BWSDIMMAX];
	double	data[BWMAX+BWSMAX*BWSDIMMAX];
    CClip	clip;
public:
	int	xl, xr, yt, yb;
	int	xw, yw;
	int	DotLen;
	double	xdl, xdh, xdw;
	double	ydl, ydh, ydw;
	double	rydl, rydh, rydw;
	double	YLIMMAX;
	TColor	gCol;
	TCanvas	*cp;
public:
	CGraph(void);
	inline ~CGraph(){
	};
	void Init(TPaintBox *pp);
	void Init(TCanvas *p, int x1, int y1, int x2, int y2);
	void ClearView(TPaintBox *pp);
	void DrawAngle(void);
	void Clear(void);
	void AddPoint(double x, double y, int fg);
	void AutoRenge(double lim);
    inline void SetYLimit(double lim){
		YLIMMAX = lim;
    };
	void AdjRengeZero(void);
	void DrawTitle(int sw, LPCSTR p, TColor col);
	void DrawGage(int sw, TColor col);
	void DrawXGage(void);
	void Plot(TColor col, TPenStyle style = psSolid);
	void DrawConst(double l, double c, double q, double w, double f);
	void DrawInfo(LPCSTR p);
	void DrawInfoL(int n, LPCSTR fmt, ...);
};


///-------------------------------------------------------
/// CRecentMenu�N���X
#define	RECMENUMAX	10	// �����ł���ő�̐�
class CRecentMenu
{
private:
public:
	int		InsPos;		// ���j���[�}���ʒu�̔ԍ�
	int		Max;		// �������鐔
	AnsiString	Caption[RECMENUMAX];
	TMenuItem	*pMenu;
	TMenuItem	*Items[RECMENUMAX+1];

public:
	CRecentMenu();
	void Init(int pos, TMenuItem *pmenu, int max);
	void Init(TMenuItem *pi, TMenuItem *pmenu, int max);
	int GetCount(void);
	LPCSTR GetItemText(int n);
	void SetItemText(int n, LPCSTR p);
	int IsAdd(LPCSTR pNew);
	void Add(LPCSTR pNew);
	void ExtFilter(LPCSTR pExt);
	void Clear(void);
	void Insert(TObject *op, Classes::TNotifyEvent pEvent);
	void Delete(void);
	void Delete(LPCSTR pName);
	int FindItem(TMenuItem *mp);
	LPCSTR FindItemText(TMenuItem *mp);
};

class CWebRef
{
private:
	AnsiString	HTML;
public:
	CWebRef();
	inline bool IsHTML(void){
		return !HTML.IsEmpty();
	};
	void ShowHTML(LPCSTR url);
};

class CWaitCursor
{
private:
	TCursor sv;
public:
	CWaitCursor();
	~CWaitCursor();
	void Delete(void);
	void Wait(void);
};

#endif

