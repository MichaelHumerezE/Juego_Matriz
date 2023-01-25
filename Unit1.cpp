//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "Unit1.h"
#include "Marcador.h"
#include "Nivel.h"
#include "Usuario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"

TForm1 *Form1;

Marcador marc;
int contador;
Nivel niv;
int cronometro;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner){
	Form1->Width = 410;
	Form1->Height = 260;
	Label19->Visible = true;
	Button11->Top = 152;
	Button11->Left = 98;
	Button11->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender){
	Edit2->Visible = true;
	Edit4->Visible = true;
	Button3->Visible = true;
	Button1->Visible = false;
	Button2->Visible = false;
	Label15->Visible = false;
	Label16->Visible = true;
	Label17->Visible = true;
	Label19->Visible = true;
    Form1->Width = 441;
	Form1->Height = 432;
	Button11->Top = 337;
	Button11->Left = 88;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender){
	Edit1->Visible = false;
	Edit2->Visible = false;
	Edit4->Visible = false;
	Button3->Visible = false;
	Button4->Visible = false;
	Button5->Visible = false;
	Button6->Visible = false;
	Label4->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
	Label7->Visible = false;
	Label10->Visible = false;
	Label11->Visible = false;
	Label13->Visible = false;
	Label14->Visible = false;
	RadioButton1->Visible = false;
	RadioButton2->Visible = false;
	RadioButton3->Visible = false;
	RadioButton4->Visible = false;
	Button7->Visible = false;
	Label12->Visible = false;
	niv.create();
	marc.create();
	contador = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender){
	Edit1->Visible = true;
	Edit2->Visible = true;
	Edit4->Visible = true;
	Button4->Visible = true;
	Button1->Visible = false;
	Button2->Visible = false;
	Label15->Visible = true;
	Label16->Visible = true;
	Label17->Visible = true;
	Label19->Visible = true;
    Form1->Width = 441;
	Form1->Height = 432;
	Button11->Top = 337;
	Button11->Left = 88;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender){
	String usuario = Edit1->Text;
	String correo = Edit2->Text;
	String password = Edit4->Text;
	niv.u.SetUsuario(usuario,password,correo);
	Label1->Caption = niv.u.getUser();
	Edit1->Visible = false;
	Edit2->Visible = false;
	Edit4->Visible = false;
	Button3->Visible = false;
	Button4->Visible = false;
	Button5->Visible = true;
	Label14->Visible = true;
	Label15->Visible = false;
	Label16->Visible = false;
	Label17->Visible = false;
	Label18->Visible = true;
    Label19->Visible = false;
	Button8->Visible = true;
	Button9->Visible = true;
	Button10->Visible = true;
	Button11->Visible = true;
	Form1->Width = 970;
	Form1->Height = 616;
	Button11->Top = 369;
	Button11->Left = 408;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender){
	String correo = Edit2->Text;
	String password = Edit4->Text;
	if(niv.u.login(correo,password)){
		Label1->Caption = niv.u.getUser();
		Edit1->Visible = false;
		Edit2->Visible = false;
		Edit4->Visible = false;
		Button3->Visible = false;
		Button4->Visible = false;
		Label2->Visible = false;
		Label14->Visible = true;
		Label3->Caption = "\n   NIVEL "+ (String)niv.getNivel();
		Button5->Visible = true;
		Label18->Visible = true;
        Label15->Visible = false;
		Label16->Visible = false;
		Label17->Visible = false;
		Button8->Visible = true;
		Button9->Visible = true;
		Button10->Visible = true;
		Form1->Width = 970;
		Form1->Height = 616;
		Button11->Visible = true;
		Label19->Visible = false;
        Button11->Top = 369;
		Button11->Left = 408;
	}
	else{
		Label2->Caption = "\nERROR DE CUENTA!!";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender){
	niv.iniciarJuego();
	Label4->Visible = true;
	Label5->Visible = true;
	Label6->Visible = true;
	Label7->Visible = true;
	Label10->Visible = true;
	Label11->Visible = true;
	Label4->Caption = niv.getm1();
	Label5->Caption = niv.getm2();
	Label6->Caption = niv.getm3();
	Label7->Caption = niv.getm4();
	Label8->Caption = niv.pregunta();
	Button6->Visible = true;
	RadioButton1->Visible = true;
	RadioButton2->Visible = true;
	RadioButton3->Visible = true;
	RadioButton4->Visible = true;
	Button5->Visible = false;
	Label11->Caption = (String)(niv.getNivel()*5);
	Timer1->Enabled = true;
	Button8->Visible = false;
	Button9->Visible = false;
	Button10->Visible = false;
    Button11->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender){
	bool respuesta;
	if(RadioButton1->Checked){
		respuesta = niv.responder(niv.m1.getTipo());
	}
		else if (RadioButton2->Checked) {
				respuesta =  niv.responder(niv.m2.getTipo());
			 }
				 else if(RadioButton3->Checked){
					respuesta = niv.responder(niv.m3.getTipo());
				 }
					else {
						respuesta = niv.responder(niv.m4.getTipo());
					}
	if(respuesta){
		//marc.agregar((cronometro*6)/niv.getNivel());
		if (niv.getNivel() == 3) {
			marc.agregar(20);           //100
		}else{
			if (niv.getNivel() == 2) {
				marc.agregar(17);       //102
			}else{
				if (niv.getNivel() == 1) {
					marc.agregar(15);   //105
				}
			}
		}
		Label9->Caption = "Respuesta Correcta! Puntaje: " + (String)marc.returnpuntaje();
		Label11->Caption = (String)(niv.getNivel()*5);
	}
		else {
			Label9->Caption = "Error Puntaje: " + (String)marc.returnpuntaje();
			Label11->Caption = (String)(niv.getNivel()*5);
		}

		if(contador>4){
			Label9->Caption = "Fin Del Juego";
			marc.guardarPuntaje(niv.getNivel(),Label1->Caption);
			Label4->Visible = false;
			Label5->Visible = false;
			Label6->Visible = false;
			Label7->Visible = false;
			Label8->Visible = false;
			Label9->Visible = false;
			Label10->Visible = false;
			Label11->Visible = false;
			RadioButton1->Visible = false;
			RadioButton2->Visible = false;
			RadioButton3->Visible = false;
			RadioButton4->Visible = false;
			Button6->Visible = false;
			Label12->Visible = true;
			Label12->Caption = "Fin Del Juego, Su Puntaje Es: " + (String)marc.returnpuntaje();
			Button7->Visible = true;
            Button11->Visible = true;
			Label13->Caption = marc.mostrarPuntajes(niv.getNivel());
			Label13->Visible = true;
			Timer1->Enabled=false;
			Button8->Visible = true;
			Button9->Visible = true;
			Button10->Visible = true;
			Button11->Top = 455;
			Button11->Left = 408;
		}
			else {
				niv.iniciarJuego();
				Label4->Caption=niv.getm1();
				Label5->Caption=niv.getm2();
				Label6->Caption=niv.getm3();
				Label7->Caption=niv.getm4();
				Label8->Caption = niv.pregunta();
				contador++;
			}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender){
	cronometro = Label11->Caption.ToInt();
	if(cronometro > 0){
		cronometro--;
		Label11->Caption = cronometro;
	}
	else{
		Label11->Caption = (String)(niv.getNivel() * 5);
		Button6->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender){
	niv.create();
	marc.create();
	String correo = Edit2->Text;
	String password = Edit4->Text;
	Button5->Click();
	Button7->Visible = false;
	Label9->Visible = true;
	Label12->Visible = false;
	Label13->Visible = false;
	Label8->Visible = true;
	contador = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender){
	niv.setNivel(1);
	Label3->Caption = "\n   NIVEL "+ (String)niv.getNivel();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender){
	niv.setNivel(2);
	Label3->Caption = "\n   NIVEL "+ (String)niv.getNivel();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender){
	niv.setNivel(3);
	Label3->Caption = "\n   NIVEL "+ (String)niv.getNivel();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender){
    Form1->Close();
}
//---------------------------------------------------------------------------

