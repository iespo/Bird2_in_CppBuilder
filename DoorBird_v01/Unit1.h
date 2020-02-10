//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#include<iostream>	//standart libraries
#include<string>	//fuer klass string
#include<fstream>	//fuer Files (read/write)
#include <sstream>	//fuer ostringstream ost;
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
        TButton *Button1;
        TSpeedButton *sbt_ReadTraceA;
        TSpeedButton *sbt_ReadTraceB;
        TGroupBox *GroupBox33;
        TImage *Image14;
        TSpeedButton *sb_TraceSensO2_A;
        TSpeedButton *sbt_rdSaveA;
        TSpeedButton *sb_TraceSensO2_B;
        TSpeedButton *sbt_rdSaveB;
        TPanel *Panel20;
        TEdit *ed_PfadTraceSensor_A;
        TEdit *edO2_A;
        TEdit *ed_PfadTraceSensor_B;
        TEdit *edO2_B;
        TStringGrid *StringGridHistory;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox1;
        TMemo *Memo1;
        TMemo *Memo2;
        TSpeedButton *sbt_Insert;
        TSpeedButton *sbt_Move;
        TSpeedButton *sbt_Del;
        TGroupBox *GroupBox3;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *ed_FirstName;
        TEdit *ed_Name;
        TEdit *ed_Param;
        TStatusBar *StatusBar1;
        TButton *btSaveCalInsert;
        TSpeedButton *sbt_EditSave;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label1;
        TLabel *Label9;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall sb_TraceSensO2_AClick(TObject *Sender);
        void __fastcall sb_TraceSensO2_BClick(TObject *Sender);
        void __fastcall sbt_rdSaveAClick(TObject *Sender);
        void __fastcall sbt_ReadTraceAClick(TObject *Sender);
        void __fastcall sbt_ReadTraceBClick(TObject *Sender);
        void __fastcall sbt_rdSaveBClick(TObject *Sender);
        void __fastcall sbt_InsertClick(TObject *Sender);
        void __fastcall sbt_MoveClick(TObject *Sender);
        void __fastcall btSaveCalInsertClick(TObject *Sender);
        void __fastcall sbt_DelClick(TObject *Sender);
        void __fastcall StringGridHistorySelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect);
        void __fastcall sbt_EditSaveClick(TObject *Sender);
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
        __fastcall TForm1(TComponent* Owner);

        string intToStrg(int &par);

        // 2 ---------- File COPIE ----------------------
        void fileCopie(ifstream &rdKu, ofstream &wrKu);
        // 100 ---------- Param FILLING ----------------------
        void paramAutoFill(ifstream &rdKu, ofstream &wrKu);
        //---------- OPENFILE ----------------------
        void openFile(AnsiString &fPathRd, AnsiString &fPathWr, int &dialog, string stofind = "");

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
