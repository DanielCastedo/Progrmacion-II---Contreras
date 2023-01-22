//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <FStream.h>
#include <System.ImageList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
const Max=100;
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TImageList *ImageList1;
	TMenuItem *cargar1;
	TMenuItem *salir1;
	TMenuItem *verificar21;
	void __fastcall cargar1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall verificar21Click(TObject *Sender);
private:	// User declarations
char Laberinto[Max][Max];
byte m,n;
int x,y;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	fstream *pf;
	void Cargar(String);
    void Verificar(String);
	bool BackTrack(char lab[][Max],int x,int y);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
