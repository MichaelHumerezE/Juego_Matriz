//---------------------------------------------------------------------------

#ifndef MarcadorH
#define MarcadorH
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <vcl.h>

using namespace std;

//---------------------------------------------------------------------------

class Marcador{
	private:
		int puntaje;
		string fecha;
	public:
		void create();
		void agregar(int);
		int returnpuntaje();
		void guardarPuntaje(int nivel, String nombre);
		String mostrarPuntajes(int);
		String StrToAnsiString(string cadena);
		string AnsiStringToStr(String cadena);
		String ultimos(String);
};

#endif
