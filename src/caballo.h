#pragma once
#define MOV_CORRECTO 1

#include "Pieza.h"

class caballo :public Pieza
{
private:

public:
	caballo() :Pieza() {}
	caballo(Vector  pcaballo, int c):Pieza(pcaballo, c, false) {}
	void dibuja();

	int mov_correcto(Vector, ListaPiezas&);
	void movimientos(Vector, ListaPiezas&);


};