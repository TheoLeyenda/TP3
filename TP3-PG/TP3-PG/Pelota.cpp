/*
private:
ALLEGRO_BITMAP  *bitmapJugador;
float x;
float y;
float h;
float w;

public:

Pelota();(HECHO)
Pelota(float _x, float _y, float _w, float _h);(HECHO)
void setImage();(HECHO)
ALLEGRO_BITMAP* getBitmap();(HECHO)
bool CheckLoadImage(ALLEGRO_DISPLAY *_display);(HECHO)
void draw(ALLEGRO_BITMAP *_bitmapPelota, int flags);(HECHO)
bool colicion(float W_enemy, float H_enemy, float X_enemy, float Y_enemy);
void setX(float _x);
void setY(float _y);
void setW(float _w);
void setH(float _h);
float getX();
float getY();
float getW();
float getH();
~Pelota();(HECHO)

};
*/
#include "Pelota.h"
Pelota::Pelota()
{
	bitmapPelota = NULL;
	x = 0;
	y = 0;
	h = 0;
	w = 0;
}
Pelota::Pelota(float _x, float _y, float _w, float _h)
{
	bitmapPelota = NULL;
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}
Pelota::~Pelota()
{
	al_destroy_bitmap(bitmapPelota);
}
void Pelota::setImage()
{
	bitmapPelota = al_load_bitmap("../sprite/pelotaOP1.png");
	if (bitmapPelota == NULL)
	{
		cout << "No cargo la imagen" << endl;
	}
}
ALLEGRO_BITMAP* Pelota::getBitmap()
{
	return bitmapPelota;
}
bool Pelota::CheckLoadImage(ALLEGRO_DISPLAY *_display)
{
	if (!bitmapPelota) {
		return false;
	}
	else
	{
		return true;
	}
}
void Pelota::draw(ALLEGRO_BITMAP *_bitmapPelota, int flags)
{
	al_draw_bitmap(bitmapPelota, x, y, flags);
}

void Pelota::setX(float _x)
{
	x = _x;
}
void Pelota::setY(float _y)
{
	y = _y;
}
float Pelota::getX()
{
	return x;
}
float Pelota::getY()
{
	return y;
}
void Pelota::setH(float _h)
{
	h = _h;
}
void Pelota::setW(float _w)
{
	w = _w;
}
float Pelota::getW()
{
	return w;
}
float Pelota::getH()
{
	return h;
}

bool Pelota::colicion(float W_enemy, float H_enemy, float X_enemy, float Y_enemy)
{
	if ((Y_enemy + H_enemy > y && y > Y_enemy && x >= X_enemy && x <= X_enemy + W_enemy) || (Y_enemy + H_enemy > y && y > Y_enemy && x + w >= X_enemy && x + w <= X_enemy + W_enemy))
	{
		cout << "abajo" << endl;
		return true;
	}
	if ((x > X_enemy && x<X_enemy + W_enemy && y > Y_enemy && y < Y_enemy + H_enemy) || (x > X_enemy && x < X_enemy + W_enemy && y + w > Y_enemy && y + w < Y_enemy + H_enemy))
	{
		cout << "Derecha" << endl;
		return true;
	}
	if ((x > X_enemy - W_enemy && x<X_enemy && y > Y_enemy && y < Y_enemy + H_enemy) || (x > X_enemy - W_enemy && x < X_enemy  && y + w > Y_enemy && y + w < Y_enemy + H_enemy))
	{
		cout << "izquierda" << endl;
		return true;
	}
	if (y + h > Y_enemy && y + h < Y_enemy + H_enemy && x > X_enemy && x < X_enemy + W_enemy || y + h > Y_enemy && y + h < Y_enemy + H_enemy && x + w > X_enemy && x + w < X_enemy + W_enemy)
	{
		cout << "Arriba" << endl;
		return true;
	}
	return false;
}