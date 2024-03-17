#pragma once
#include "Pieza.h"

class rey :public Pieza {
public:
	rey() :Pieza() {}
	rey(Vector prey, int c) :Pieza(prey, c, true) {}

	void dibuja();
	int mov_correcto(Vector, ListaPiezas&);
	void movimientos(Vector, ListaPiezas&);
};
