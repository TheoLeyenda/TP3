#ifndef BALA_H
#define BALA_H
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
using namespace std;
class Bala
{
private:
	ALLEGRO_BITMAP  *bitmapBala;
	float x;
	float y;
	float h;
	float w;
	float velocidad;
	int direccion;
	float danio;
	bool dibujarse;
	bool yaDisparada;
	bool lastima;
public:
	Bala(float _x,float _y,float _w, float _h,float _velocidad,int _direccion,float _danio);
	Bala();
	~Bala();
	void setYaDisparada(bool _yaDisparada);
	bool getYaDisparada();
	void loadImage();
	void setImage(int _direcion);
	bool CheckLoadImage(ALLEGRO_DISPLAY *_display);
	void draw(ALLEGRO_BITMAP *_bitmapJugador, int flags);
	ALLEGRO_BITMAP* getBitmap();
	void movimiento();
	bool colicion(float W_enemy, float H_enemy, float X_enemy, float Y_enemy);
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	void setH(float _h);
	void setW(float _w);
	float getH();
	float getW();
	float getVelocidad();
	void setVelocidad(float _velocidad);
	int getDireccion();
	void setDireccion(int _direccion);
	float getDanio();
	void setDanio(float danio);
	bool getDibujarse();
	void setDibujarse(bool _dibujarse);
	bool getLastima();
	void setLastima(bool _lastima);
	
};
#endif BALA_H
