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
//---------------------------------------------------------------------------
/*  MOSTRAR SOLO LOS NUMEROS PARES
		Ej: 5245631 => 246

	Paso 0: x(numero, natural,grande)
			p(numero,natural,pequeno)

	Paso 1: VR n(Cantidad de digitos en X)

	Paso 2: Dn=[0,10]n[0,inf[
				Dn=[0,10]

	Paso 3: CASO BASE
			x%2==1 --> Si es par se le aumenta
				x = 0

	Paso 4: CASO GENERAL
		d = x%10 ->sacamos el ultimo digito
		if(d%2==0)
			Si el digito sacado es par colocarlo
			x = x*10+d
        Si es impar no hacer nada y eliminarlo para pasar al siguiente digito              */
void MostrarPares(Cardinal &x){
byte d;
	if(x<10){
		if(x%2==1){
			x = 0;
		}
	}
	else{
		d = x%10;
		x = x/10;
		MostrarPares(x);
		if(d%2==0){
			x = (x*10)+d;
		}
	}
}
void __fastcall TForm2::MostrarPares1Click(TObject *Sender)
{Cardinal x;
	x = StrToInt(Edit1->Text);
	MostrarPares(x);
	Edit2->Text = x;
// 	Ej: 5245631 => 246
}
//---------------------------------------------------------------------------
/*  MOSTRAR IMPARES
		Ej: 158430615 => 15315
	PASO 0: E: x(numero,natural,grande)
			S: Im(numero, natural,pequeno)

	PASO 1: VR= n(cantidad de elementos en X)

	PASO 2: Dn=[0,10]n[0,inf[
				Dn = [0,10]

	PASO 3: CASO BASE
		x%2==0
			x=0

	PASO 4: CASO GENERAL
		d = x%10
		x = x/10
		if(d%2==1) -> comprobar que sea impar
			x = x*10 + d
*/
void MostrarImp(Cardinal &x){
 byte d;
	if(x<10){
		if(x%2==0){
			x = 0;
		}
	}
	else{
		d = x%10;
		x = x/10;
		MostrarImp(x);
		if(d%2==1){
			x = (x*10)+ d;
		}
	}
}
void __fastcall TForm2::MostrarPares2Click(TObject *Sender)
{Cardinal x;
	x = StrToInt(Edit1->Text);
	MostrarImp(x);
	Edit2->Text = x;
// Ej: 158430615 => 15315
}
//---------------------------------------------------------------------------
/* FUNCION DE SUMA DE DIGITOS
	ej: 58471 => 25

	PASO 0: E: x(numero,grande,natural)
			S: s(numero,pequeno,natural)

	PASO 1: VR = n(cantidad de digitos)

	PASO 2: Dn=[0,10]n[0,inf[
				Dn=[0,10]

	PASO 3: CASO BASE
			cuando sea un digito (x<10)
				s = 0

	PASO 4: CASO GENERAL
			s = suma(x/10) -> la funcion nos devolvera el ultimo digo el cual sumaremos
			s = x%10 + s;  --> sumamos cada digito
*/
byte Suma(Cardinal x){
 byte s;
	if(x<10){
		s = x;
	}
	else{
		s = Suma(x/10);
		s = x%10 + s;
	}
	return s;
}
void __fastcall TForm2::Suma1Click(TObject *Sender)
{
	Edit2->Text = Suma(StrToInt(Edit1->Text));
	// ej: 58471 => 25
}
//---------------------------------------------------------------------------
/* Escribir una función que devuelva el menor de los dígitos de un número
		Ej. Menor(385267) ==> 2

	PASO 0: E: x(numero,natural,grande)
			S: men(numero,natural,pequeno)

	PASO 1: VR = n(cantidad en x)

	PASO 2: Dn = [1,10]n[1,inf[
				Dn = [1,10]

	PASO 3: CASO BASE
			x < 10
				men = x

	PASO 4: CASO GENERAL
			men = Menor(x/10)  -> se obtiene el numero menor(hipoteticamente)
			d = x%10 -> sacamos un digito para comparar
				(men > d)  -> comparamos
					men = d  -> cambiamos el valor de men si es verdadero
*/
byte Menor(Cardinal x){
  byte men,d;
	if(x<10){
		men = x;
	}
	else{
		men = Menor(x/10);
		d = x%10;
		if(men > d){
			men = d;
		}
	}
	return men;
}
void __fastcall TForm2::Suma2Click(TObject *Sender)
{
	Edit2->Text = Menor(StrToInt(Edit1->Text));
   // Ej. 385267 ==> 2
}
//---------------------------------------------------------------------------
/* Escribir una función que devuelva el mayor de los dígitos de un número
		Ej. Mayor(385267) ==> 8

	Paso 0: E: x(numero,natural,grande)
			S: m(numero,natural,pequeno)

	PASO 1: VR = n(cantidad en X)

	PASO 2: Dn = [0,10]n[0,inf[
				Dn = [0,10]

	PASO 3:     CASO BASE
			x < 10
				may = x

	PASO 4:    CASO GENERAL
		sacamos digito y un mayor y comparamos
			d > may -->(hacemos cambio de variable)
				may = d;
*/
byte Mayor(Cardinal x){
  byte may,d;
	if(x<10){
		may = x;
	}
	else{
		may = Mayor(x/10);
		d = x%10;
		if(d>may){
			may = d;
		}
	}
	return may;
}
void __fastcall TForm2::NumeroMayor1Click(TObject *Sender)
{
	Edit2->Text = Mayor(StrToInt(Edit1->Text));
//    Ej. Mayor(385267) ==> 8
}
//---------------------------------------------------------------------------
/* Escribir un proceso que lleve el mayor de los dígitos al final de un número.
			Ej.   x=382731 ===> x=327318

	PASO 0: E: x(numero,grande,natural)
			S: MovMay(numero,natural,grande)

	PASO 1: VR = n(cantidad en X)

	PASO 2: Dn = [0,10]n[0,inf[
				Dn = [0,10]

	PASO 3:     CASO BASE
			x < 10
			  may = x

	PASO 4:     CASO GENERAL
			sacamos un numero y un digito y comparamos
				may = x%10 -> mayor
				x/= 10;  -> menos ese digito mayor
				MovMay(x);  -> llamamos a la funcion para que haga el ciclo
				d = x%10  -> digito
				x /= 10;  ->menos el digito que se comparara
				(d > may) --> hacemos cambio de variable si es verdadero
					aux = may;
					may = d;
					d = aux;
				x = (x*10+d)*10)+ may;  --> lo anadimos al final
*/
void MovMayFin(Cardinal &x){
byte may,d,aux;
	if(x<10){
		may = x;
	}
	else{
		may = x%10;
		x = x/10;
		MovMayFin(x);
		d = x%10;
		x = x/10;
		if(d > may){
			aux = may;
			may = d;
			d = aux;
		}
		x = (x*10+d)*10 + may;
	}
}
void __fastcall TForm2::NumeroMayor2Click(TObject *Sender)
{
Cardinal z;
	z = StrToInt(Edit1->Text);
	MovMayFin(z);
	Edit2->Text = z;
//	Ej.   x=382731 ===> x=327318
}
//---------------------------------------------------------------------------
/* Escribir un proceso que lleve el menor de los dígitos al final de un número.
			Ej.   x=312738 ===> x=327381

	PASO 0: E: x(numero,grande,natural)
			S: MovMen(numero,grande,natural)

	PASO 1: VR = n(cantidad en X)

	PASO 2: Dn = [0,10]n[0,inf[
				Dn = [0,10]

	PASO 3: CASO BASE
			X < 10
				men = x;

	PASO 4: CASO GENERAL
		Sacamos dos digitos y comparamos cual es menor
			men = x%10 -> sacamos menor(hipotenticamene es menor)
			x = x/10  -> menos un digito
			MovMen(x) -> llamamos a la funcion para que haga el ciclo
			d = x%10  -> sacamos digito para comparar
			x = x/10  --> menos un digito
				(d < men) -> comparamos y si es verdad hacemos cambio de variable
					aux = men
					men = d
					d = aux;
			x = (x*10+d)*10+men    --> pegamos el menor al final

*/
void MovMenFin(Cardinal &x){
byte men,d,aux;
	if(x<10){
		men = x;
	}
	else{
		men = x%10;
		x = x/10;
		MovMenFin(x);
		d = x%10;
		x = x/10;
		if(d < men){
			aux = men;
			men = d;
			d = aux;
		}
		x = (x*10+d)*10 + men;
	}
}
void __fastcall TForm2::MoverMenorFinal1Click(TObject *Sender)
{Cardinal z;
	z = StrToInt(Edit1->Text);
	MovMenFin(z);
	Edit2->Text = z;
// Ej.   x=312738 ===> x=327381
}
//---------------------------------------------------------------------------
/*  Escribir una función que devuelva la cantidad de dígitos pares que
están inmediatamente antes de uno impar.
			Ej. CantDigPares(3827435) ==> 2

	PASO 0: E: x(numero,grande,natural)
			S: imp(numero,pequeno,natural)

	PASO 1: VR = n(cantidad en X)

	PASO 2: Dn = [1,10]n[1,inf[
				Dn = [1,10]

	PASO 3: CASO BASE
		x < 10
			s = 0  --> s se vuelve cero

	PASO 4: CASO GENERAL
		s = CantDeParAnteImp(x/10) ->llamamos a la funcion obteniendo los digitos
		if(x%2==1)  -> verificamos que el numero sea impar
			d = x/10;  -> quitamos el numero que verificamos como impar
			if(d%2==0) -> verficamos el sgt numero si es que es par
				s++    -> sumamos 1 si cumple las condiciones
*/
byte CantDeParAnteImp(Cardinal x){
 byte d,s;
	if(x<10){
		s = 0;
	}
	else{
		s = CantDeParAnteImp(x/10);
		if(x%2==1){
			d = x/10;
			if(d%2==0){
				s++;
			}
		}
	}
	return s;
}
void __fastcall TForm2::MoverMenorFinal2Click(TObject *Sender)
{
	Edit2->Text = CantDeParAnteImp(StrToInt(Edit1->Text));
  // Ej. 3827435 ==> 2
}
//---------------------------------------------------------------------------
/* Procedimiento que haga Rotar el primer digito
		Ej: 615248 => 152486 => 524861 => 248615

	PASO 0: E: x(numero,grande,natural)
			S: r(numero,grande,natural)

	PASO 1: VR = n(cantidad en x)

	PASO 2: Dn = [1,10]n[1,inf[
				Dn = [1,10]

	PASO 3: 	CASO BASE
		x < 10
			r = x;

	PASO 4:     CASO GENERAL
		d = x%10 -->sacamos el ultimo digito
		x = x/10 -> quitamos el ultimo digito
		RotarDig(x) -> llamamos a la funcion
		r = x%10 -> sacamos el primer digito
		x = x/10 -> quitamos el primer digito
		x = (x*10+d)*10+r; -> anadimos el primer digito al final y recoremos los
								otros digitos
*/
void RotarDig(Cardinal &x){
 byte r,d;
	if(x<10){
		r = x;
	}
	else{
		d = x%10;
		x = x/10;
		RotarDig(x);
		r = x%10;
		x = x/10;
		x = (x*10+d)*10 + r;
	}
}
void __fastcall TForm2::RotarPrimerDigito1Click(TObject *Sender)
{Cardinal z;
	z = StrToInt(Edit1->Text);
	RotarDig(z);
	Edit1->Text = z;
//	Ej: 615248 => 152486 => 524861 => 248615
}
//---------------------------------------------------------------------------
 Byte SumaDeDigitos(String cad){
 char letra;
 byte sum,len;
	len = cad.Length();
	if(len>1){
		letra = cad[len];
		cad.Delete(len,1);
		sum = SumaDeDigitos(cad);
		if(isdigit(letra)>0){
			sum = sum + StrToInt(letra);
		}
	}
	else{
		if(isdigit(letra)>0){
			sum = StrToInt(cad);
		}
		else{
			sum = 0;
		}
	}
	return sum;
 }
void __fastcall TForm2::SumarsoloDigitos1Click(TObject *Sender)
{ String cad = Edit1->Text;
byte res = SumaDeDigitos(cad);
	Edit2->Text = res;
/*	Ej: Re12ne Chun34gar5a
		=> 15                            */
}
//---------------------------------------------------------------------------
void OrdenarAscendente(Cardinal &x){
byte d;
	if(x>10){
		MovMayFin(x);
		d = x%10;
		x = x/10;
		OrdenarAscendente(x);
		x = (x*10)+d;
	}
}
void __fastcall TForm2::OrdenarAscendente1Click(TObject *Sender)
{Cardinal z=StrToInt(Edit1->Text);
	OrdenarAscendente(z);
	Edit2->Text = z;
/* Ej:	29854793
		=> 23457899                                                  */
}
//---------------------------------------------------------------------------
void RepetirNum(Cardinal &x,Cardinal dig){
	if(x>1){
		x--;
		RepetirNum(x,dig);
		x = x*10+dig;
	}
	else{
		x = dig;
	}
}
String DigEnLit(Cardinal x){
 Cardinal d;
 String num;
	if(x>10){
		d = x%10;
		x = x/10;
		num = DigEnLit(x);
		RepetirNum(d,d);
		num = num + String(d);
	}
	else{
		RepetirNum(x,x);
		num = String(x);
	}
	return num;
}
void __fastcall TForm2::SumarsoloDigitos2Click(TObject *Sender)
{Cardinal x = StrToInt(Edit1->Text);
AnsiString resp	= DigEnLit(x);
	Edit2->Text = resp;
/*  Ej:  20147
		=> 22144447777777                                 */
}
//---------------------------------------------------------------------------
void Invertir(AnsiString &x)
{
	if(x!=""){
		char z=x[1];
		x.Delete(1,1);
		Invertir(x);
		x = x + z;
	}
}
void __fastcall TForm2::Invertir1Click(TObject *Sender)
{  	AnsiString a;
	a = Edit1->Text;
	Invertir(a);
	Edit2->Text=a;
/*	Ej:  Rene Chungara
		  => aragnuhC eneR						*/
}
//---------------------------------------------------------------------------
bool esnum(wchar_t z){
	return	(z>='0')&&(z<='9');
}
void EliminarPrimerNum(String &x){
	if(x!=""){
		wchar_t z = x[1];
		x.Delete(1,1);
		if(!esnum(z)){
			EliminarPrimerNum(x);
			x = String(z) +  x;
		}
		else{
			if((x!="")&&(esnum(x[1]))){
				EliminarPrimerNum(x);
			}
		}
	}
}
void __fastcall TForm2::Invertir2Click(TObject *Sender)
{String cad = Edit1->Text;
	EliminarPrimerNum(cad);
	Edit2->Text = cad;
/* Ej: Ren887e Ch32ungar98a
		=> Rene Ch32ungar98a				*/
}
//---------------------------------------------------------------------------
void EliminarNumCad(String &x){
	if(x!=""){
		char z = x[1];
		x.Delete(1,1);
		EliminarNumCad(x);
		if(!isdigit(z)){
			x = String(z) + x;
		}
	}
}
void __fastcall TForm2::EliminarNumeros1Click(TObject *Sender)
{   String cad = Edit1->Text;
	EliminarNumCad(cad);
	Edit2->Text = cad;
/*     Ej: Ren887e Ch32ungar98a
			=> Rene Chungara				*/
}
//---------------------------------------------------------------------------
bool EliminarVocales(char z){
AnsiString vocales = "aeiouAEIOUáéíóúÁÉÍÓÚ";
	return vocales.Pos(z)>0;
}
void EliminarVocCad(String &x){
	if(x!=""){
		char z = x[1];
		x.Delete(1,1);
		EliminarVocCad(x);
		if(!EliminarVocales(z)){
			x = String(z) + x;
		}
	}
}
void __fastcall TForm2::EliminarNumeros2Click(TObject *Sender)
{
String cad = Edit1->Text;
	EliminarVocCad(cad);
	Edit2->Text = cad;
/*  Ej: René Chung12ara
		=>Rn Chng12r				*/
}
//---------------------------------------------------------------------------
void Dimensionar(TStringGrid *v, byte n)
{   if(n==0){  //caso base
		v->ColCount=0;
	}
	else{    //caso general
		Dimensionar(v,n-1);
		v->Cells[n-1][0] = "";
		v->ColCount = n;
	}
}
void __fastcall TForm2::Dimensionar1Click(TObject *Sender)
{
	Dimensionar(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void CargarAleatorio(TStringGrid *v, byte n)
{   if(n==0){  //caso base
		v->ColCount=0;
	}
	else{    //caso general
		CargarAleatorio(v,n-1);
		v->Cells[n-1][0] = Random(15);
		v->ColCount = n;
	}
}
void __fastcall TForm2::Dimensionar2Click(TObject *Sender)
{
	CargarAleatorio(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
byte SumaVec(TStringGrid *v, byte n)
{ byte s;
	if(n==0) //primer caso base
		s = 0;
	else if(n==1)   //segundo caso base
			s = StrToInt(v->Cells[0][0]);


	else{   //caso general
		s = SumaVec(v,n-2);
		s = s + StrToInt(v->Cells[n-2][0])+ StrToInt(v->Cells[n-1][0]);
	}
	return s;
}
void __fastcall TForm2::Suma3Click(TObject *Sender)
{
	Edit2->Text=SumaVec(StringGrid1,StringGrid1->ColCount);
//  Ej:  v[7,4,6,3,1,5] => 26
}
//---------------------------------------------------------------------------
bool Buscar(TStringGrid *v,byte a,byte b, int x)
{bool e; byte n=b-a+1;
	if(n==0)  //Primer caso base
		e = false;
	else if(n==1)
		e = x==StrToInt(v->Cells[a][0]);
	else{   //Caso General
		byte c=(a+b)/2;
		if(x==StrToInt(v->Cells[a][0]))
			e = true;
		else if(x<StrToInt(v->Cells[c][0]))
			e = Buscar(v,a,c-1,x);
		else
			e = Buscar(v,c+1,b,x);
	}

 return e;
}
void __fastcall TForm2::Suma4Click(TObject *Sender)
{
	if(Buscar(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text))){
		Edit2->Text="Si esta";
	}
	else{
		Edit2->Text="No esta";
	}
}
//---------------------------------------------------------------------------
void eliminarPos(TStringGrid *v,byte &n,byte pos){
	if(n>pos){
		if((n-1)==pos){
			n = n-1;
		}
		else{
			byte e = v->Cells[n-1][0].ToInt();
			n= n - 1;
			eliminarPos(v,n,pos);
			v->Cells[n][0]= e;
			n = n + 1;
		}
	}
}
void eliminarCant(TStringGrid *v, byte &n, byte pos, byte cant){
	if(cant>0){
		eliminarPos(v,n,pos);
		eliminarCant(v,n,pos,cant-1);
	}
}
void __fastcall TForm2::EliminardesdePMelemsms1Click(TObject *Sender)
{
	byte n = StringGrid1->ColCount;
	byte pos = StrToInt(InputBox("Ingrese la posicion a eliminar"," "," "));
	byte cant = StrToInt(InputBox("Ingrese los datos a eliminar",""," "));
	eliminarCant(StringGrid1,n,pos,cant);
	StringGrid1->ColCount = n;
/*Ej:   v[8,3,1,5,4,9,7]   pos = 4 ; cant = 2
		=> v[8,3,1,5,7]                                   */
}
//---------------------------------------------------------------------------
bool VerificarOrdenado(TStringGrid *v,byte a,byte b, int x)
{bool e; byte n=b-a+1;
	if(n==0)  //Primer caso base
		e = false;
	else if(n==1)
		e = x==StrToInt(v->Cells[a][0]);
	else{   //Caso General
		byte c=(a+b)/2;
		if(x==StrToInt(v->Cells[a][0]))
			e = true;
		else if(x<StrToInt(v->Cells[c][0]))
			e = VerificarOrdenado(v,a,c-1,x);
		else
			e = VerificarOrdenado(v,c+1,b,x);
	}

 return e;
}
void __fastcall TForm2::EliminardesdePMelemsms2Click(TObject *Sender)
{
	if(VerificarOrdenado(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text))){
		Edit2->Text="Si esta";
	}
	else
		Edit2->Text="No esta";
/*  Ej:	v[4,2,5,1,7,9,5] => No esta
		v[1,2,4,5,5,7,9] =>Si esta                                       */
}
//---------------------------------------------------------------------------
void OrdenarVecAux(TStringGrid *v,byte n)
{
	if(n>1){  //caso general
		OrdenarVecAux(v,n-1);
		if(StrToInt(v->Cells[n-2][0])>v->Cells[n-1][0]){
			String x;
			x = v->Cells[n-2][0];
			v->Cells[n-2][0] = v->Cells[n-1][0];
			v->Cells[n-1][0] = x;
		}
	}
}
void OrdenarVec(TStringGrid *v,byte n)
{
	if(n>1){    //caso general
		OrdenarVecAux(v,n);
		OrdenarVec(v,n-1);
	}
}
void __fastcall TForm2::Ordenar1Click(TObject *Sender)
{
 	OrdenarVec(StringGrid1,StringGrid1->ColCount);
/* ej:	v[4,2,5,1,7,9,5]
			=> v[1,2,4,5,5,7,9]                           */
}
//---------------------------------------------------------------------------
 void NumAVector(TStringGrid *B,Cardinal n,byte a)
{
	if (n<100){
		 B->Cells [0][0] = n;
	}
	else{
		B->Cells [a-1][0] = n % 100;
		NumAVector(B,n/100,a-1);
	}
}
void __fastcall TForm2::Ordenar2Click(TObject *Sender)
{
	AnsiString n = StrToInt(Edit1->Text);
	StringGrid1->ColCount = (n.Length()+1)/2;
	NumAVector(StringGrid1,StrToInt(n),StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void VectorANum(TStringGrid *B,byte a)
{
String n,x;
	if (n<100){
		 n = B->Cells [0][0];
	}
	else{
		n = B->Cells [a-1][0];
		VectorANum(B,a-1);
		x = n;
		n = n + x;
	}
}
void __fastcall TForm2::VectoraNumero1Click(TObject *Sender)
{
	//Edit2->Text=VectorANum(StringGrid1,StringGrid1->ColCount);
	// Estaba en duda y no lo complete xd
}
//---------------------------------------------------------------------------
void inserOrdVec(TStringGrid *v, byte &c, Cardinal x){
	if(c==0){
		v->Cells[0][0] = x;
		c = 1;
	}
	else{
		if(x<=StrToInt(v->Cells[c-1][0])){
			v->Cells[c][0] = x;
			c++;
		}
		else{
			Cardinal aux = StrToInt(v->Cells[c-1][0]);
			c--;
			inserOrdVec(v,c,x);
			v->Cells[c][0] = aux;
			c++;
		}
	}
}
void __fastcall TForm2::VectoraNumero2Click(TObject *Sender)
{   byte c = StringGrid1->ColCount;
	Cardinal x = StrToInt(Edit1->Text);
	inserOrdVec(StringGrid1,c,x);
	StringGrid1->ColCount = c;
/*	Ej: v[8,6,5,4,2,1]      num = 3
		=> v[8,6,5,4,3,2,1]                            */
}
//---------------------------------------------------------------------------
 void InsertarVectorPos(TStringGrid *v,byte &n,byte pos,byte num){
	if(n>pos){
	Cardinal aux = StrToInt(v->Cells[n-1][0]);
		n--;
		InsertarVectorPos(v,n,pos,num);
		n++;
		v->Cells[n-1][0]=aux;
	}
	else{
		n++;
		v->Cells[n-1][0] = num;
	}
}
void __fastcall TForm2::InsertarendichaPossms1Click(TObject *Sender)
{
	byte num = StrToInt(InputBox("","Numero: ",""));
	byte pos = StrToInt(InputBox("","Posicion a insertar: ",""));
	byte n = StrToInt(StringGrid1->ColCount);
	InsertarVectorPos(StringGrid1,n,pos,num);
	StringGrid1->ColCount = n;
/*  Ej: v[3,5,2,1,8]   num = 4 ; pos = 2
		 => v[3,5,4,2,1,8]							*/
}
//---------------------------------------------------------------------------
byte SumaElemPares(TStringGrid *v, byte n){
byte s;
	if(n==0){
		s = StrToInt(v->Cells[0][0]);
	}
	else if(n>0){
		s = SumaElemPares(v,n-1);
		if(n%2==0){
			s = s + StrToInt(v->Cells[n][0]);
		}
	}
	return s;
}
void __fastcall TForm2::InsertarendichaPossms2Click(TObject *Sender)
{ Edit2->Text=SumaElemPares(StringGrid1,StringGrid1->ColCount);
//  Ej:  v[7,4,6,3,1,5] => 7+6+1 = 14
}
//---------------------------------------------------------------------------
void CargarColNor(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k){
 byte m = cb-ca+1;
	if(m>0){
		A->Cells[ca][fa]=k++;
		CargarColNor(A,fa,fb,ca+1,cb,k);
	}
}
void CargarFilNor(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k){
 byte m = fb-fa+1;
	if(m>0){
		CargarColNor(A,fa,fb,ca,cb,k);
		CargarFilNor(A,fa+1,fb,ca,cb,k);
	}
}
void __fastcall TForm2::CargarNormal1Click(TObject *Sender)
{	byte f = StrToInt(InputBox("","Dimencion Fila:",""));
	byte c = StrToInt(InputBox("","Dimencion Columna:",""));
	StringGrid1->RowCount = f;    //fila
	StringGrid1->ColCount = c;   //columna
	byte k=1;
	CargarFilNor(StringGrid1,0,f-1,0,c-1,k);
/*Ej:	|1 |2 |3 |4 |5 |
		|6 |7 |8 |9 |10|
		|11|12|13|14|15|
		|16|17|18|19|20|
		|21|22|23|24|25|                                 */

}
//---------------------------------------------------------------------------
void CargarColAba(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k,bool b){
 byte m = cb-ca+1;
	if(m>0){
		if(b){
			A->Cells[ca][fb]=k++;
			CargarColAba(A,fa,fb,ca+1,cb,k,b);
		}
		else{
			A->Cells[cb][fb]=k++;
			CargarColAba(A,fa,fb,ca,cb-1,k,b);
        }

	}
}
void CargarFilAba(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k,bool b){
 byte m = cb-ca+1;
	if(m>0){
		CargarColAba(A,fa,fb,ca,cb,k,b);
		CargarFilAba(A,fa+1,fb-1,ca,cb-1,k,!b);
	}
}
void __fastcall TForm2::CargarNormal2Click(TObject *Sender)
{ 	byte n = StrToInt(InputBox("","Dimencion:",""));
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	byte k=1;
	CargarFilAba(StringGrid1,0,n-1,0,n-1,k,true) ;
/*Ej:	   	|15|  |  |  |  |
			|14|13|  |  |  |
			|10|11|12|  |  |
			|9 |8 |7 |6 |  |
			|1 |2 |3 |4 |5 |                                 */

}
//---------------------------------------------------------------------------
 void CargarFilLden(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte k){
 byte m = cb-ca+1;
	if(m>0){
		A->Cells[ca][fa]=k;
		CargarFilLden(A,fa,fb,ca+1,cb,k);
	}
}
void CargarColLden(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte k){
 byte m = fb-fa+1;
	if(m>0){
		A->Cells[ca][fa]=k;
		CargarColLden(A,fa+1,fb,ca,cb,k);
	}
}
void CargarPrinL(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k){
 byte m = fb-fa+1;
	if(m>0){
		CargarFilLden(A,fa,fb,ca,cb,k);
		CargarColLden(A,fa,fb,ca,cb,k);
		k--;
		CargarPrinL(A,fa+1,fb,ca+1,cb,k);
	}
}
void __fastcall TForm2::Lhaciaafuera1Click(TObject *Sender)
{	byte n = StrToInt(InputBox("","Dimencion:",""));
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	byte k=n;
	CargarPrinL(StringGrid1,0,n-1,0,n-1,k);
/*Ej:   |5|5|5|5|5|
		|5|4|4|4|4|
		|5|4|3|3|3|
		|5|4|3|2|2|
		|5|4|3|2|1|                                 */
}
//---------------------------------------------------------------------------
void CargarFilDiaSeg(TStringGrid *A,byte fa,byte fb,int ca,byte cb,byte &k,byte &j){
	if(ca>=0){
		A->Cells[ca][fa]=k++;
		A->Cells[cb][fb]=j--;
		CargarFilDiaSeg(A,fa+1,fb-1,ca-1,cb+1,k,j);
	}
}
void CargarPrinDiaSeg(TStringGrid *A,byte fa,byte fb,byte ca,byte cb,byte &k,byte &j){
	if(ca<=fb){
		CargarFilDiaSeg(A,fa,fb,ca,cb,k,j);
		CargarPrinDiaSeg(A,fa,fb,ca+1,cb-1,k,j);
	}
}
void __fastcall TForm2::Lhaciaafuera2Click(TObject *Sender)
{
	byte n = StrToInt(InputBox("","Dimencion:",""));
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	byte k=1;
	byte j= n*n;
	CargarPrinDiaSeg(StringGrid1,0,n-1,0,n-1,k,j);
/*Ej: 	|1 |2 |4 |7 |11|
		|3 |5 |8 |12|16|
		|6 |9 |13|17|20|
		|10|14|18|21|23|
		|15|19|22|24|25| 									*/
}
//---------------------------------------------------------------------------
void CargarDeraIzqCbCol(TStringGrid *M,byte fa,byte fb,byte ca,byte cb,byte &k){
byte c = cb-ca+1;
	if(c>0){
		if(fa%2==0){
			c = cb;
			cb--;
		}
		else{
			c = ca;
			ca++;
		}
		M->Cells[c][fa]=k++;
		CargarDeraIzqCbCol(M,fa,fb,ca,cb,k);
	}
}
void CargarDeraIzqCbFil(TStringGrid *M,byte fa,byte fb,byte ca,byte cb,byte &k){
byte n = fb-fa+1;
	if(n>0){
		CargarDeraIzqCbCol(M,fa,fb,fb-fa,cb,k);
		CargarDeraIzqCbFil(M,fa+1,fb,ca,cb,k);
	}
}
void __fastcall TForm2::ArribaDeraIzq1CB1Click(TObject *Sender)
{byte m = StrToInt(InputBox("","Dimencion:",""));
 StringGrid1->ColCount = m; //Columna
 StringGrid1->RowCount = m; //filas
 byte k = 1;
 CargarDeraIzqCbFil(StringGrid1,0,m-1,0,m-1,k);
				 //          cb ca fb  fa cons
 /*Ej:  |  |  |  |  |1 |
		|  |  |  |2 |3 |
		|  |  |6 |5 |4 |
		|  |7 |8 |9 |10|
		|15|14|13|12|11|                              */
}
//---------------------------------------------------------------------------
void IzqaDerTrianabacol(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k,bool b){
byte c = cb-ca+1;
	if(c>0){
		if(b){
			M->Cells[ca][fb] = k++;
			IzqaDerTrianabacol(M,ca+1,cb,fa,fb,k,b);
		}
		else{
			M->Cells[cb][fb] = k++;
			IzqaDerTrianabacol(M,ca,cb-1,fa,fb,k,b);
		}
	}
}
void IzqaDerTrianabafil(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k,bool b){
byte n = fb-fa+1;
	if(n>0){
		IzqaDerTrianabacol(M,ca,cb,fa,fb,k,b);
		IzqaDerTrianabafil(M,ca,cb-1,fa,fb-1,k,!b);
	}
}
void __fastcall TForm2::ArribaDeraIzq1CB2Click(TObject *Sender)
{byte m = StrToInt(InputBox("","Dimencion:",""));
	StringGrid1->ColCount = m;
	StringGrid1->RowCount = m;
	byte k=1;
	IzqaDerTrianabafil(StringGrid1,0,m-1,0,m-1,k,true);
/*Ej:	   	|15|  |  |  |  |
			|14|13|  |  |  |
			|10|11|12|  |  |
			|9 |8 |7 |6 |  |
			|1 |2 |3 |4 |5 |                                 */
}
//---------------------------------------------------------------------------
void DiagMismoNumcol(TStringGrid *M,int ca,byte cb,byte fa,byte fb,byte &k,byte &z){
	if(ca>=0){
		M->Cells[ca][fa]=k;
		M->Cells[cb][fb]=z;
		DiagMismoNumcol(M,ca-1,cb+1,fa+1,fb-1,k,z);
	}
}
void DiagMismoNumfil(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k,byte &z){
	if(ca<=fb){
		DiagMismoNumcol(M,ca,cb,fa,fb,k,z);
		k++; z--;
		DiagMismoNumfil(M,ca+1,cb-1,fa,fb,k,z);
	}
}
void __fastcall TForm2::DiagMismonum1Click(TObject *Sender)
{byte m = StrToInt(InputBox("","Dimencion:",""));
	StringGrid1->ColCount = m;
	StringGrid1->RowCount = m;
	byte k=1; byte z = (m*2)-1;
	DiagMismoNumfil(StringGrid1,0,m-1,0,m-1,k,z);
/*Ej:  		|1|2|3|4|5|
			|2|3|4|5|6|
			|3|4|5|6|7|
			|4|5|6|7|8|
			|5|6|7|8|9|                                    */
}
//---------------------------------------------------------------------------
void Lhaciadentro2Col(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k){
byte n = cb-ca+1;
	if(n>0){
		M->Cells[ca][fa]=k;
		M->Cells[fa][ca]=k;
		Lhaciadentro2Col(M,ca+1,cb,fa,fb,k);
	}

}
void Lhaciadentro2fil(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k){
byte n = cb-fa+1;
	if(n>0){
		Lhaciadentro2Col(M,ca,cb,fa,fb,k);
		k++;
		Lhaciadentro2fil(M,ca+1,cb,fa+1,fb,k);
	}
}
void __fastcall TForm2::DiagMismonum2Click(TObject *Sender)
{byte c = StrToInt(InputBox("","Dimencion:",""));
 StringGrid1->ColCount = c;
 StringGrid1->RowCount = c;
 byte k=1;
 Lhaciadentro2fil(StringGrid1,0,c-1,0,c-1,k);
 /*  Ej:   	|1|1|1|1|1|
			|1|2|2|2|2|
			|1|2|3|3|3|
			|1|2|3|4|4|
			|1|2|3|4|5|					 */
}
//---------------------------------------------------------------------------
void cargarFila_aux(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte &k){
byte n=cb-ca+1;
	if (n>0) {
		m->Cells [ca][fa]=k++;
		cargarFila_aux(m,fa,fb,ca+1,cb,k);
	}
}
void cargarFila2_aux(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte &k){
	byte n=cb-ca+1;
	if (n>0) {
		m->Cells [cb][fb]=k++;
		cargarFila2_aux(m,fa,fb,ca,cb-1,k);
	}
}
void cargarCol_aux(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte &k){
	byte n=fb-fa+1;
	if (n>0) {
		m->Cells [cb][fa]=k++;
		cargarCol_aux(m,fa+1,fb,ca,cb,k);
	}
}
void cargarCol2_aux(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte &k){
	byte n=fb-fa+1;
	if (n>0) {
		m->Cells [ca][fb]=k++;
		cargarCol2_aux(m,fa,fb-1,ca,cb,k);
	}
}
//Proceso principal
void cargarCaracol_aux(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte &k){
byte n=fb-fa+1;
byte m2=cb-ca+1;
	if (m2*n>0) {//caso base m=0 o n=0
		if (m2*n==1) //2do caso base
			m->Cells[ca][fb]=k;
		else {//caso general
			cargarFila_aux(m,fa,fb,ca,cb-1,k);
			cargarCol_aux(m,fa,fb-1,ca,cb,k);
			cargarFila2_aux(m,fa,fb,ca+1,cb,k);
			cargarCol2_aux(m,fa+1,fb,ca,cb,k);
			cargarCaracol_aux(m,fa+1,fb-1,ca+1,cb-1,k);
		}
	}
}
void __fastcall TForm2::Caracol1Click(TObject *Sender)
{
	byte n=StrToInt(InputBox("","dimencion",""));
	StringGrid1->ColCount = n;
	StringGrid1->RowCount =n;
	byte k=1;
	cargarCaracol_aux(StringGrid1,0,n-1,0,n-1,k);
/*  |1 |2 |3 |4 |5 |
	|16|17|18|19|6 |
	|15|24|25|20|7 |
	|14|23|22|21|8 |
	|13|12|11|10|9 |				*/
}
//---------------------------------------------------------------------------
void SerpienteCol(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k,bool b){
byte c = cb-ca+1;
	if(c>0){
		if(b){
			M->Cells[ca][fa] = k++;
			SerpienteCol(M,ca+1,cb,fa,fb,k,b);
		}
		else{
			M->Cells[cb][fa] = k++;
			SerpienteCol(M,ca,cb-1,fa,fb,k,b);
		}
	}
}
void SerpienteFil(TStringGrid *M,byte ca,byte cb,byte fa,byte fb,byte &k,bool b){
byte n = fb-fa+1;
	if(n>0){
		SerpienteCol(M,ca,cb,fa,fb,k,b);
		SerpienteFil(M,ca,cb,fa+1,fb,k,!b);
	}
}
void __fastcall TForm2::Caracol2Click(TObject *Sender)
{byte n=StrToInt(InputBox("","Dimencion:",""));
   StringGrid1->ColCount=n;
   StringGrid1->RowCount=n;
   byte k=1;
   SerpienteFil(StringGrid1,0,n-1,0,n-1,k,true);
/* 	|1 |2 |3 |4 |5 |  ->
	|10|9 |8 |7 |6 |  <-
	|11|12|13|14|15|  ->
	|20|19|18|17|16|  <-
	|21|22|23|24|25|  ->                          */
}
//---------------------------------------------------------------------------
void triangseguida1cbAux(TStringGrid *M,byte ca,byte cb,byte fa,byte &k){
byte n = cb-ca+1;
	if(n>0){
		M->Cells[ca][fa] = k;
		triangseguida1cbAux(M,ca+1,cb,fa,++k);
	}
}
void triangseguida1cb(TStringGrid *M,byte ca,byte cb,byte fa,byte &k){
byte n = cb-ca+1;
	if(n>0){
		triangseguida1cbAux(M,ca,cb,fa,k);
		triangseguida1cb(M,ca,cb-1,fa+1,k);
	}
}
void __fastcall TForm2::Arriba1Cb1Click(TObject *Sender)
{byte n = StrToInt(InputBox("","Dimencion :",""));
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = n;
	byte k = 1;
	triangseguida1cb(StringGrid1,0,n-1,0,k);
/*  |1 |2 |3 |4 |5 |
	|6 |7 |8 |9 |  |
	|10|11|12|  |  |
	|13|14|  |  |  |
	|15|  |  |  |  |  				*/
}
//---------------------------------------------------------------------------
void diagMismoNum2Aux(TStringGrid *M,byte ca,byte cb,byte fa){
byte n = cb-ca+1;
	if(n>0){
		M->Cells[ca][fa]=ca+1;
		M->Cells[fa][ca]=ca+1;
		diagMismoNum2Aux(M,ca+1,cb,fa);
	}
}
 void diagMismoNum2(TStringGrid *M,byte ca,byte cb,byte fa){
 byte n = cb-fa+1;
	if(n>0){
		diagMismoNum2Aux(M,ca,cb,fa);
		diagMismoNum2(M,ca,cb,fa+1);
	}
 }
void __fastcall TForm2::Lhaciadentro1Click(TObject *Sender)
{byte n = StrToInt(InputBox("","Dimencion :",""));
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = n;
	diagMismoNum2(StringGrid1,0,StringGrid1->ColCount,0);
 /*  Ej:   	|1|1|1|1|1|
			|1|2|2|2|2|
			|1|2|3|3|3|
			|1|2|3|4|4|
			|1|2|3|4|5|					 */
}
//---------------------------------------------------------------------------

