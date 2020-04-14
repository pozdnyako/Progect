#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#define ALLEGRO_STATICLINK

#include "Includes.h"

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

ALLEGRO_FONT *font[30];

int Mode = 1;

double pos_x = SCREEN_W / 2;
int pos_y = SCREEN_H - 60 - 64;
// 65, 25

ALLEGRO_BITMAP *player[10];
ALLEGRO_BITMAP *platform;
ALLEGRO_BITMAP *thingsBitmap[10];
ALLEGRO_BITMAP *mapImage[10];
ALLEGRO_BITMAP *effectsImage[10][10];
ALLEGRO_BITMAP *interfaceImage[10];

int playerImageCount = 0;
double alphaRotated = 0;
double speed = 0;
double time1 = 0;

const double aStoping = 0.03;
const double aEngine = 0.5 + aStoping;
const double MaxSpeed = 9;

int sizeForId[10] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

struct Thing{
    double pos_x, pos_y;
    double speedX, speedY;
    int id;
    double alpha;
    double w;
    int size;
    int dx, dy, dalpha;
    bool lies;
    bool inBasket;
    Thing(int id, double pos_x, double pos_y, double speedX, double speedY, double w)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    ,speedX(speedX)
    ,speedY(speedY)
    ,w(w)
    ,id(id)
    ,alpha(rand()%360 * one_grad)
    ,lies(false)
    ,inBasket(false)
    ,size(sizeForId[id])
    ,dx(0)
    ,dy(0)
    ,dalpha(0)
    {}
};

struct Effect{
    int idthing, id;
    double pos_x, pos_y, speedX, speedY;
    bool lies;
    double alpha, w;
    Effect(int idthing, int id, int pos_x, int pos_y, int speedX, int speedY)
    :idthing(idthing)
    ,id(id)
    ,pos_x(pos_x)
    ,pos_y(pos_y)
    ,speedX(speedX)
    ,speedY(speedY)
    ,lies(false)
    ,alpha((rand()%360 - 180) * one_grad)
    ,w(rand()%30 * one_grad)
    {}
};

vector<Thing> things;
vector<Effect> effects;

int countTime;
const double minCo = 0.6;
double coefficient = minCo;
const double dCoNa = 0.02;
const double dCoEng = 0.01 + dCoNa;
const double maxCo = 1;

int nowPos = rand()%8;
int nowId = rand()%2;
int nowSpeedX = rand()%7 - 3;
int nowSpeedY = 5;

int pointGood, pointBad;

int map[100][60];

// угол отражения 2b - a
//
// fault
#endif // INFO_H_INCLUDED
