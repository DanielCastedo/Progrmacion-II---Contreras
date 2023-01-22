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
//------------------------- --------------------------------------------------
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