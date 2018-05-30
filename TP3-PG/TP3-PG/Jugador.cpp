#include "Jugador.h"

Jugador::Jugador()
{
	
	bitmapJugador = NULL;
	rotacion = 0;
	x = 400-13;
	y = 300 - 13;
	w = 8;
	h = 32;
	//bitmapJugador = al_create_bitmap(w, h);

}

Jugador::Jugador(float _x, float _y, float _w, float _h)
{
	bitmapJugador = NULL;
	x = _x;
	y = _y;
	w = _w;
	h = _h;
//	bitmapJugador = al_create_bitmap(w, h);
}

Jugador::~Jugador()
{
	al_destroy_bitmap(bitmapJugador);
	
}

void Jugador::loadImage()
{
	bitmapJugador = al_load_bitmap("../sprite/jugador - Arriba.png");
	if (bitmapJugador == NULL)
	{
		cout << "No cargo la imagen" << endl;
	}
}
bool Jugador::CheckLoadImage(ALLEGRO_DISPLAY *_display)
{
	if (!bitmapJugador) {
		return false;// si da falso que en el programa principal retorne 0
	}
	else
	{
		return true;
	}
}
void Jugador::setImage(int imagen)
{
	switch (imagen)
	{
	case 1:
		bitmapJugador = al_load_bitmap("../Sprite/jugador - Arriba.png");
		break;
	case 2:
		bitmapJugador = al_load_bitmap("../Sprite/jugador - derecha.png");
		break;
	case 3:
		bitmapJugador = al_load_bitmap("../Sprite/jugador - izquierda.png");
		break;
	case 4:
		bitmapJugador = al_load_bitmap("../Sprite/jugador - abajo.png");
		break;
	default:
		cout << "debe usarse un numero entre el 1 y el 4" << endl;
		break;
	}
}
void Jugador::draw(ALLEGRO_BITMAP *_bitmapJugador, int flags)
{

	al_draw_bitmap(bitmapJugador, x, y, flags);
}
ALLEGRO_BITMAP* Jugador::getBitmap()
{
	return bitmapJugador;
}
void Jugador::setX(float _x) 
{
	x = _x;
}
void Jugador::setY(float _y)
{
	y = _y;
}
float Jugador::getX()
{
	return x;
}
float Jugador::getY()
{
	return y;
}
void Jugador::setRotacion(float _rotacion)
{
	rotacion = _rotacion;
}
float Jugador::getRotacion()
{
	return rotacion;
}
void Jugador::setH(float _h)
{
	h = _h;
}
void Jugador::setW(float _w)
{
	w = _w;
}
float Jugador::getW()
{
	return w;
}
float Jugador::getH()
{
	return h;
}
bool Jugador::colicionEnemigo(float W_enemy, float H_enemy,float X_enemy, float Y_enemy)
{
	if ((Y_enemy + H_enemy > y && y > Y_enemy && x >= X_enemy && x <= X_enemy + W_enemy) || (Y_enemy + H_enemy > y && y > Y_enemy && x+w >= X_enemy && x+w <= X_enemy + W_enemy))
	{
		cout << "abajo" << endl;
		return true;
	}
	if ((x > X_enemy && x<X_enemy + W_enemy && y > Y_enemy && y < Y_enemy + H_enemy) || (x > X_enemy && x < X_enemy + W_enemy && y+w > Y_enemy && y+w < Y_enemy + H_enemy))
	{
		cout << "Derecha" << endl;
		return true;
	}
	if ((x > X_enemy-W_enemy && x<X_enemy && y > Y_enemy && y < Y_enemy + H_enemy) || (x > X_enemy - W_enemy && x < X_enemy  && y + w > Y_enemy && y + w < Y_enemy + H_enemy))
	{
		cout << "izquierda" << endl;
		return true;
	}
	if (y+h > Y_enemy && y+h < Y_enemy + H_enemy && x > X_enemy && x < X_enemy + W_enemy || y + h > Y_enemy && y + h < Y_enemy+ H_enemy && x+w > X_enemy && x+w < X_enemy + W_enemy)
	{
		cout << "Arriba" << endl;
		return true;
	}
	return false;
}