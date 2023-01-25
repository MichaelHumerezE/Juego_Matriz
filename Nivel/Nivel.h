//---------------------------------------------------------------------------
#ifndef NivelH
#define NivelH
#include <vcl.h>

using namespace std;

#include <string>

#include "Usuario.h"
#include "Matriz.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

class Nivel{
	private:
		int _tiempo;
		int _nivel;
		Matriz mat;
		Matriz respuesta;
		int _correcto;
	public:
		Usuario u;
		void create();
		void subirNivel();
		Matriz m1;
		Matriz m2;
		Matriz m3;
		Matriz m4;
		void iniciarJuego();
		String pregunta();
		String getm1();
		String getm2();
		String getm3();
		String getm4();
		bool responder(int);
		int getNivel();
		void setNivel(int nivel);
};

#endif
