#include "reina.h"
#include"freeglut.h"
#include <iostream>

using namespace std;

void reina::dibuja() {

	glTranslatef(origen.x - 0.5, origen.y - 0.9, 0);
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaB.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaN.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-0.4, 0);
	glTexCoord2d(1, 1); glVertex2f(0.4, 0);
	glTexCoord2d(1, 0); glVertex2f(0.4, 0.8);
	glTexCoord2d(0, 0); glVertex2f(-0.4, 0.8);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-origen.x + 0.5, -origen.y + 0.9, 0);
}

int reina::mov_correcto(Vector v, ListaPiezas& l)
{
	Vector aux = origen;
	int contador = 0;
	int mover = 1;
	//los movimientos de la reina son equivalentes a torre+alfil
	
	//parte de la torre
	if ((v.x == origen.x) && (v.y == origen.y)) {
		return ERROR;
	}

	else if ((v.x > origen.x) && (v.y < origen.y) || (v.x < origen.x) && (v.y > origen.y)) {
		if (v.x + v.y == origen.x + origen.y) {
			contador++;

		}
		else
			return ERROR;
	}
	else if ((v.x < origen.x) && (v.y < origen.y) || (v.x > origen.x) && (v.y > origen.y)) {
		if (v.y - v.x == origen.y - origen.x) {
			contador++;

		}
		else
			return ERROR;
	}
	else {
		if ((v.x == origen.x) || (v.y == origen.y)) {
			contador++;
		}
		else 
			return ERROR;
	}


	//hacia arriba
	if (v.x == origen.x && v.y > origen.y + 1)
	{
		do
		{
			for (int i = 0; i < l.numero; i++) {
				if (aux.y + 1 == l.lista[i]->getpos().y && aux.x == l.lista[i]->getpos().x)
				{
					mover = 0;
				}

			}

			aux.y++;
		} while (aux.y + 1 != v.y);//mover 0 es que NO se puede mover
	}

	//hacia izquierda
	if (v.x < origen.x - 1 && v.y == origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++) {
				if (aux.x - 1 == l.lista[i]->getpos().x && aux.y == l.lista[i]->getpos().y)
				{
					mover = 0;
				}

			}

			aux.x--;
		} while (aux.x - 1 != v.x);//mover 0 es que NO se puede mover
	}

	//hacia derecha
	if (v.x > origen.x + 1 && v.y == origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++) {
				if (aux.x + 1 == l.lista[i]->getpos().x && aux.y == l.lista[i]->getpos().y)
				{
					mover = 0;
				}

			}

			aux.x++;
		} while (aux.x + 1 != v.x);//mover 0 es que NO se puede mover
	}

	//hacia abajo

	if (v.x == origen.x && v.y < origen.y - 1)
	{
		do
		{
			for (int i = 0; i < l.numero; i++) {
				if (aux.y - 1 == l.lista[i]->getpos().y && aux.x == l.lista[i]->getpos().x)
				{
					mover = 0;
				}

			}

			aux.y--;
		} while (aux.y - 1 != v.y);//mover 0 es que NO se puede mover
	}

		//arriba derecha

		if (v.x > origen.x + 1 && v.y > origen.y + 1)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux.x + 1 == l.lista[i]->getpos().x && aux.y + 1 == l.lista[i]->getpos().y)
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x++;
			} while (aux.x + 1 != v.x || aux.y + 1 != v.y);
		}

		//arriba izquierda
		if (v.x < origen.x - 1 && v.y > origen.y + 1)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux.x - 1 == l.lista[i]->getpos().x && aux.y + 1 == l.lista[i]->getpos().y)
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x--;
			} while (aux.x - 1 != v.x || aux.y + 1 != v.y);
		}

		//abajo derecha

		if (v.x > origen.x + 1 && v.y < origen.y - 1)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux.x + 1 == l.lista[i]->getpos().x && aux.y - 1 == l.lista[i]->getpos().y)
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x++;
			} while (aux.x + 1 != v.x || aux.y - 1 != v.y);
		}

		//abajo izquierda
		if (v.x < origen.x - 1 && v.y < origen.y - 1)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux.x - 1 == l.lista[i]->getpos().x && aux.y - 1 == l.lista[i]->getpos().y)
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x--;
			} while (aux.x - 1 != v.x || aux.y- 1 != v.y);
		}


	if (mover == 0)
		return ERROR;
	else
		contador++;


	if (Pieza::casillalibre(v, l) == 0)
		return ERROR;
	else
		contador++;


	if (contador == 3) {
		return MOV_CORRECTO;
	}

}

void reina::movimientos(Vector v,ListaPiezas& l)
{
	if (mov_correcto(v, l) == 1 && Pieza::casillalibre(v, l) == 1)
		Pieza::piezacomida(v, l);

	if (mov_correcto(v,l) == 1 && turno == 0) {

		turno = 2;
		if ((v.x == origen.x) && (v.y > origen.y))//mover arriba
		{
			do {
				origen.y = origen.y + 1;
			} while (origen.y != v.y);
		}
		if ((v.x == origen.x) && (v.y < origen.y))//mover abajo
		{
			do {
				origen.y = origen.y - 1;
			} while (origen.y != v.y);
		}
		if ((v.x > origen.x) && (v.y == origen.y))//mover derecha
		{
			do {
				origen.x = origen.x + 1;
			} while (origen.x != v.x);
		}
		if ((v.x < origen.x) && (v.y == origen.y))//mover izquierda
		{
			do {
				origen.x = origen.x - 1;
			} while (origen.x != v.x);
		}

		//parte alfil

		if (v.x > origen.x && v.y > origen.y) {
			do { //movimiento arriba-derecha

				origen.x = origen.x + 1;
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		if (v.x < origen.x && v.y < origen.y) {
			do { //movimiento abajo-izquierda

				origen.x = origen.x - 1;
				origen.y = origen.y - 1;


			} while (origen.x != v.x && origen.y != v.y);
		}

		if (v.x < origen.x && v.y > origen.y) {
			do { //arriba-izquierda

				origen.x = origen.x - 1;
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		if (v.x > origen.x && v.y < origen.y) {
			do { //abajo-derecha

				origen.x = origen.x + 1;
				origen.y = origen.y - 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		for (int i = 0; i < l.numero; i++) {
			if (l.lista[i]->getmarca() == true) {
				l.lista[i]->hayjaque(l);
				l.lista[i]->jaquemate(l);
			}
		}
	}
}