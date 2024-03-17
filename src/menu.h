#pragma once
#include "mundo.h"
#include "ETSIDI.h"

enum Estado { INICIO, JUEGO };

class menu
{
public:
	menu();
	~menu();
	void tecla(unsigned char key);
	void dibuja();
	void mueve();
	

protected:
	mundo mundo1;
	Estado estado;
	float tiempo;
	bool audio;

};

