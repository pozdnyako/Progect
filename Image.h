#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

extern ALLEGRO_BITMAP *map_image[300];
extern ALLEGRO_BITMAP *build_image[151][10];
extern ALLEGRO_BITMAP *Construction_image[6];
extern ALLEGRO_BITMAP *transport_image[30][5];
extern ALLEGRO_BITMAP *technology_image[16][5];
extern ALLEGRO_BITMAP *interface_image[100];
extern ALLEGRO_BITMAP *unit_image[5][10];
extern ALLEGRO_BITMAP *bullet_image[10];

void InitImage();

#endif // IMAGE_H_INCLUDED
