//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz.h"
//---------------------------------------------------------------------------

void Matriz::generarMatriz(int tipo){
	switch(tipo){
		case 1:
			_filas=1;
			_columnas=5;
			_tipo=1;
			_pregunta= "�C�al Es La Matriz Fila?"  ;
			mat1();
		break;
		case 2:
			_filas=5;
			_columnas=5;
			_tipo=2;
			_pregunta= "�C�al Es La Matriz Cuadrada?"  ;
			mat2();
		break;
			case 3:
			_filas=2;
			_columnas=5;
			_tipo=3;
			_pregunta= "�C�al Es La Matriz Rectangular?"  ;
			mat3();
		break;
		case 4:
			_filas=5;
			_columnas=5;
			_tipo=4;
			_pregunta= "�C�al Es La Matriz Triangular Superior?"  ;
			mat4();
		break;
		case 5:
			_filas=5;
			_columnas=5;
			_tipo=4;
			_pregunta= "�C�al Es La Matriz Triangular Inferior?"  ;
			mat5();
		break;
		case 6:
			_filas=5;
			_columnas=5;
			_tipo=6;
			_pregunta= "�C�al Es La Matriz Diagonal?"   ;
			mat6();
		break;
		case 7:
			_filas=5;
			_columnas=5;
			_tipo=7;
			_pregunta= "�C�al Es La Matriz Identidad?"  ;
			mat7();
		break;
	}
}

String Matriz::getMatriz(){
	return _matriz;
}

String Matriz::getPregunta(){
	return _pregunta;

}

int Matriz::getTipo()  {
	return _tipo;
}

void Matriz::mat1(){        //matriz fila
	String result = "";
	int num;
	for (int i = 0; i < 5; i++) {
		num=rand() % 9 + 1;
		result = result + " " + num;
	}
	_matriz = result;
}

void Matriz::mat2(){               // matriz cuadrada
	String result = "";
	int num;
	for(int j = 0; j < 5; j++){
		for (int i = 0; i < 5; i++) {
			num = rand() % 9 + 1;
			result = result +" "+ num;
		}
		result = result+"\n";
	}
	_matriz = result;
}

void Matriz::mat3(){      // matriz rectangular
	String result = "";
	int num;
	for(int j = 0; j < 3; j++){
		for (int i = 0; i < 5; i++) {
			num = rand() % 9 + 1;
			result = result + " " + num;
		}
		result = result + "\n";
	}
	_matriz = result;
}

void Matriz::mat4(){        //triangular superior
	String result = "";
	int num;
	for(int j = 0; j < 5; j++){
		for (int i = 0; i < 5; i++) {
			num = rand() % 9 + 1;
			if(i < j){
				result = result + " " + 0;
			}
				else{
					result = result + " " + num;
				}
		}
		result = result + "\n";
	}
	_matriz = result;
}

void Matriz::mat5(){            // triangular inferior
	String result = "";
	int num;
	for(int j = 0; j < 5; j++){
		for (int i = 0; i < 5; i++) {
			num = rand() % 9 + 1;
			if(i > j){
				result = result + " " + 0;
			}
				else{
					result = result + " " + num;
				}
		}
		result = result + "\n";
	}
	_matriz = result;
}

void Matriz::mat6(){            // matriz Diagonal
	String result = "";
	int num;
	for(int j = 0; j < 5; j++){
		for (int i = 0; i < 5; i++) {
			num = rand() % 9 + 1;
			if(i != j){
				result = result + " " + 0;
			}
				else{
					result = result + " " + num;
				}
		}
		result = result + "\n";
	}
	_matriz = result;
}

void Matriz::mat7(){            // matriz identidad
	String result = "";
	int num;
	for(int j = 0; j < 5; j++){
		for (int i = 0; i < 5; i++) {
			if(i != j){
				result = result + " " + 0;
			}
				else{
					result = result + " " + 1;
				}
		}
		result = result + "\n";
	}
	_matriz = result;
}

#pragma package(smart_init)
