//---------------------------------------------------------------------------

#ifndef MatrizH
#define MatrizH

#include <vcl.h>

#include <string>

#include "Usuario.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//---------------------------------------------------------------------------

class Matriz{
	private:
		int _filas;
		int _columnas;
		int _tipo;
		String _matriz;
		String _pregunta;
	public:
		void generarMatriz(int tipo);
		String getMatriz();
		String getPregunta();
		int getTipo();
		void mat1();
		void mat2();
		void mat3();
		void mat4();
		void mat5();
		void mat6();
		void mat7();
};

#endif
