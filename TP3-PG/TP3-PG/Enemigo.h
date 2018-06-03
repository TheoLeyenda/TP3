#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
class Enemigo
{
private:
	ALLEGRO_BITMAP  *bitmapEnemigo;
	float x;
	float y;
	float h;
	float w;
	int diley;
	int direcion;
	float anchoPantalla;
	float altoPantalla;
	bool Muerto;
	float vida;
public:
	Enemigo();
	Enemigo(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida);
	~Enemigo();
	void setMuerto(bool _muerto);
	bool getMuerto();
	virtual void loadImage();
	virtual void setImage(int imagen);
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);
	void draw(ALLEGRO_BITMAP *_bitmapEnemigo, int flags);
	ALLEGRO_BITMAP* getBitmap();
	void setBitmap(ALLEGRO_BITMAP *_bitmapEnemigo);
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	void setH(float _h);
	void setW(float _w);
	float getH();
	float getW();
	virtual void movimiento();
	void setDiley(int _diley);
	int getDiley();
	void setAnchoPantalla(float _anchoPantalla);
	float getAnchoPantalla();
	void setAltoPantalla(float _altoPantalla);
	float getAltoPantalla();
	void SetDirecion(int _direcion);
	int getDirecion();
	void setVida(float _vida);
	float getVida();
	void checkMuerto();
};
#endif
