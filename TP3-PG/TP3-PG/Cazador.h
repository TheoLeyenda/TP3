#ifndef CAZADOR_H
#define CAZADOR_H
#include "Enemigo.h"
class Cazador :public Enemigo
{
private:
	ALLEGRO_BITMAP  *bitmapCazador;
public:
	Cazador();
	Cazador(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, int _vida);
	void movimiento();
	~Cazador();
	void loadImage();
	void setImage(int imagen);
	ALLEGRO_BITMAP* getBitmapCazador();
	void drawCazador(ALLEGRO_BITMAP *_bitmapCazador, int flags);
};
#endif
