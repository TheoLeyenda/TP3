#include "Tanque.h"

/*
void Jugador::draw(ALLEGRO_BITMAP *_bitmapJugador, int flags)
{

	al_draw_bitmap(bitmapJugador, x, y, flags);
}
*/
Tanque::Tanque()
{
	bitmapBalaTanque = NULL;
	bitmapTanque = NULL;
	numSprite = 1;
	disparoHabilitado = false;
	balaTanque = new Bala(getX(), getY(), 4, 12, 6, 1, 1);
	balaTanque->setX((getX() + getW()));
	balaTanque->setY((getY() + getH()));
}
Tanque::Tanque(float _x, float _y, float _w, float _h, float _anchoPantalla, float _altoPantalla, float _vida, float _velocidad, bool _esEnemigo, int _numSprite):Enemigo(_x, _y, _w, _h, _anchoPantalla, _altoPantalla, _vida, _velocidad)
{
	bitmapBalaTanque = NULL;
	bitmapTanque = NULL;
	esEnemigo = _esEnemigo;
	numSprite = _numSprite;
	balaTanque = new Bala(getX(), getY(), 4, 12, 6, 1, 1);
	balaTanque->setX((getX() + getW()));
	balaTanque->setY((getY() + getH()));
	disparoHabilitado = true;
}

Tanque::~Tanque()
{
	al_destroy_bitmap(bitmapTanque);
	delete balaTanque;
}
void Tanque::setDisparoHabilitado(bool _disparoHabilitado)
{
	disparoHabilitado = _disparoHabilitado;
}
bool Tanque::getDisparoHabilitado()
{
	return disparoHabilitado;
}
void Tanque::loadImage()
{
	if (numSprite == 1)
	{
		bitmapTanque = al_load_bitmap("../sprite/Enemigo1.png");
	}
	if (numSprite == 2)
	{
		bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1.png");
	}
	bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
	SetDirecion(1);
}
void Tanque::setImage(int imagen)
{
	if (numSprite == 1)
	{
		switch (imagen)
		{
		case 1:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1.png");
			SetDirecion(1);
			//w = 2;
			//h = 6;
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(1);
			}
			break;
		case 2:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Derecha.png");
			SetDirecion(2);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(2);
			}
			break;
		case 3:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Izquierda.png");
			SetDirecion(3);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(3);
			}
			break;
		case 4:
			bitmapTanque = al_load_bitmap("../sprite/Enemigo1 - Abajo.png");
			SetDirecion(4);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(4);
			}
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
		}
	}
	if (numSprite == 2)
	{
		switch (imagen)
		{
		case 1:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1.png");
			SetDirecion(1);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(1);
			}
			break;
		case 2:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Derecha.png");
			SetDirecion(2);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(2);
			}
			break;
		case 3:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Izquierda.png");
			SetDirecion(3);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(3);
			}
			break;
		case 4:
			bitmapTanque = al_load_bitmap("../sprite/TanqueJugado1 - Abajo.png");
			SetDirecion(4);
			if (!disparoHabilitado)
			{
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(4);
			}
			break;
		default:
			cout << "debe usarse un numero entre el 1 y el 4" << endl;
			break;
		}
	}
}
void Tanque::movimiento()
{
	int aux;
	//setDiley(150);
	if (getDiley() >= 150)
	{
		aux = rand() % 4 + 1;
		setImage(aux);
		setDiley(0);
	}
	setDiley(getDiley() + 1);
	switch (getDirecion())
	{
	case 1:
		//ANDA
		if (getY() >= 0)
		{
			setY(getY() - getVelocidad());
			//balaTanque->setImage(1);
		}
		else
		{
			setDiley(150);
		}
		break;
	case 2:
		//ANDA
		if (getX() <= getAnchoPantalla() - getW())
		{
			setX(getX() + getVelocidad());
			//balaTanque->setImage(2);
		}
		else
		{
			setDiley(150);
		}
		break;
	case 3:
		//ANDA
		if (getX() >= 0)
		{
			setX(getX() - getVelocidad());
			//balaTanque->setImage(3);
		}
		else
		{
			setDiley(150);
		}
		break;
	case 4:
		//ANDA
		if (getY() <= getAltoPantalla() - getH())
		{
			setY(getY() + getVelocidad());
			//balaTanque->setImage(4);
		}
		else
		{
			setDiley(150);
		}

	}
	
}
Bala* Tanque::getBalaTanque()
{
	return balaTanque;
}
ALLEGRO_BITMAP* Tanque::getBitmapTanque()
{
	return bitmapTanque;
}
void Tanque::drawTanque(ALLEGRO_BITMAP *_bitmapTanque, int flags)
{
	al_draw_bitmap(_bitmapTanque, getX(), getY(), flags);
}
void Tanque::setEsEnemigo(bool _esEnemigo)
{
	esEnemigo = _esEnemigo;
}
bool Tanque::getEsEnemigo()
{
	return esEnemigo;
}
void Tanque::disparar()
{
	if (disparoHabilitado == false)
	{
		if (numSprite == 1)
		{
			if (getDirecion() == 1)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
				balaTanque->setY((getY() + getH()) - getH() / 2);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(1);
			}
			if (getDirecion() == 2)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2);
				balaTanque->setY((getY() + getH()) - getH() / 2 - 4);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(2);
			}
			if (getDirecion() == 3)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2);
				balaTanque->setY((getY() + getH()) - getH() / 2 - 4);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(3);
			}
			if (getDirecion() == 4)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
				balaTanque->setY((getY() + getH()) - getH() / 2);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(4);
			}
		}
		if (numSprite == 2)
		{
			if (getDirecion() == 1)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
				balaTanque->setY((getY() + getH()) - getH() / 2);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(1);
			}
			if (getDirecion() == 2)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2);
				balaTanque->setY((getY() + getH()) - getH() / 2 - 6);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(2);
			}
			if (getDirecion() == 3)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2);
				balaTanque->setY((getY() + getH()) - getH() / 2 - 6);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
				balaTanque->setW(12);
				balaTanque->setH(4);
				balaTanque->setDireccion(3);
			}
			if (getDirecion() == 4)
			{
				balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
				balaTanque->setY((getY() + getH()) - getH() / 2);
				bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
				balaTanque->setW(4);
				balaTanque->setH(12);
				balaTanque->setDireccion(4);
			}
		}
		//dileyDisparo = 100;
	}
	else
	{
		balaTanque->draw(bitmapBalaTanque, 0);
		balaTanque->movimiento();
		if (balaTanque->getY() > getAltoPantalla() || balaTanque->getX() > getAnchoPantalla() || balaTanque->getY()<0 ||balaTanque->getX()<0)
		{
			if (numSprite == 1)
			{
				if (getDirecion() == 1)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
					balaTanque->setY((getY() + getH()) - getH() / 2);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
					balaTanque->setW(4);
					balaTanque->setH(12);
					balaTanque->setDireccion(1);
				}
				if (getDirecion() == 2)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2);
					balaTanque->setY((getY() + getH()) - getH() / 2 - 4);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
					balaTanque->setW(12);
					balaTanque->setH(4);
					balaTanque->setDireccion(2);
				}
				if (getDirecion() == 3)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2);
					balaTanque->setY((getY() + getH()) - getH() / 2 - 4);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
					balaTanque->setW(12);
					balaTanque->setH(4);
					balaTanque->setDireccion(3);
				}
				if (getDirecion() == 4)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
					balaTanque->setY((getY() + getH()) - getH() / 2);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
					balaTanque->setW(4);
					balaTanque->setH(12);
					balaTanque->setDireccion(4);
				}
			}
			if (numSprite == 2)
			{
				if (getDirecion() == 1)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
					balaTanque->setY((getY() + getH()) - getH() / 2);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo.png");
					balaTanque->setW(4);
					balaTanque->setH(12);
					balaTanque->setDireccion(1);
				}
				if (getDirecion() == 2)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2);
					balaTanque->setY((getY() + getH()) - getH() / 2 - 6);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Derecha.png");
					balaTanque->setW(12);
					balaTanque->setH(4);
					balaTanque->setDireccion(2);
				}
				if (getDirecion() == 3)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2);
					balaTanque->setY((getY() + getH()) - getH() / 2 - 6);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Izquierda.png");
					balaTanque->setW(12);
					balaTanque->setH(4);
					balaTanque->setDireccion(3);
				}
				if (getDirecion() == 4)
				{
					balaTanque->setX((getX() + getW()) - getW() / 2 - 2);
					balaTanque->setY((getY() + getH()) - getH() / 2);
					bitmapBalaTanque = al_load_bitmap("../sprite/balaTanqueRojo - Abajo.png");
					balaTanque->setW(4);
					balaTanque->setH(12);
					balaTanque->setDireccion(4);
				}
			}
		}
	}
}
