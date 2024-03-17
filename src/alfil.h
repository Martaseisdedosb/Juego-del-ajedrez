#pragma once
#include "ETSIDI.h"
#include "Pieza.h"


using namespace ETSIDI;

class alfil:public Pieza
{

public:
	alfil(): Pieza(){}
	alfil(Vector palfil, int c):Pieza(palfil, c, false) {}
	void dibuja();
	
	int mov_correcto(Vector,ListaPiezas&);
	void movimientos(Vector, ListaPiezas&);
	
};