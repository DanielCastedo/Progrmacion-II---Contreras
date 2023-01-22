//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
#include <FStream>
//---------------------------------------------------------------------------
struct TFecha{
	byte dia;
	byte mes;
	Word año;
};
struct RegAlumno{
	char mark; //marca de borrador
	Word cod;
	char nom[21];//cadena de 20 caracteres
	char dir[21];  //cadena de 20 caracteres
	TFecha fecha;
};
struct RegIdxCod{
	Word cod;  //codigo del alumno
	Cardinal pos; //posicion de archivos de daots de alumnos
};

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TMainMenu *MainMenu1;
	TMenuItem *Indices1;
	TMenuItem *porcodigo1;
	TMenuItem *pornombre1;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TMenuItem *Ordenar1;
	TMenuItem *Porcodigo2;
	TMenuItem *Pornombre2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit5KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall porcodigo1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Porcodigo2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
   fstream *pf,*pIdx;
   AnsiString nomArch,nomIdxCod;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
