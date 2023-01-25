//---------------------------------------------------------------------------

#pragma hdrstop

#include "Nivel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Nivel::create(){
	//setNivel(3);
	int nivel = u.getNivel();
	if(nivel == 1){
		_nivel = 1;
		_tiempo = 5;
	}
		else if(nivel == 2){
			_nivel = 2;
			_tiempo = 10;
		}
			else{
				_nivel = 3;
				_tiempo = 15;
			}
}

String Nivel::pregunta(){
	switch(_correcto){
			case 1:
			respuesta = m1;
			return m1.getPregunta();
			break;
				case 2:
				respuesta = m2;
			return m2.getPregunta();
			break;
				case 3:
				respuesta = m3;
			return m3.getPregunta();
			break;
				case 4:
				respuesta = m4;
			return m4.getPregunta();
			break;
	}
}

void Nivel::iniciarJuego(){
	_correcto = rand() % 4 + 1;
	m1.generarMatriz(rand() % 7 + 1);
	m2.generarMatriz(rand() % 7 + 1);
	m3.generarMatriz(rand() % 7 + 1);
	m4.generarMatriz(rand() % 7 + 1);

}

bool Nivel::responder(int resp){
	if (resp == respuesta.getTipo() ) {
		return true;
	}
	return false;
}

String Nivel::getm1(){
	return m1.getMatriz();
}

String Nivel::getm2(){
	return m2.getMatriz();
}

String Nivel::getm3(){
	return m3.getMatriz();
}

String Nivel::getm4(){
	return m4.getMatriz();
}

void Nivel::subirNivel(){
	int nuevoNivel = u.getNivel() + 1;
	u.setNivel(nuevoNivel);
	_nivel = u.getNivel();
}

int Nivel::getNivel(){
	return u.getNivel();
}

void Nivel::setNivel(int nivel){
 	u.setNivel(nivel);
}