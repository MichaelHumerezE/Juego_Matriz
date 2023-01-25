//---------------------------------------------------------------------------

#pragma hdrstop

#include "Marcador.h"
#include <vcl.h>
#pragma package(smart_init)
#include <dos.h>
#include <stdio.h>
#include <fstream>

void Marcador::create(){
	puntaje = 0;
	std::time_t ct = std::time(0);
	char* cc = ctime(&ct);
	fecha = cc;
}

void Marcador::agregar(int puntos){
	puntaje = puntaje + puntos;
}

int Marcador::returnpuntaje(){
	return puntaje;
}

void Marcador::guardarPuntaje(int nivel, String nombre){
	ofstream registro;
	std::string linea,someString;
	string nombres =  AnsiStringToStr(nombre);
	switch (nivel){
		case 1:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel1.txt",ios::in|ios::ate);
			 break;
		case 2:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel2.txt",ios::in|ios::ate);
			 break;
		case 3:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel3.txt",ios::in|ios::ate);
			 break;
	default:
		;
	}
	registro<<"fecha:"<<fecha<<"/puntaje:"<<puntaje<<"/nombre:"<<nombres<<"/\n";
	registro.close();
}

String Marcador::mostrarPuntajes(int nivel){
	ifstream registro;
	switch (nivel){
		case 1:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel1.txt");
			 break;
		case 2:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel2.txt");
			 break;
		case 3:
		registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//nivel3.txt");
			 break;
	default:
		;
	}
	String resp;
	string reg;
	String puntuaciones = "";
	String orden;
	std::getline(registro, reg);
	while (reg != ""){
		puntuaciones = puntuaciones + "Fecha:";
		resp = StrToAnsiString(reg);
		String actual = resp[1];
		while (actual != ":"){
			resp.Delete(1,1);
			actual = resp[1];
		}
		resp.Delete(1,1);
		actual = resp[1];
		int contador = 30;
		while (contador > 6){
			puntuaciones = puntuaciones+actual;
			resp.Delete(1,1);
			actual = resp[1];
			contador--;
		}
		puntuaciones = puntuaciones + " ||puntuacion: ";
		std::getline(registro, reg);
		resp = StrToAnsiString(reg);
		actual = resp[1];
		while (actual != ":"){
			resp.Delete(1,1);
			actual = resp[1];
		}
		resp.Delete(1,1);
		actual = resp[1];
		while (actual != "/"){
			puntuaciones = puntuaciones + actual;
			resp.Delete(1,1);
			actual = resp[1];
		}
		resp.Delete(1,1);
		actual = resp[1];
		puntuaciones = puntuaciones + " ||nombre:";
		actual = resp[1];
		while (actual != ":"){
			resp.Delete(1,1);
			actual = resp[1];
		}
		resp.Delete(1,1);
		actual = resp[1];
		while (actual != "/"){
			puntuaciones = puntuaciones + actual;
			resp.Delete(1,1);
			actual = resp[1];
		}
		puntuaciones = puntuaciones+"\n";
		orden = puntuaciones + orden;
		puntuaciones="";
		std::getline(registro, reg);
	}
	orden = "Puntuaciones Del Nivel " + (String)nivel + "\n -----------------------------------\n" + orden;
	registro.close();
	return orden;
}

String Marcador::ultimos(String datos){

}

String Marcador::StrToAnsiString(string cadena){
	String res = "";
	for (int i = 0; i <= cadena.length() ; i++) {
		res += cadena[i];
	}
	return res;
}

string Marcador::AnsiStringToStr(String cadena){    //String a string
	string res = "";
	for (int i = 1; i <= cadena.Length(); i++) {
		res += cadena[i];
	}
	return res;
}



