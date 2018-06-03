#include "Blindado.h"
Blindado::Blindado(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida, float _velocidad) :Enemigo(_x, _y, _w, _h, _anchoPantalla, _altoPantalla, _vida, _velocidad)
{
	bitmapBlindado = NULL;
}
Blindado::Blindado():Enemigo()
{
	bitmapBlindado = NULL;
}
Blindado::~Blindado()
{
}
void Blindado::movimiento()
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

void Blindado::loadImage()
{
	bitmapBlindado = al_load_bitmap("../sprite/Blindado - Arriba.png");
	SetDirecion(1);
}
void Blindado::setImage(int imagen)
{
	switch (imagen)
	{
	case 1:
		bitmapBlindado = al_load_bitmap("../sprite/Blindado - Arriba.png");
		SetDirecion(1);
		break;
	case 2:
		bitmapBlindado = al_load_bitmap("../sprite/Blindado - Derecha.png");
		SetDirecion(2);
		break;
	case 3:
		bitmapBlindado = al_load_bitmap("../sprite/Blindado - Izquierda.png");
		SetDirecion(3);
		break;
	case 4:
		bitmapBlindado = al_load_bitmap("../sprite/Blindado - Abajo.png");
		SetDirecion(4);
		break;
	default:
		cout << "debe usarse un numero entre el 1 y el 4" << endl;
		break;
	}
}
ALLEGRO_BITMAP* Blindado::getBitmapBlindado()
{
	return bitmapBlindado;
}
void Blindado::drawBlindado(ALLEGRO_BITMAP *_bitmapBlindado, int flags)
{
	al_draw_bitmap(_bitmapBlindado, getX(), getY(), flags);
}