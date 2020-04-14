#ifndef EXTERN_H_INCLUDED
#define EXTERN_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <time.h>
#include <string>
#include <conio.h>
#include <queue>
#include <vector>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std; // использовать пространство имен std

const float FPS = 60;
const double PI = 3.1415926;

bool key[6] = { false, false, false, false, false, false };
bool key1[6] = { false, false, false, false, false, false };

bool redraw = false;
bool doexit = false;

const int SCREEN_W = 1000;
const int SCREEN_H = 600;

int cx, cy;

double Pi = 3.1415926, one_grad = Pi / 180;

enum MYKEYS {
KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, mouse_1, mouse_2
};

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

ALLEGRO_SAMPLE *effect = NULL;

ALLEGRO_FONT *font[18];

int Mode = 1;

#endif // EXTERN_H_INCLUDED
