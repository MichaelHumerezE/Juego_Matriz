//---------------------------------------------------------------------------

#pragma hdrstop
#include <fstream>

#include "Usuario.h"

//---------------------------------------------------------------------------

void Usuario::SetUsuario(String usuario, String password, String correo){
	string us = AnsiStringToStr(usuario);
	string cor =  AnsiStringToStr(correo);
	string pass =  AnsiStringToStr(password);
	ofstream registro;
	std::string linea,someString;
	registro.open("D://219190658//Borrado//JuegoMatriz//registro.txt",ios::in|ios::ate);
	registro<<"correo:"<<cor<<"/password:"<<pass<<"/usuario:"<<us<<"/\n";
	registro.close();
	_userName = usuario;
	_correo = correo;
	_password = password;
	_nivel = 3;
}

int Usuario::getNivel(){
	return _nivel;
}


Boolean Usuario::login(String usuario, String password){
	ifstream registro;
	registro.open("D://219190658//Borrado//ProyectoJuegoMatriz//registro.txt");
	String resp;
	string reg;
	std::getline(registro, reg);
	while (reg != ""){
		resp = StrToAnsiString(reg);
		setDatos(resp);
			if(_correo == usuario && _password == password){
				return true;
		}
		std::getline(registro, reg);
	}
	registro.close();
	return false;
}

void Usuario::setNivel(int nivel){
	_nivel = nivel;
}

void Usuario::setDatos(String datos){
	String actual = datos[1];
	String correo = "";
	String password = "";
	String nombre = "";
	while (actual != ":"){
		datos.Delete(1,1);
		actual = datos[1];
	}
	datos.Delete(1,1);
	actual = datos[1];
	while (actual != "/"){
		correo = correo+actual;
		datos.Delete(1,1);
		actual = datos[1];
	}
	datos.Delete(1,1);
	actual = datos[1];
	while (actual != ":"){
		datos.Delete(1,1);
		actual = datos[1];
	}
	datos.Delete(1,1);
	actual = datos[1];
	while (actual != "/"){
		password = password + actual;
		datos.Delete(1,1);
		actual = datos[1];
	}
	datos.Delete(1,1);
	actual = datos[1];
	while (actual != ":"){
		datos.Delete(1,1);
		actual = datos[1];
	}
	datos.Delete(1,1);
	actual = datos[1];
	while (actual != "/"){
		nombre = nombre+actual;
		datos.Delete(1,1);
		actual = datos[1];
	}
	_correo = correo;
	_userName = nombre;
	_password = password;
}

String Usuario::getUser(){
	return _userName;
}

string Usuario::AnsiStringToStr(String cadena){    //String a string
	string res = "";
	for (int i = 1; i <= cadena.Length(); i++) {
		res += cadena[i];
	}
	return res;
}

String Usuario::StrToAnsiString(string cadena){
	String res = "";
	for (int i = 0; i <= cadena.length() ; i++) {
		res += cadena[i];
	}
	return res;
}

#pragma package(smart_init)
