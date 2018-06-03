#include "Pared.h"
/*
private:
	ALLEGRO_BITMAP  *bitmapPared;
	float x;
	float y;
	float h;
	float w;
public:
	Pared();(HECHO)
	Pared(float _x, float _y, float _w, float _h);
	~Pared();(HECHO)
	virtual void loadImage();(HECHO)
	virtual void setImage(int imagen);(HECHO)
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);(HECHO)
	void draw(ALLEGRO_BITMAP *_bitmapEnemigo, int flags);(HECHO)
	ALLEGRO_BITMAP* getBitmap();(HECHO)
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	void setH(float _h);
	void setW(float _w);
	float getH();
	float getW();
*/


Pared::Pared()
{
	bitmapPared = NULL;
	x = 0; 
	y = 0;
	h = 0;
	w = 0;
}
Pared::Pared(float _x, float _y, float _w, float _h)
{
	bitmapPared = NULL;
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}
Pared::~Pared()
{
	al_destroy_bitmap(bitmapPared);
}
void Pared::loadImage(int _numImage)
{
	//segun el numero de _numImage es la imagen que se cargara a la pared
	switch (_numImage)
	{
		case 1:
			bitmapPared = al_load_bitmap("../sprite/MarronClarito.png");
			if (bitmapPared == NULL)
			{
				cout << "error, No se cargo la imagen 1"<<endl;
			}
			break;
		case 2:
			bitmapPared = al_load_bitmap("../sprite/MarronOscuro.png");
			break;
		case 3:
			bitmapPared = al_load_bitmap("../sprite/paredMadera - Abajo.png");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}
}
bool Pared::CheckLoadImage(ALLEGRO_DISPLAY *_display)
{
	if (!bitmapPared) {
		return false;
	}
	else
	{
		return true;
	}
}
ALLEGRO_BITMAP* Pared::getBitmap()
{
	return bitmapPared;
}
void Pared::draw(ALLEGRO_BITMAP *_bitmapPared, int flags)
{

	al_draw_bitmap(_bitmapPared, x, y, flags);
}
void Pared::setX(float _x)
{
	x = _x;
}
void Pared::setY(float _y)
{
	y = _y;
}
float Pared::getX()
{
	return x;
}
float Pared::getY()
{
	return y;
}
void Pared::setH(float _h)
{
	h = _h;
}
void Pared::setW(float _w)
{
	w = _w;
}
float Pared::getW()
{
	return w;
}
float Pared::getH()
{
	return h;
}
bool Pared::ColicionanConmigo(float W_enemy, float H_enemy, float X_enemy, float Y_enemy)
{
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
	if ((y < Y_enemy + H_enemy && y > Y_enemy + 5 && x > X_enemy && x < X_enemy + W_enemy || y < Y_enemy + H_enemy && y > Y_enemy + 5 && x + w > X_enemy && x + w < X_enemy + W_enemy))
	{
		//cout << "Abajo" << endl;
		return true;
	}
return false;
}