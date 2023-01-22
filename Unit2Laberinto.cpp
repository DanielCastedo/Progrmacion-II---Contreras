//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------void TForm2::Cargar(String nom)
void __fastcall TForm2::cargar1Click(TObject *Sender)
{
  if (OpenTextFileDialog1->Execute()) {//si eligio un archivo
	   Cargar(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	x=y=0;
}
void TForm2::Cargar(String nom)
{ byte i,j; char img;
  ifstream pf(nom.c_str());
  if (!pf.fail()) {//si logró abrir el archivo
	 i=0; j=0;
	 while (!pf.eof()){
		img=pf.get();
		Laberinto[j][i]=img;
		switch (img) {
		  case 'M': ImageList1->Draw(Canvas,j*40,i*40,0);break;
		  case '@': ImageList1->Draw(Canvas,j*40,i*40,1);x=j;y=i;break;
		  case '#': ImageList1->Draw(Canvas,j*40,i*40,2);break;
		  case 'c': ImageList1->Draw(Canvas,j*40,i*40,3);break;
		  case 10 : n=j; i++; j=255;break;
		}
		j++;
	 }
	 m=i; Height=(m+2)*40+22;
	 Width=n*40+17;
	 pf.close();
  }
}
//---------------------------------------------------------------------------
bool TForm2::BackTrack(char Lab[][Max],int x,int y)
{ bool haySalida=false; byte nc; char d;
  char caminos[4]; nc=0;
  if ((Lab[x+1][y]==' ')||(Lab[x+1][y]=='#'))//si hay camino a la derecha
	 caminos[nc++]='6';
  if ((Lab[x-1][y]==' ')||(Lab[x-1][y]=='#'))//si hay camino a la izquierda
	 caminos[nc++]='4';
  if ((Lab[x][y-1]==' ')||(Lab[x][y-1]=='#'))//si hay camino arriba
	 caminos[nc++]='8';
  if ((Lab[x][y+1]==' ')||(Lab[x][y+1]=='#'))//si hay camino abajo
	 caminos[nc++]='2';
  while ((nc>0)&&(!haySalida)) {
	 nc--; d=caminos[nc];
	 Lab[x][y]='+'; //camino pisado
	 ImageList1->Draw(Canvas,x*40,y*40,1);//borra al hamster
	 switch(d){
	   case '4':x--;break;
	   case '6':x++;break;
	   case '8':y--;break;
	   case '2':y++;break;
	 }
	 ImageList1->Draw(Canvas,x*40,y*40,2);//dibuja al hamster
	 Sleep(100);
	 if (Lab[x][y]=='#')
	   haySalida=TRUE;
	 else {
		haySalida=BackTrack(Lab,x,y);
		if (!haySalida){//back track
		  ImageList1->Draw(Canvas,x*40,y*40,1);//borra al hamster
		  switch(d){
			case '4':x++;break;
			case '6':x--;break;
			case '8':y++;break;
			case '2':y--;break;
		  }
		  ImageList1->Draw(Canvas,x*40,y*40,2);//dibuja al hamster
		  Sleep(100);
		}
	 }
  }
  return haySalida;
}
//---------------------------------------------------------------------------
/*void __fastcall TForm2::probar1Click(TObject *Sender)
{
 if ((x>0)&&(y>0)) {
	  if (BackTrack(Laberinto,x,y))
		 Caption="HANSTER encontro la salida";
	  else
		Caption="Laberinto sin salida";
 }
}  */
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TForm2::Verificar(String nom)
{ byte i,j; char img;
	bool b=true;
  ifstream pf(nom.c_str());
  if (!pf.fail()) {//si logró abrir el archivo
	 i=0; j=0;
	 while (!pf.eof()){
		img=pf.get();
		Laberinto[j][i]=img;
		switch (img) {
		  case 'M': b=true;break;
		  case '@': b=true;break;
		  case '#': b=true;break;
		  case 'c': b=true;break;
		  case 10 : n=j; i++; j=255;break;

		}
		j++;
	 }
	 m=i; Height=(m+2)*40+22;
	 Width=n*40+17;
	 pf.close();
  }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::verificar21Click(TObject *Sender)
{
 if (OpenTextFileDialog1->Execute()) {//si eligio un archivo
		Verificar(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------

