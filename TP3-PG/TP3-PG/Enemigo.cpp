#include "Enemigo.h"


Enemigo::Enemigo()
{
	bitmapEnemigo = NULL;
	x = 0;
	y = 0;
	w = 36;
	h = 38;
	diley = 150;
	srand(time(0));
	anchoPantalla = 640;
	altoPantalla = 480;
	Muerto = false;
	vida = 100;
}
Enemigo::Enemigo(float _x, float _y, float _w, float _h,float _anchoPantalla, float _altoPantalla, int _vida)
{
	bitmapEnemigo = NULL;
	x = _x;
	y = _y;
	h = _h;
	w = _w;
	diley = 150;
	srand(time(0));
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	Muerto = false;
	vida = _vida;
}

Enemigo::~Enemigo()
{
	al_destroy_bitmap(bitmapEnemigo);
}
void Enemigo::checkMuerto()
{
	if (vida <= 0)
	{
		Muerto = true;
	}
}
void Enemigo::loadImage()
{
}
void Enemigo::setMuerto(bool _muerto)
{
	Muerto = _muerto;
}
bool Enemigo::getMuerto()
{
	return Muerto;
}
void Enemigo::setImage(int imagen)
{
	
}
bool Enemigo::CheckLoadImage(ALLEGRO_DISPLAY *_display)
{
	if (!bitmapEnemigo) {
		return false;// si da falso que en el programa principal retorne 0
	}
	else
	{
		return true;
	}
}
void Enemigo::draw(ALLEGRO_BITMAP *_bitmapEnemigo, int flags)
{

	al_draw_bitmap(_bitmapEnemigo, x, y, flags);
}
ALLEGRO_BITMAP* Enemigo::getBitmap()
{
	return bitmapEnemigo;
}
void Enemigo::setX(float _x)
{
	x = _x;
}
void Enemigo::setY(float _y)
{
	y = _y;
}
float Enemigo::getX()
{
	return x;
}
float Enemigo::getY()
{
	return y;
}
void Enemigo::setH(float _h)
{
	h = _h;
}
void Enemigo::setW(float _w)
{
	w = _w;
}
float Enemigo::getW()
{
	return w;
}
float Enemigo::getH()
{
	return h;
}
void Enemigo::setVida(int _vida)
{
	vida = _vida;
}
int Enemigo::getVida()
{
	return vida;
}
void Enemigo::movimiento()
{
	/*int aux;
	if (diley >= 150)
	{
		aux = rand() % 4 + 1;
		setImage(aux);
		diley = 0;
	}
	diley++;
	switch (direcion)
	{
		case 1:
			//ANDA
			if (y >=0)
			{
				y = y - 0.5;
			}
			else
			{
				diley = 150;
			}
			break;
		case 2:
			//ANDA
			if (x <= anchoPantalla-w)
			{
				x = x + 0.5;
			}
			else
			{
				diley = 150;
			}
			break;
		case 3:
			//ANDA
			if (x >= 0)
			{
				x = x - 0.5;
			}
			else
			{
				diley = 150;
			}
			break;
		case 4:
			//ANDA
			if (y <= altoPantalla-h)
			{
				y = y + 0.5;
			}
			else
			{
				diley = 150;
			}

	}*/
}
void Enemigo::setDiley(int _diley)
{
	diley = _diley;
}
int Enemigo::getDiley()
{
	return diley;
}
void Enemigo::setAnchoPantalla(float _anchoPantalla)
{
	anchoPantalla = _anchoPantalla;
}
float Enemigo::getAnchoPantalla()
{
	return anchoPantalla;
}
void Enemigo::SetDirecion(int _direcion)
{
	direcion = _direcion;
}
int Enemigo::getDirecion()
{
	return direcion;
}
void Enemigo::setAltoPantalla(float _altoPantalla)
{
	altoPantalla = _altoPantalla;
}
float Enemigo::getAltoPantalla() 
{
	return altoPantalla;
}
void Enemigo::setBitmap(ALLEGRO_BITMAP* _bitmapEnemigo)
{
	bitmapEnemigo = _bitmapEnemigo;
}