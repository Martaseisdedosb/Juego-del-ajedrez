#include "tablero.h"
#include "ListaPiezas.h"
#include "marco.h"
#include "Pieza.h"
#include "alfil.h"
#include "caballo.h"
#include "peon.h"
#include "reina.h"
#include "rey.h"
#include "torre.h"
#include "Vector.h"

class mundo
{
public:
	float x;
	float y;
	float z;
	Vector posini, posfin;

	Marco marco1;

	ListaPiezas listapiezas;


	mundo();
	~mundo();

	void inicializa();
	void dibuja();
	void mueve();

	void dibujatblancas();
	void dibujatnegras();

	tablero tablero1;

};