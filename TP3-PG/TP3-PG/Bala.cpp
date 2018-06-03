#include "Bala.h"
/*
ALLEGRO_BITMAP  *bitmapBala;
float x;
float y;
float h;
float w;
float velocidad;
int direccion;
float danio;
*/
Bala::Bala()
{
	bitmapBala = NULL;
	x = 0;
	y = 0;
	h = 0;
	w = 0; 
	velocidad = 0;
	direccion = 0;
	danio = 0;
	dibujarse = false;
	yaDisparada = false;
}
Bala::Bala(float _x, float _y, float _w, float _h, float _velocidad, int _direccion, float _danio)
{
	bitmapBala = NULL;
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	velocidad = _velocidad;
	direccion = _direccion;
	danio = _danio;
	dibujarse = false;
	yaDisparada = false;
}
Bala::~Bala()
{
	al_destroy_bitmap(bitmapBala);
}
void Bala::setYaDisparada(bool _yaDisparada)
{
	yaDisparada = _yaDisparada;
}
bool Bala::getYaDisparada()
{
	return yaDisparada;
}
void Bala::setDibujarse(bool _dibujarse)
{
	dibujarse = _dibujarse;
}
bool Bala::getDibujarse()
{
	return dibujarse;
}
void Bala::setX(float _x)
{
	x = _x;
}
void Bala::setY(float _y)
{
	y = _y;
}
float Bala::getX()
{
	return x;
}
float Bala::getY()
{
	return y;
}
void Bala::setH(float _h)
{
	h = _h;
}
void Bala::setW(float _w)
{
	w = _w;
}
float Bala::getW()
{
	return w;
}
float Bala::getH()
{
	return h;
}
bool Bala::colicion(float W_enemy, float H_enemy, float X_enemy, float Y_enemy)
{
	//ver si funciona
	//ANDA
	if ((x > X_enemy && x<X_enemy + W_enemy && y + h >= Y_enemy && y + h <= Y_enemy + 5 || x + w > X_enemy && x + w<X_enemy + W_enemy && y + h >= Y_enemy && y + h <= Y_enemy + 5))
	{
		//cout << "Arriba" << endl;
		return true;
	}
	//ANDA
	if (((y < Y_enemy + H_enemy && y > Y_enemy && x + w >= X_enemy && x + w <= X_enemy + W_enemy) || (y + h < Y_enemy + H_enemy && y + h > Y_enemy && x + w >= X_enemy && x + w <= X_enemy + W_enemy)))
	{
		//cout << "Izquierda" << endl;
		return true;
	}
	//ANDA
	if ((x > X_enemy && x<X_enemy + W_enemy && y > Y_enemy && y < Y_enemy + H_enemy || x > X_enemy && x<X_enemy + W_enemy && y + h > Y_enemy && y + h < Y_enemy + H_enemy))
	{
		//cout << "Derecha" << endl;
		return true;
	}
	//ANDA
	if ((y < Y_enemy + H_enemy && y > Y_enemy  && x > X_enemy && x < X_enemy + W_enemy || y > Y_enemy + H_enemy && y < Y_enemy  && x + w > X_enemy && x + w < X_enemy + W_enemy))
	{
		//cout << "Abajo" << endl;
		return true;
	}
	return false;
}
void Bala::loadImage()
{
	bitmapBala = al_load_bitmap("../sprite/BalaJugador.png");
	if (bitmapBala == NULL)
	{
		cout << "No cargo la imagen de Bala" << endl;
	}
}
bool Bala::CheckLoadImage(ALLEGRO_DISPLAY *_display)
{
	if (!bitmapBala) {
		return false;
	}
	else
	{
		return true;
	}
}
void Bala::draw(ALLEGRO_BITMAP *_bitmapJugador, int flags)
{

	al_draw_bitmap(_bitmapJugador, x, y, flags);
}
void Bala::setImage(int _direcion)
{
	switch (_direcion)
	{
	case 1:
		w = 2;
		h = 6;
		bitmapBala = al_load_bitmap("../sprite/BalaJugador.png");
		direccion = 1;//arriba
		break;
	case 2:
		w = 6;
		h = 2;
		bitmapBala = al_load_bitmap("../sprite/BalaJugador - derecha.png");
		direccion = 2;//derecha
		break;
	case 3:
		w = 6;
		h = 2;
		bitmapBala = al_load_bitmap("../sprite/BalaJugador - izquierda.png");
		direccion = 3;//izquierda
		break;
	case 4:
		w = 2;
		h = 6;
		bitmapBala = al_load_bitmap("../sprite/BalaJugador - Abajo.png");
		direccion = 4;//abajo
		break;
	default:
		cout << "debe usarse un numero entre el 1 y el 4" << endl;
		break;
	}
}
ALLEGRO_BITMAP* Bala::getBitmap()
{
	return bitmapBala;
}
void Bala::movimiento()
{
	switch (direccion)
	{
		case 1:
			y = y - velocidad;
			break;
		case 2:
			x = x + velocidad;
			break;
		case 3:
			x = x - velocidad;
			break;
		case 4:
			y = y + velocidad;
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
	}
}
float Bala::getVelocidad()
{
	return velocidad;
}
void Bala::setVelocidad(float _velocidad)
{
	velocidad = _velocidad;
}
int Bala::getDireccion()
{
	return direccion;
}
void Bala::setDireccion(int _direccion)
{
	direccion = _direccion;
}
float Bala::getDanio()
{
	return danio;
}
void Bala::setDanio(float _danio)
{
	danio = _danio;
}