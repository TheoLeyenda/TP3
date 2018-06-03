#include "Tanque.h"

/*
void Jugador::draw(ALLEGRO_BITMAP *_bitmapJugador, int flags)
{

	al_draw_bitmap(bitmapJugador, x, y, flags);
}
*/
Tanque::Tanque()
{
	bitmapTanque = NULL;
	numSprite = 1;
}
Tanque::Tanque(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida, float _velocidad, bool _esEnemigo , int _numSprite):Enemigo(_x, _y, _w, _h, _anchoPantalla, _altoPantalla, _vida, _velocidad)
{
	bitmapTanque = NULL;
	esEnemigo = _esEnemigo;
	numSprite = _numSprite;
}

Tanque::~Tanque()
{
	al_destroy_bitmap(bitmapTanque);
}
void Tanque::loadImage()
{
	if (numSprite == 1)
	{
		bitmapTanque = al_load_bitmap("../sprite/Enemigo1.png");
	}
	if (numSprite == 2)
	{
		bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1.png");
	}
	SetDirecion(1);
}
void Tanque::setImage(int imagen)
{
	if (numSprite == 1)
	{
		switch (imagen)
		{
		case 1:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1.png");
			SetDirecion(1);
			break;
		case 2:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Derecha.png");
			SetDirecion(2);
			break;
		case 3:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Izquierda.png");
			SetDirecion(3);
			break;
		case 4:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Abajo.png");
			SetDirecion(4);
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
		}
	}
	if (numSprite == 2)
	{
		switch (imagen)
		{
		case 1:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1.png");
			SetDirecion(1);
			break;
		case 2:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Derecha.png");
			SetDirecion(2);
			break;
		case 3:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Izquierda.png");
			SetDirecion(3);
			break;
		case 4:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Abajo.png");
			SetDirecion(4);
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
		}
	}
}
void Tanque::movimiento()
{
	int aux;
	//setDiley(150);
	if (getDiley() >= 150)
	{
		aux = rand() % 4 + 1;
		setImage(aux);
		setDiley(0);
	}
	setDiley(getDiley() + 1);
	switch (getDirecion())
	{
	case 1:
		//ANDA
		if (getY() >= 0)
		{
			setY(getY() - getVelocidad());
		}
		else
		{
			setDiley(150);
		}
		break;
	case 2:
		//ANDA
		if (getX() <= getAnchoPantalla() - getW())
		{
			setX(getX() + getVelocidad());
		}
		else
		{
			setDiley(150);
		}
		break;
	case 3:
		//ANDA
		if (getX() >= 0)
		{
			setX(getX() - getVelocidad());
		}
		else
		{
			setDiley(150);
		}
		break;
	case 4:
		//ANDA
		if (getY() <= getAltoPantalla() - getH())
		{
			setY(getY() + getVelocidad());
		}
		else
		{
			setDiley(150);
		}

	}
}
ALLEGRO_BITMAP* Tanque::getBitmapTanque()
{
	return bitmapTanque;
}
void Tanque::drawTanque(ALLEGRO_BITMAP *_bitmapTanque, int flags)
{
	al_draw_bitmap(_bitmapTanque, getX(), getY(), flags);
}
void Tanque::setEsEnemigo(bool _esEnemigo)
{
	esEnemigo = _esEnemigo;
}
bool Tanque::getEsEnemigo()
{
	return esEnemigo;
}
