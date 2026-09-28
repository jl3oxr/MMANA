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
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
USEFORM("ResCmp.cpp", ResCmpDlg);
USEFORM("RotWire.cpp", RotWireDlg);
USEFORM("StackDlg.cpp", StackDlgBox);
USEFORM("Print.cpp", PrintDlgBox);
USEFORM("MoveDlg.cpp", MoveDlgBox);
USEFORM("NearSet.cpp", NearSetDlg);
USEFORM("OptDlg.cpp", OptDlgBox);
USEFORM("TextEdit.cpp", TextEditDlg);
USEFORM("WireCad.cpp", WireCadDlg);
USEFORM("WireEdit.cpp", WireEditDlg);
USEFORM("WireScl.cpp", WireScaleDlg);
USEFORM("WcombDsp.cpp", WCombDspDlg);
USEFORM("ValRep.cpp", ValRepDlg);
USEFORM("VerDsp.cpp", VerDspDlg);
USEFORM("WComb.cpp", WCombDlg);
USEFORM("ACalRes.cpp", ACalResDlg);
USEFORM("BwDisp.cpp", BwDispDlg);
USEFORM("ACalMult.cpp", ACalMultDlg);
USEFORM("ACalBox.cpp", ACalDlg);
USEFORM("ACalEle.cpp", ACalEleBox);
USEFORM("ACalInfo.cpp", ACalInfoBox);
USEFORM("FarSet.cpp", FarSetDlg);
USEFORM("MediaDlg.cpp", MediaDlgBox);
USEFORM("FreqSet.cpp", FreqSetDlg);
USEFORM("GrpWire.cpp", GrpWireDlg);
USEFORM("Main.cpp", MainWnd);
USEFORM("PrgBar.cpp", ProgressForm);
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "MMANA";
		Application->CreateForm(__classid(TMainWnd), &MainWnd);
		Application->CreateForm(__classid(TProgressForm), &ProgressForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
