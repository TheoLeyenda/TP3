#pragma once
#include "Enemigo.h"
#ifndef BLINDADO_H
#define BLINDADO_H
class Blindado :public Enemigo
{
private:
	ALLEGRO_BITMAP  *bitmapBlindado;
public:
	Blindado();
	Blindado(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida, float _velocidad);
	~Blindado();
	void movimiento();
	void loadImage();
	void setImage(int imagen);
	ALLEGRO_BITMAP* getBitmapBlindado();
	void drawBlindado(ALLEGRO_BITMAP *_bitmapBlindado, int flags);
};
#endif

