#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#define ALLEGRO_STATICLINK

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
#include "Image.h"

using namespace std; // использовать пространство имен std

const float FPS = 60;
const double PI = 3.1415926;

string ChetString;

bool key[6] = { false, false, false, false, false, false };
bool key1[6] = { false, false, false, false, false, false };

bool redraw = false;
bool doexit = false;

const int SCREEN_W = 1000;
const int SCREEN_H = 600;

int cx, cy;

double Pi = 3.1415926, one_grad = Pi / 180;

int MyDigetShit = 0;

enum MYKEYS {
KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, mouse_1, mouse_2
};

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

ALLEGRO_SAMPLE *effect = NULL;

ALLEGRO_FONT *font[18];

int map[200][200];
int map1[200][200];
int map2[200][200];
int UnitMap[200][200][4];
int visualMap[200][200];
//int map3[200][200];

bool Debug = false;

double offset_x = 270, offset_y = 290;

float TimeGame = 0;
const float Second60 = 1 / FPS;

int Transformirum = 1000;

int min_x, min_y, max_x, max_y;

int Max_Level_Office = 0;

int substance[16];

double pros_s[16] = {17, 14, 13, 12, 12, 12, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1};

int price_substance[16] = {50, 75, 100, 200, 400, 400, 800, 5000, 1000, 1200, 3000, 3000, 3000, 3000, 3000, 3000};

bool DigRes = false;

int openBuild[15] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 1 1 1 1 0 0

int PriceTechnology[16][5];

int openTransport[5] = {0, 0, 0, 0, 0}; // 0 0 0 0 0

int PriceTransport[5] = {500, 500, 500, 500, 500};

int time_v = 0;

int Mode = 0;

int Man = 10;

bool open_dialog[10];

bool SelectTransportJob[3] = {false, false, false};

int Technology[16][5];

char* name_build[15];

char* name_transport[5];

int price_build[15] = {500, 500, 5000, 1000, 5000, 5000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};

int Max_level[7] = {3, 5, 1, 1, 1, 1, 1};

int Man_num[15] = {10, -5, 0, -10, -10, -20, -10, -10, -10, -10, -10, -10, -10, -10, -10};

int select_x0, select_y0, select_x1, select_y1;

int capture = -1;

int Max_num_image_array[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int FreeTransport = 3;

bool CanSelect;

vector<int> SelectTransport;

int TypeChangeTransportGroup = 0;
int NumTransportChangeGroup = -1;

int countFps;

struct Build{
    int id, pos;
    int pos_x, pos_y, level, num_image, max_num_image;
    int time_m, Max_time, num, price;
    int Construction;
    int MySubstance[16], JobTransport, wearout;
    bool searchTransport;
    int xp;
    Build(int id, int pos_x, int pos_y, int max_num_image)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    ,id(id)
    ,time_m(0)
    ,Max_time(200)
    ,num(0)
    ,level(1)
    ,num_image(0)
    ,max_num_image(max_num_image)
    ,Construction(0)
    ,JobTransport(0)
    ,wearout(10)
    ,MySubstance({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})
    ,searchTransport(0)
    ,xp(60)
    {}
};

struct Transport{
    double pos_x, pos_y, speed, speed_rotated, alpha, alpha_k, w, Max_speed;
    int MyRes = -1;
    int Goal, Job, Job_build, id;
    int TimeP, AllTimeP;
    bool inSelect;
    bool patrul;
    int MapGoalX, MapGoalY;
    int xp;
    Transport(double pos_x, double pos_y, double alpha, int id)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    ,speed(0)
    ,patrul(0)
    ,speed_rotated(10 * one_grad)
    ,alpha(alpha)
    ,Goal(-1)
    ,Job(-1)
    ,w(0)
    ,Max_speed(3)
    ,id(id)
    ,MapGoalX(pos_x / 32)
    ,MapGoalY(pos_y / 32)
    ,TimeP(0)
    ,AllTimeP(20 * id)
    ,inSelect(0)
    ,xp(id * 20)
    {}
};

struct Bullet{
    double pos_x, pos_y, alpha, speed;
    int id, TimeFly;
    Bullet(double pos_x, double pos_y, double alpha, int id)
        :pos_x(pos_x)
        ,pos_y(pos_y)
        ,alpha(alpha)
        ,id(id)
        ,speed(10 * (id % 4 + 3) / 3)
        ,TimeFly(0)
        {}
};

int LastUnit;

int CountEnemyBase = 1;
int CountEnemyTransport = 0;

struct Unit{
    double pos_x, pos_y, alpha, alpha_k;
    double speed, speed_rotated;
    int id, xp;
    int Goal;
    double animation;
    bool visible;
    int timeP, maxTimeP;
    int MapGoalX, MapGoalY;
    int GoalX, GoalY;
    int Job;
    Unit(double pos_x, double pos_y, double alpha, int id)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    ,alpha(alpha)
    ,id(id)
    ,xp(0)
    ,alpha_k(0)
    ,speed(0)
    ,speed_rotated(0)
    ,Goal(-1)
    ,animation(0)
    ,visible(0)
    ,timeP(0)
    ,maxTimeP(0)
    ,MapGoalX(pos_x / 32)
    ,MapGoalY(pos_y / 32)
    ,GoalX(-1)
    ,GoalY(-1)
    ,Job(0)
    {}
};


struct EnemyBuild{
    int pos_x, pos_y, id;
    int Construction;
    int timeBuild;
    int MaxTimeBuild;
    EnemyBuild(int pos_x, int pos_y, int id)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    ,id(id)
    ,Construction(0)
    ,timeBuild(0)
    ,MaxTimeBuild(900)
    {}
};

struct playerPoint{
    int pos_x, pos_y;
    playerPoint(int pos_x, int pos_y)
    :pos_x(pos_x)
    ,pos_y(pos_y)
    {}
};

vector<EnemyBuild> enemyBuild;

vector<Unit> unit;
vector<Transport> transport;
vector<Build> build;
vector<Bullet> bullet;

vector<playerPoint> PlayerPoint;
vector<int> freeEnemyTransport;

Build Interface_build = Build(-1, 0, 0, 0);
/*
time_v ++;
int r = 24;
int x0 = 500, y0 = 300;
for(double i = 0; i < (time_v % 360) * one_grad; i += one_grad){
    cout << i << endl;
    al_draw_pixel(x0 + sin(i) * r, y0 + cos(i) * r, al_map_rgb(0, 0, 0));
}
*/

#endif // INFO_H_INCLUDED
