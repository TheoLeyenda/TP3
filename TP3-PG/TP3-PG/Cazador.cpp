#include "Cazador.h"



Cazador::Cazador():Enemigo()
{
}
Cazador::Cazador(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla) : Enemigo(_x, _y, _w, _h, _anchoPantalla, _altoPantalla)
{
}
Cazador::~Cazador()
{
}
void Cazador::movimiento()
{
	int aux;
	//setDiley(150);
	if (getDiley() >= 150)
	{
		aux = rand() % 4 + 1;
		setImage(aux);
		setDiley(0);
	}
	setDiley(getDiley()+1);
	switch (getDirecion())
	{
		case 1:
			//ANDA
			if (getY() >=0)
			{
				//y = y - 0.5;
				setY(getY() - 1);
			}
			else
			{
				//diley = 150;
				setDiley(150);
			}
			break;
		case 2:
		//ANDA
		if (getX() <= getAnchoPantalla()-getW())
		{
			//x = x + 0.5;
			setX(getX() + 1);
		}
		else
		{
			//diley = 150;
			setDiley(150);
		}
		break;
		case 3:
		//ANDA
		if (getX() >= 0)
		{
			//x = x - 0.5;
			setX(getX() - 1);
		}
		else
		{
			//diley = 150;
			setDiley(150);
		}
		break;
		case 4:
		//ANDA
		if (getY() <= getAltoPantalla()-getH())
		{
			//y = y + 0.5;
			setY(getY() + 1);
		}
		else
		{
			//diley = 150;
			setDiley(150);
		}

	}
}
ALLEGRO_BITMAP* Cazador::getBitmapCazador()
{
	return bitmapCazador;
}
void Cazador::loadImage()
{
	//bitmapJugador = al_load_bitmap("../Sprite/Enemigo1.png");
	//direcion= 1;
	bitmapCazador = al_load_bitmap("../sprite/EnemigoCazador - arriba.png");
	SetDirecion(1);
}
void Cazador::setImage(int imagen)
{
	switch (imagen)
	{
		case 1:
			bitmapCazador = al_load_bitmap("../sprite/EnemigoCazador - arriba.png");
			SetDirecion(1);
			break;
		case 2:
			bitmapCazador = al_load_bitmap("../Sprite/EnemigoCazador - derecha.png");
			SetDirecion(2);
			break;
		case 3:
			bitmapCazador = al_load_bitmap("../Sprite/EnemigoCazador - izquierda.png");
			SetDirecion(3);
			break;
		case 4:
			bitmapCazador = al_load_bitmap("../Sprite/EnemigoCazador - abajo.png");
			SetDirecion(4);
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
	}
}
void Cazador::drawCazador(ALLEGRO_BITMAP *_bitmapCazador, int flags)
{
	al_draw_bitmap(_bitmapCazador, getX(), getY(), flags);
}