#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Cazador.h"
#include "Bala.h"
#include "Blindado.h"
#include "Pared.h"
#include "Tanque.h"
#include <list>
#include <stack>
#define CARGADOR 15
#define VELOCIDADJUGADOR 2.5
using namespace std;
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int JUGADOR_SIZE = 32;

void draw(ALLEGRO_BITMAP *_bitmap,float X_bitmap, float Y_bitmap, int flags)
{
	al_draw_bitmap(_bitmap, X_bitmap, Y_bitmap, flags);
}
int main(int argc, char **argv)
{
	//cout << "LA CONCHA DE TU MADRE" << endl;
	int subIndiceBala = 0;
	bool gameOver = false;
	bool salirDefinitivo = false;
	int imagenJugador = 0;
	int cantBalas = CARGADOR;
	float velocidadJugador = 2.5;
	//  Crea un puntero a un ALLEGRO_DISPLAY
	ALLEGRO_DISPLAY* ventana;
	ALLEGRO_DISPLAY *display = NULL;
	float widthPantalla = 800;
	float heightPantalla = 600;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP  *fondo = NULL;

	Jugador *player = new Jugador(350,30,25,25,1,3);
	imagenJugador = player->getVision();
	Enemigo *cazador1 = new Cazador(0, 0, 20, 20, widthPantalla, heightPantalla, 1,2);
	Enemigo *blindado = new Blindado(600, 400, 32, 32, widthPantalla, heightPantalla, 100,0.8);
	Bala *bala[CARGADOR]; //= new Bala(0, 0, 2, 6, 4, 1, 5);
	
	Pared *pared = new Pared(0, 60,32, 32);
	Enemigo *tanqueRojo = new Tanque(200, 200, 36, 38, widthPantalla, heightPantalla,100,0.5,true,1);
	//list<int>* l = new list<int>();
	
	for (int i = 0; i < CARGADOR; i++)
	{
		bala[i] = new Bala(0, 0, 2, 6, 4,1, 5);
		bala[i]->setYaDisparada(false);
		bala[i]->setDibujarse(false);
	}
	//  Inicia allegro5, esto es necesario para realizar cualquier
	//  función de allegro
	al_init();
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_init_primitives_addon();
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	if (!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	display = al_create_display(widthPantalla, heightPantalla);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	player->loadImage();
	cazador1->loadImage();
	//bala->loadImage();
	pared->loadImage(3);
	blindado->loadImage();
	tanqueRojo->loadImage();
	for (int i = 0; i < CARGADOR; i++)
	{
		bala[i]->loadImage();
	}
	fondo = al_load_bitmap("../sprite/FondoOP2.png");
	if (!fondo)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	if (!player->CheckLoadImage(display))
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}
	//game loop
	al_start_timer(timer);
	while (!gameOver) {
		player->setImage(imagenJugador);
		if (player->getVidas() <= 0)
		{
			gameOver = true;
		}
		//  La siguiente función limpia el buffer, con un color determinado, 
		//  recibe como parámetro un ALLEGRO_COLOR. 
		//  La función al_map_rgb(0,0,0) recibe como tres enteres sin signo,
		//  cada uno determina la cantidad del color rojo, verde y azul
		//  respectivamente; esta función devuelve un ALLEGRO_COLOR con lo
		//  que encaja perfecto con el parámetro que recibe la función
		//  al_clear_to_color(...)
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(fondo, 0, 0, 0);
		player->draw(player->getBitmap(), 0);
		((Tanque*)tanqueRojo)->disparar();
		if (blindado->getMuerto() == false)
		{
			((Blindado*)blindado)->drawBlindado(((Blindado*)blindado)->getBitmapBlindado(), 0);
		}
		blindado->movimiento();
		if (cazador1->getMuerto() == false) 
		{
			((Cazador*)cazador1)->drawCazador(((Cazador*)cazador1)->getBitmapCazador(), 0);
		}
		cazador1->movimiento();
		if (tanqueRojo->getMuerto() == false)
		{
			((Tanque*)tanqueRojo)->drawTanque(((Tanque*)tanqueRojo)->getBitmapTanque(), 0);
		}
		//tanqueRojo->setImage(4);
		tanqueRojo->movimiento();
		for (int i = 0; i < CARGADOR; i++)
		{
			if (bala[i]->getDibujarse())
			{
				bala[i]->draw(bala[i]->getBitmap(), 0);
				bala[i]->movimiento();
			}
		}
		pared->draw(pared->getBitmap(), 0);
		//  Intercambia los buffers, ahora la ventana mostrará tendrá fondo
		//  de color negro. Si minimiza la ventana y la vuelve restaurar, se
		//  dará cuenta que ahora la pantalla muestra lo que estuve detrás.
		//  Esto es porque el buffer ahora tiene lo que estaba detrás de la
		//  ventana. Luego veremos como redibujar la ventana cuando se realice
		//  un evento.
		al_flip_display();
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		switch (ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_ESCAPE:
				gameOver = true;
				salirDefinitivo = true;
				
				break;
			case ALLEGRO_KEY_UP:
				//ANDA
				if (player->getY() > 0)
				{
					player->setY(player->getY() - velocidadJugador);
					player->setImage(1);
					imagenJugador = 1;
					for (int i = 0; i < CARGADOR; i++)
					{
						if (bala[i]->getYaDisparada() == false)
						{
							bala[i]->setImage(1);
						}
					}
				}
				break;
			case ALLEGRO_KEY_DOWN:
				//ANDA
				if (player->getY() < heightPantalla - player->getH())
				{
					player->setY(player->getY() + velocidadJugador);
					player->setImage(4);
					imagenJugador = 4;
					for (int i = 0; i < CARGADOR; i++)
					{
						if (bala[i]->getYaDisparada() == false)
						{
							bala[i]->setImage(4);
						}
					}
				}
				break;
			case ALLEGRO_KEY_LEFT:
				//ANDA
				if (player->getX() > 0)
				{
					player->setX(player->getX() - velocidadJugador);
					player->setImage(3);
					imagenJugador = 3;
					for (int i = 0; i < CARGADOR; i++)
					{
						if (bala[i]->getYaDisparada() == false)
						{
							bala[i]->setImage(3);
						}
					}
				}
				break;
			case ALLEGRO_KEY_RIGHT:
				//ANDA
				if (player->getX() < widthPantalla - player->getH())
				{
					player->setX(player->getX() + velocidadJugador);
					player->setImage(2);
					imagenJugador = 2;
					for (int i = 0; i < CARGADOR; i++)
					{
						if (bala[i]->getYaDisparada() == false)
						{
							bala[i]->setImage(2);
						}
					}
				}
				break;

			case ALLEGRO_KEY_R:
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					if (cantBalas <= 0)
					{
						for (int i = 0; i < CARGADOR; i++)
						{
							if (bala[i]->getYaDisparada() && bala[i]->getDibujarse() == false)
							{
								if (!bala[i]->getDibujarse() && player->getVision() == 1 && bala[i]->getYaDisparada() == true)
								{
									bala[i]->setX(player->getX() + 18);
									bala[i]->setY(player->getY());
									bala[i]->setYaDisparada(false);
									bala[i]->setDibujarse(false);
									bala[i]->setLastima(true);
									bala[i]->setImage(1);
								}
								if (!bala[i]->getDibujarse() && player->getVision() == 2 && bala[i]->getYaDisparada() == true)
								{
									bala[i]->setX(player->getX() + 18);
									bala[i]->setY(player->getY() + 18);
									bala[i]->setYaDisparada(false);
									bala[i]->setDibujarse(false);
									bala[i]->setLastima(true);
									bala[i]->setImage(2);
								}
								if (!bala[i]->getDibujarse() && player->getVision() == 3 && bala[i]->getYaDisparada() == true)
								{
									bala[i]->setX(player->getX());
									bala[i]->setY(player->getY() + 5);
									bala[i]->setYaDisparada(false);
									bala[i]->setDibujarse(false);
									bala[i]->setLastima(true);
									bala[i]->setImage(3);
								}
								if (!bala[i]->getDibujarse() && player->getVision() == 4 && bala[i]->getYaDisparada() == true)
								{
									bala[i]->setX(player->getX() + 5);
									bala[i]->setY(player->getY() + player->getH());
									bala[i]->setYaDisparada(false);
									bala[i]->setDibujarse(false);
									bala[i]->setLastima(true);
									bala[i]->setImage(4);
								}
							}
						}
						cantBalas = CARGADOR;
						subIndiceBala = 0;
					}
				}
				break;
			case ALLEGRO_KEY_SPACE:
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					if (cantBalas > 0)
					{
						bala[subIndiceBala]->setDibujarse(true);
						bala[subIndiceBala]->setYaDisparada(true);
						bala[subIndiceBala]->setLastima(true);
						subIndiceBala++;
						cantBalas--;
					}
				}
				break;
		}
		for (int i = 0; i < CARGADOR; i++)
		{
			if (!bala[i]->getDibujarse() && player->getVision() == 1 && bala[i]->getYaDisparada() == false)
			{
				bala[i]->setX(player->getX() + 18);
				bala[i]->setY(player->getY());
			}
			if (!bala[i]->getDibujarse() && player->getVision() == 2 && bala[i]->getYaDisparada() == false)
			{
				bala[i]->setX(player->getX() + 18);
				bala[i]->setY(player->getY() + 18);
			}
			if (!bala[i]->getDibujarse() && player->getVision() == 3 && bala[i]->getYaDisparada() == false)
			{
				bala[i]->setX(player->getX());
				bala[i]->setY(player->getY() + 5);
			}
			if (!bala[i]->getDibujarse() && player->getVision() == 4 && bala[i]->getYaDisparada() == false)
			{
				bala[i]->setX(player->getX() + 5);
				bala[i]->setY(player->getY() + player->getH());
			}
			if (bala[i]->getX()+bala[i]->getW() >= widthPantalla)
			{
				bala[i]->setDibujarse(false);
			}
			if (bala[i]->getX() <= 0)
			{
				bala[i]->setDibujarse(false);
			}
			if (bala[i]->getY() + bala[i]->getH() >= heightPantalla)
			{
				bala[i]->setDibujarse(false);
			}
			if (bala[i]->getY() <= 0)
			{
				bala[i]->setDibujarse(false);
			}

		}
		//coliciones
		
		
		if (blindado->getVida() <= 0)
		{
			blindado->setMuerto(true);
		}

		//COLICION JUGADOR CON BLINDADO
		if (blindado->getMuerto() == false)
		{
			if (player->colicionCuadrada(blindado->getW(), blindado->getH(), blindado->getX(), blindado->getY()))
			{
				//gameOver = true;
				cout << player->getVidas() << endl;
				player->setVidas(player->getVidas() - 1);
			}
		}

		//COLICION BALA CON PARED
		for (int i = 0; i < CARGADOR; i++)
		{
			if (bala[i]->colicion(pared->getW(), pared->getH(), pared->getX(), pared->getY()))
			{

			}
		}
		//COLICION TANQUE JUGADOR
		if (player->colicionCuadrada(tanqueRojo->getW(), tanqueRojo->getH(), tanqueRojo->getX(), tanqueRojo->getY()))
		{
			cout << player->getVidas() << endl;
			player->setVidas(player->getVidas() - 1);
		}
		//COLICION BLINDADO PARED
		if (pared->ColicionanConmigo(blindado->getW(), blindado->getH(), blindado->getX(), blindado->getY()))
		{
			blindado->setDiley(150);
		}
		//COLICION CAZADOR PARED
		if (pared->ColicionanConmigo(cazador1->getW(), cazador1->getH(), cazador1->getX(), cazador1->getY()))
		{
			cazador1->setDiley(150);
		}
		//COLICION JUGADOR PARED
		if (player->colicionCuadrada(pared->getW(), pared->getH(), pared->getX(), pared->getY()))
		{
			//cout <<"entre";
			velocidadJugador = 0;
		}
		else
		{
			velocidadJugador = VELOCIDADJUGADOR;
		}
		//COLICION BALA CON CAZADOR
		if (cazador1->getMuerto() == false)
		{
			//COLICION JUGADOR CON CAZADOR
			if (player->colicionCuadrada(cazador1->getW(), cazador1->getH(), cazador1->getX(), cazador1->getY()))
			{
				cout << player->getVidas() << endl;
				player->setVidas(player->getVidas() - 1);
			}
			for (int i = 0; i < CARGADOR; i++)
			{
				if (bala[i]->colicion(cazador1->getW(), cazador1->getH(), cazador1->getX(), cazador1->getY()) && bala[i]->getDibujarse() == true && bala[i]->getYaDisparada() == true)
				{
					cazador1->setMuerto(true);
					bala[i]->setDibujarse(false);
					bala[i]->setLastima(true);

				}
			}
		}
		//COLICION BALA CON BLINDADO
		if (blindado->getMuerto() == false)
		{
			for (int i = 0; i < CARGADOR; i++)
			{
				if (bala[i]->colicion(blindado->getW(), blindado->getH(), blindado->getX(), blindado->getY()) && bala[i]->getLastima() == true && bala[i]->getYaDisparada() == true)
				{
					//blindado->setMuerto(true);
					cout << "entre" << endl;
					blindado->setVida(blindado->getVida() - 4);
					bala[i]->setDibujarse(false);
					bala[i]->setLastima(false);
				}
			}
		}
		
	}
	if (!salirDefinitivo)
	{
		gameOver = false;
	}
	while (!gameOver)
	{

		al_clear_to_color(al_map_rgb(0, 0, 0));
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		switch (ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_ENTER:
				gameOver = true;
				cout << "Entre" << endl;
				break;
		}
		al_flip_display();
	}
	//  No olvidarnos de eliminar el contenido bajo el puntero de ventana,
	//  esto eliminará a la ventana de la memoria.
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_bitmap(fondo);
	delete player;
	delete tanqueRojo;
	delete pared;
	delete blindado;
	//delete[] bala;
	for (int i = 0; i < CARGADOR; i++)
	{
		if (bala[i] != NULL)
		{
			delete bala[i];
		}
	}
	delete cazador1;
	return 0;
}