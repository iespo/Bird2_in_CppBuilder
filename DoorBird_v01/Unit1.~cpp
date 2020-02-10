//---------------------------------------------------------------------------

/* Wladimir Popov: 28.01.2020 */

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

#include<iostream>	//standart libraries
#include<string>	//fuer klass string
#include<fstream>	//fuer Files (read/write)
#include <sstream>	//fuer ostringstream ost;
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

        AnsiString filepath;

	AnsiString fPathKd = "Namensliste.txt";		//Kundenliste ohne Parameter fuer read
	AnsiString fPath1 = "Kunden1.txt";			//fuer die Fuellung die Parameter
	AnsiString fPath2 = "Kunden2.txt";			//Add neuen Kunden nach die Kopierung von "Kunden1.txt"
	AnsiString fPath3 = "Kunden3.txt";			//streichen die Kunden
	AnsiString fPath4 = "Kunden4.txt";			//Aendern die Parameter

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   int dg;
   dg = 3;//fooDialog();

   Form2->Show();

   //fileCopie(ifstream &rdKu, ofstream &wrKu);


}
//---------------------------------------------------------------------------

string intToStrg(int &par)
{
	stringstream strpar;	//fuer Int to Str

	strpar.str("");				//cleaning string von alten parameter
	strpar.clear();
	strpar << par;				//param as string
								//line += strpar.str();			//<- param as string
								//line.append(strpar.str());	//<- param as string
	return strpar.str();
}

// 2 ---------- File COPIE ----------------------
void fileCopie(ifstream &rdKu, ofstream &wrKu)
{
	string line = "";				//ein Satz

	char ch;
	while (rdKu.get(ch))			//get() - gibt true/false
	{
		cout << ch;					//symbolsweise reading
		wrKu << ch;					//symbolsweise reading
	}

	/*	while (!rdKu.eof())				 //read customer list
		{
			getline(rdKu, line);			//listet eine Zeile
			wrKu << line << endl;			//write one line to file
			cout << line << endl;			// <--!Ein Enter am ende ist zufiel
		}//end while  */
}

// 100 ---------- Param FILLING ----------------------
void paramAutoFill(ifstream &rdKu, ofstream &wrKu)
{
	int param;
	//stringstream strpar;
	string line = "";				//ein Satz

	//while (!rdKu.eof())				//read customer list	//(s!='\n'&&!f.eof())
	//{
	while (getline(rdKu, line))			//listet eine Zeile
	{
		line.append(" : \t");			//Trennzeichen ":"

		param = 1 + rand() % 98;		//1...99 - Zufaelige param

		line += intToStrg(param);		//param as string

		cout << line << endl;

		if (!rdKu.eof()) {
			wrKu << line << endl;		//write one line to file <- !Ein Enter am ende ist zufiel
		}
		else {
			wrKu << line;				//write one line to file <- !Ein Enter am ende ist zufiel
		}
	}//end while

}

//---------- OPENFILE ----------------------
void openFile(AnsiString &fPathRd, AnsiString &fPathWr, int &dialog, string stofind = "")
{
	ifstream rdKu;				//for read from file

        //this->rdKu.

	rdKu.open(fPathRd.c_str() );
	if (rdKu.is_open())
	{
		//cout << "File open to read: ..\\" << fPathRd << endl;

		ofstream wrKu;			//for write to file
		wrKu.open(fPathWr.c_str());		// , ofstream::app);
		if (wrKu.is_open())
		{
			cout << "File open to write: ..\\" << fPathWr.c_str() << endl;

			if (dialog == 2)				//File Copie
			{
				fileCopie(rdKu, wrKu);		//copying customer list
			}
			else if (dialog == 3)			//Add neuen Kunden
			{
				//hat eigene Methode
			}
			else if (dialog == 4)			//streichen die Kunden
			{
				//fileLoescheKunde(rdKu, wrKu, stofind);
			}
			else if (dialog == 5)			//Parameter Editor
			{
				//paramEdit(rdKu, wrKu, stofind);	//Parameter Editor
			}
			else if (dialog == 100)
			{
				paramAutoFill(rdKu, wrKu);
			}
			else {}

		}//end if (wrKu.is_open())
		else { cout << "File cannot open to write!" << endl; }

		wrKu.close();
		cout << "File is closed for writing" << endl;

	}//end if(rdKu.is_open())
	else { cout << "File cannot open to read!" << endl; }	// !Fьllen Sie zuerst die Parameter mit dem Code 100 aus

	rdKu.close();
	cout << "File is closed for reading" << endl;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::sb_TraceSensO2_AClick(TObject *Sender)
{
   filepath = GetCurrentDir(); //

   OpenDialog1->InitialDir = ".\\Docs\\";                       //Initialisiert path
   OpenDialog1->Filter = "DoorBird files (*.txt)|*.txt";        //Erstellt Filter

   if(OpenDialog1->Execute())
   {
      filepath = OpenDialog1->FileName;
      ed_PfadTraceSensor_A->Text = filepath;
      fPathKd = filepath;

      Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
   }

                         // X,Y
   StringGridHistory->Cells[0][0] = 0.00;
   StringGridHistory->Cells[1][0] = 10;
   StringGridHistory->Cells[0][1] = 1;
   StringGridHistory->Cells[1][1] = 11; //history_asumADC_A[r][c]; //ListBox1->Items->Strings[r];//s;
   //StringGridHistory->Cells[c][r+1] = history_asumADC_A[r][c]; //ListBox1->Items->Strings[r];//s;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::sb_TraceSensO2_BClick(TObject *Sender)
{
   filepath = GetCurrentDir(); //

   OpenDialog1->InitialDir = ".\\Docs\\";                       //Initialisiert path
   OpenDialog1->Filter = "DoorBird files (*.txt)|*.txt";        //Erstellt Filter

   if(OpenDialog1->Execute())
   {
      filepath = OpenDialog1->FileName;
      ed_PfadTraceSensor_B->Text = filepath;
      fPath1 = filepath;

      Memo2->Lines->LoadFromFile(OpenDialog1->FileName);
   }

   //openFile(fPathKd, fPath1, 3, "a");

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::sbt_rdSaveAClick(TObject *Sender)
{
   //int dg;
   //dg = 3;//fooDialog();
   //AnsiString pathR =  fPathKd;
   //AnsiString pathW =  fPath1;

   filepath = GetCurrentDir(); //


   SaveDialog1->InitialDir = ".\\Docs\\";                       //Initialisiert path
   SaveDialog1->FileName = fPathKd;
   SaveDialog1->Filter = "DoorBird files (*.txt)|*.txt";        //Erstellt Filter

   if(SaveDialog1->Execute())
   {
      filepath = SaveDialog1->FileName;
      edO2_A->Text = filepath;
      //fPathKd = filepath;
      Memo1->Lines->SaveToFile(SaveDialog1->FileName);
      StatusBar1->Panels->Items[0]->Text=SaveDialog1->FileName;
      //Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::sbt_ReadTraceAClick(TObject *Sender)    //paramAutoFill
{
   char s, fs, stroka[255];
   string line = "";
   string word = "";
   int lcnt = 0;
   int param;


   ifstream frdKu; //(fPathKd.c_str);				//for read from file
   frdKu.open(fPathKd.c_str());

   if(frdKu.is_open())
   {
      while(!frdKu.eof())
      {
         param = 1 + rand() % 98;		//1...99 - Zufaelige param
         lcnt++;
         StringGridHistory->RowCount = lcnt+1;
         word = "";
         frdKu >> word;
         StringGridHistory->Cells[0][lcnt] = word.c_str();
         frdKu >> word;
         StringGridHistory->Cells[1][lcnt] = word.c_str();
         StringGridHistory->Cells[2][lcnt] = " : ";
         StringGridHistory->Cells[3][lcnt] = param;

         Label1->Caption = lcnt;
      }
   }
   else
   {
      Label1->Caption = "File cannot open!";
   }
   frdKu.close();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::sbt_ReadTraceBClick(TObject *Sender)
{
   //sbt_rdSaveB->Click();
   //Memo2->Lines->SaveToFile(fPath1);  //Ohne Save Dialog

   filepath = GetCurrentDir(); //


   SaveDialog1->InitialDir = ".\\Docs\\";                       //Initialisiert path
   SaveDialog1->FileName = fPath2;
   SaveDialog1->Filter = "DoorBird files (*.txt)|*.txt";        //Erstellt Filter

   if(SaveDialog1->Execute())
   {
      filepath = SaveDialog1->FileName;
      edO2_B->Text = filepath;
      //fPath1 = filepath;
      Memo2->Lines->SaveToFile(SaveDialog1->FileName);
      StatusBar1->Panels->Items[0]->Text=SaveDialog1->FileName;
      //Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sbt_rdSaveBClick(TObject *Sender)
{ 

   filepath = GetCurrentDir(); //


   SaveDialog1->InitialDir = ".\\Docs\\";                       //Initialisiert path
   SaveDialog1->FileName = fPath1;
   SaveDialog1->Filter = "DoorBird files (*.txt)|*.txt";        //Erstellt Filter

   if(SaveDialog1->Execute())
   {
      filepath = SaveDialog1->FileName;
      edO2_B->Text = filepath;
      //fPath1 = filepath;
      Memo2->Lines->SaveToFile(SaveDialog1->FileName);
      StatusBar1->Panels->Items[0]->Text=SaveDialog1->FileName;
      //Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
   }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::sbt_InsertClick(TObject *Sender)
{
     const int row_count =  StringGridHistory->RowCount;

     StringGridHistory->RowCount = row_count +1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::sbt_MoveClick(TObject *Sender)
{
         int AfterIndex = StringGridHistory->Row;
         int row_count = StringGridHistory-> RowCount;

         for (int row = row_count; row > AfterIndex + 1; --row)
                 StringGridHistory->Rows[row] =  StringGridHistory->Rows[row - 1];

         StringGridHistory->Rows[AfterIndex + 1]->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btSaveCalInsertClick(TObject *Sender)
{
   AnsiString str = "";
   Memo2->Lines->Clear();

   for (int i=1; i<StringGridHistory->RowCount; i++)
   {
        str =  StringGridHistory->Cells[0][i] + " \t";
        str += StringGridHistory->Cells[1][i] + " : \t";
        str += StringGridHistory->Cells[3][i]; // + "\n";
        Memo2->Lines->Add(str);
   }



/* //VAriant ok, aber mit Tab-s
   for (int i=1; i<StringGridHistory->RowCount; i++)
   {
        str = StringGridHistory->Cells[0][i];
        for (int j=1; j<StringGridHistory->ColCount; j++)
        {
            str += " \t" + StringGridHistory->Cells[j][i];
        }
        str += "\n";
        Memo2->Lines->Add(str);
   }
*/

}
//---------------------------------------------------------------------------

void __fastcall TForm1::sbt_DelClick(TObject *Sender)
{

   int drow = -1;
   int row_count = StringGridHistory->RowCount;


   drow = StringGridHistory->Row;                       //welche selekted
   //StringGridHistory->Selection.TopLeft.X;            //welche selekted
   //StringGridHistory->Selection.TopLeft.Y;            //welche selekted


   for (int i=drow; i<row_count-1; i++)
   {
      StringGridHistory -> Rows[i] = StringGridHistory -> Rows[i + 1];
   }

   StringGridHistory -> RowCount = row_count-1;

   

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGridHistorySelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
   ed_FirstName->Text = StringGridHistory->Cells[0][ARow];
   ed_Name->Text = StringGridHistory->Cells[1][ARow];
   ed_Param->Text = StringGridHistory->Cells[3][ARow];
}
//---------------------------------------------------------------------------


/*    //Bsp: Insert
       void __fastcall InsertRow( TStringGrid* StringGrid, int AfterIndex)
       {
         SendMessage(StringGrid->Handle,  WM_SETREDRAW, false, 0);
       try {
         const int row_count =  StringGrid->RowCount;

           // (1) добавить новую строку в конец грида. 
          StringGrid->RowCount = row_count +1;

          // (2) сдвинуть содержимое каждой строки.
            for (int row = row_count;row > AfterIndex + 1; --row)
            {
             StringGrid->Rows[row] =  StringGrid->Rows[row - 1];
            }
          StringGrid->Rows[ AfterIndex + 1]->Clear();
       }
         catch (...) {
          SendMessage(StringGrid->Handle,  WM_SETREDRAW, true, 0);
         }
       SendMessage(StringGrid->Handle, WM_SETREDRAW, true, 0);
       // update (repaint) the shifted rows
       RECT R =    StringGrid->CellRect(0, AfterIndex);
       InflateRect(&R, StringGrid->Width, StringGrid->Height);
         InvalidateRect(StringGrid->Handle, &R, false);
       }
*/
void __fastcall TForm1::sbt_EditSaveClick(TObject *Sender)
{
         int drow = StringGridHistory->Row;

         StringGridHistory->Cells[0][drow] = ed_FirstName->Text;
         StringGridHistory->Cells[1][drow] = ed_Name->Text;
         StringGridHistory->Cells[3][drow] = ed_Param->Text;

         //StringGridHistory->Rows[drow + 1]->Clear();
}
//---------------------------------------------------------------------------

