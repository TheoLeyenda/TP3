#ifndef PELOTA_H
#define PELOTA_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
using namespace std;
class Pelota
{
private:
	ALLEGRO_BITMAP  *bitmapPelota;
	float x;
	float y;
	float h;
	float w;
public:
	Pelota();
	Pelota(float _x, float _y, float _w, float _h);
	void setImage();
	ALLEGRO_BITMAP* getBitmap();
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);
	void draw(ALLEGRO_BITMAP *_bitmapPelota, int flags);
	bool colicion(float W_enemy, float H_enemy, float X_enemy, float Y_enemy);
	void setX(float _x);
	void setY(float _y);
	void setW(float _w);
	void setH(float _h);
	float getX();
	float getY();
	float getW();
	float getH();
	~Pelota();
};
#endif

