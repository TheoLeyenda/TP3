#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
using namespace std;
class Jugador
{
private:
	ALLEGRO_BITMAP  *bitmapJugador;
	float x;
	float y;
	float h;
	float w;
	float rotacion;
public:
	Jugador();
	Jugador(float _x, float _y, float _w, float _h);
	~Jugador();
	void loadImage();
	void Jugador::setImage(int imagen);
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);
	void draw(ALLEGRO_BITMAP *_bitmapJugador, int flags);
	ALLEGRO_BITMAP* getBitmap();
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	void setH(float _h);
	void setW(float _w);
	float getH();
	float getW();
	void setRotacion(float _rotacion);
	float getRotacion();
	bool colicionEnemigo(float W_enemy, float H_enemy, float X_enemy, float Y_enemy);
};
#endif
