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
	Edit2->Text=VectorANum(StringGrid1,StringGrid1->ColCount);
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