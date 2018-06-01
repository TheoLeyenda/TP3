#ifndef PARED_H
#define PARED_H
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
using namespace std;
class Pared
{
private:
	ALLEGRO_BITMAP  *bitmapPared;
	float x;
	float y;
	float h;
	float w;
	int numImage;
public:
	Pared();
	Pared(float _x, float _y, float _w, float _h);
	~Pared();
	void loadImage(int _numImage);
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);
	void draw(ALLEGRO_BITMAP *_bitmapEnemigo, int flags);
	ALLEGRO_BITMAP* getBitmap();
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	void setH(float _h);
	void setW(float _w);
	float getH();
	float getW();
};
#endif
