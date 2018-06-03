#ifndef TANQUE_H
#define TANQUE_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include <stdlib.h>
#include <time.h>
#include "Enemigo.h"
using namespace std;
class Tanque:public Enemigo
{
private:
	ALLEGRO_BITMAP  *bitmapTanque;
	bool esEnemigo;
	int numSprite;
public:
	Tanque();
	Tanque(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida, float _velocidad, bool _esEnemigo, int _numSprite);
	~Tanque();
	void movimiento();
	void loadImage();
	void setImage(int imagen);
	ALLEGRO_BITMAP* getBitmapTanque();
	void drawTanque(ALLEGRO_BITMAP *_bitmapTanque, int flags);
	void setEsEnemigo(bool _esEnemigo);
	bool getEsEnemigo();
};
#endif
