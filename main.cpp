#include "info.h"

void PrintFPS(){
    double Time = al_get_time();
    cout << "FPS : " << 1 / (Time - time1) << endl;
    time1 = Time;
}

void InitImage(){
    player[0] = al_load_bitmap("res/image/player/player_0.png");
    thingsBitmap[0] = al_load_bitmap("res/image/things/thing_0.png");
    thingsBitmap[1] = al_load_bitmap("res/image/things/thing_1.png");
    platform = al_load_bitmap("res/image/player/platform.png");
    mapImage[0] = al_load_bitmap("res/image/map/window.png");
    mapImage[1] = al_load_bitmap("res/image/map/balcony.png");
    mapImage[2] = al_load_bitmap("res/image/map/balconyFront.png");
    mapImage[3] = al_load_bitmap("res/image/map/fault.png");
    mapImage[4] = al_load_bitmap("res/image/map/faultFront.png");
    interfaceImage[0] = al_load_bitmap("res/image/interface/interface_0.png");

    effectsImage[0][0] = al_load_bitmap("res/image/things/effects/effect_0_0.png");
    effectsImage[0][1] = al_load_bitmap("res/image/things/effects/effect_0_1.png");
    effectsImage[0][2] = al_load_bitmap("res/image/things/effects/effect_0_2.png");
    effectsImage[0][3] = al_load_bitmap("res/image/things/effects/effect_0_3.png");
    effectsImage[0][4] = al_load_bitmap("res/image/things/effects/effect_0_4.png");
    effectsImage[0][5] = al_load_bitmap("res/image/things/effects/effect_0_5.png");
    effectsImage[0][6] = al_load_bitmap("res/image/things/effects/effect_0_6.png");
    effectsImage[0][7] = al_load_bitmap("res/image/things/effects/effect_0_7.png");
    effectsImage[0][8] = al_load_bitmap("res/image/things/effects/effect_0_8.png");
    effectsImage[0][9] = al_load_bitmap("res/image/things/effects/effect_0_9.png");

    effectsImage[1][0] = al_load_bitmap("res/image/things/effects/effect_1_0.png");
    effectsImage[1][1] = al_load_bitmap("res/image/things/effects/effect_1_1.png");
    effectsImage[1][2] = al_load_bitmap("res/image/things/effects/effect_1_2.png");
    effectsImage[1][3] = al_load_bitmap("res/image/things/effects/effect_1_3.png");
    effectsImage[1][4] = al_load_bitmap("res/image/things/effects/effect_1_4.png");
    effectsImage[1][5] = al_load_bitmap("res/image/things/effects/effect_1_5.png");
    effectsImage[1][6] = al_load_bitmap("res/image/things/effects/effect_1_6.png");
    effectsImage[1][7] = al_load_bitmap("res/image/things/effects/effect_1_7.png");
    effectsImage[1][8] = al_load_bitmap("res/image/things/effects/effect_1_8.png");
    effectsImage[1][9] = al_load_bitmap("res/image/things/effects/effect_1_9.png");

    font[30] = al_load_ttf_font("res/fonts/7.ttf", 30, 0);
}

void Menu_Mode_Mouse(){

}

void Menu_Mode(){
    Menu_Mode_Mouse();
}

void Menu_Mode_Draw(){

}

void Game_Mode_Mouse(){
    if(key[mouse_1]){
        coefficient += dCoEng;
        if(coefficient > maxCo)
            coefficient = maxCo;
    }
    coefficient -= dCoNa;
    if(coefficient < minCo)
         coefficient = minCo;
}

void Game_Mode(){
    countTime ++;
    if(countTime == 150){
        countTime = 0;
        things.push_back(Thing(nowId, nowPos * 100 + 160, 80, nowSpeedX, nowSpeedY, (5 + rand()%21) * one_grad));
        nowPos = rand()%8;
        nowSpeedX = rand()%7 - 3;
        nowSpeedY = rand()%10 - 7;
        nowId = rand()%2;
    }
    if(key[KEY_RIGHT]){
        speed += aEngine;
        if(speed > MaxSpeed)
            speed = MaxSpeed;
    }
    else if(key[KEY_LEFT]){
        speed -= aEngine;
        if(speed < -MaxSpeed)
            speed = -MaxSpeed;
    }
    if(abs(speed) > aStoping)
        speed -= aStoping * speed / abs(speed);
    else if(abs(speed) <= aStoping)
        speed = 0;
    double alpha = atan((cy - pos_y) / (cx - pos_x));
    if(cy < pos_y - 35 && abs(alpha) > 0.66){
        if(cx < pos_x)
            alpha -= Pi / 2;
        else
            alpha += Pi / 2;
        alphaRotated = alpha;
    }
    if(pos_x < 70 || pos_x > SCREEN_W - 70){
        speed *= -0.75;
        if(pos_x < 70)
            pos_x = 71;
        else if(pos_x > SCREEN_W - 70)
            pos_x = SCREEN_W - 71;
    }
    for(int i = 0; i < effects.size(); i ++){
        if(!effects[i].lies){
            if(effects[i].pos_y > SCREEN_H - 64){
                effects[i].pos_y = SCREEN_H - 64;
                effects[i].lies = true;
            }
            effects[i].speedY += 0.2;
            effects[i].speedX *= 0.9;
            effects[i].pos_x += effects[i].speedX;
            effects[i].pos_y += effects[i].speedY;
            effects[i].alpha += effects[i].w;
            if(effects[i].alpha > Pi)
                effects[i].alpha -= 2 * Pi;
        }
    }
    for(int i = 0; i < things.size(); i ++){
        if(!things[i].lies){
            if(things[i].pos_y > SCREEN_H - 64 - things[i].size){
                pointBad ++;
                for(int j = 0; j < 10; j ++){
                    effects.push_back(Effect(things[i].id, rand()%10, things[i].pos_x + rand()%21 - 10, things[i].pos_y - 30 + rand()%20, rand()%21 - 10, things[i].speedY * 0.03 * (-rand()%5 - 2)));
                }
                things.erase(things.begin() + i);
            }
            else{
                if(things[i].inBasket){
                    if(things[i].pos_x > 320 && things[i].pos_x < 680 && things[i].pos_y > 350 && things[i].pos_y < 400 && things[i].speedY >= 5.4){
                        if(things[i].id == 0)
                            pointGood ++;
                        else
                            pointBad ++;
                        things[i].lies = true;
                        things[i].speedX = 0;
                        things[i].speedY = 0;
                        things[i].w = 0;
                        things[i].pos_y = 370;
                    }
                    if(things[i].pos_x > 0 && things[i].pos_x < 100 && things[i].pos_y > 600 - 64 - 125 + 30 && things[i].pos_y > 600 - 64 - 125 + 70){
                        if(things[i].id == 1)
                            pointGood ++;
                        else
                            pointBad ++;
                        things[i].lies = true;
                    }
                }
                things[i].speedY += 0.2;
                things[i].alpha += things[i].w;
                if(things[i].alpha > Pi)
                    things[i].alpha -= 2 * Pi;
                if(!things[i].inBasket && things[i].pos_x > pos_x - 65 * cos(alphaRotated) && things[i].pos_x < pos_x + 65 * cos(alphaRotated) && things[i].pos_y - things[i].size >= pos_y - 35 && things[i].speedY > 0){
                    things[i].speedX -= speed;
                    double ThingSpeed = coefficient * sqrt(things[i].speedX * things[i].speedX + things[i].speedY * things[i].speedY);
                    double ThingAlpha = atan(things[i].speedY / things[i].speedX);
                    double NewAlpha = 2 * ThingAlpha - alphaRotated;
                    things[i].speedX = ThingSpeed * sin(NewAlpha);
                    things[i].speedY = ThingSpeed * cos(NewAlpha);
                    things[i].w /= 2;
                    things[i].speedX += speed;
                    things[i].inBasket = true;
                }
                things[i].pos_x += things[i].speedX;
                things[i].pos_y += things[i].speedY;
                if(things[i].pos_x < 20){
                    things[i].pos_x = 20;
                    things[i].speedX *= -0.5;
                }
                else if(things[i].pos_x > SCREEN_W - 20){
                    things[i].pos_x = SCREEN_W - 20;
                    things[i].speedX *= -0.5;
                }
            }
        }
    }
    pos_x += speed;
}

void Game_Mode_Draw(){
    for(int i = 0; i < 8; i ++){
        al_draw_bitmap(mapImage[0], i * 100 + 120, 20, 0);;
    }
    al_draw_bitmap(mapImage[1], 300, 200, 0);
    al_draw_bitmap(mapImage[3], 0, 600 - 64 - 125, 0);
    al_draw_bitmap(player[playerImageCount], pos_x - 70, pos_y - 60, 0);
    for(int i = 0; i < things.size(); i ++){
        if(things[i].speedY >= 0 && things[i].inBasket)
            al_draw_rotated_bitmap(thingsBitmap[things[i].id], 20, 20, things[i].pos_x, things[i].pos_y, things[i].alpha, 0);
    }
    al_draw_bitmap(mapImage[2], 300, 200, 0);
    al_draw_bitmap(mapImage[4], 0, 600 - 64 - 125 + 50, 0);
    for(int i = 0; i < things.size(); i ++){
        if(things[i].speedY < 0 || !things[i].inBasket)
            al_draw_rotated_bitmap(thingsBitmap[things[i].id], 20, 20, things[i].pos_x, things[i].pos_y, things[i].alpha, 0);
    }
    for(int i = 0; i < effects.size(); i ++){
        al_draw_rotated_bitmap(effectsImage[effects[i].idthing][effects[i].id], 10, 10, effects[i].pos_x, effects[i].pos_y, effects[i].alpha, 0);
    }
    al_draw_rotated_bitmap(platform, 70, 8, pos_x, pos_y - 35, alphaRotated, 0);
    al_draw_bitmap(player[playerImageCount], pos_x - 70, pos_y - 60, 0);
    al_draw_tinted_bitmap(thingsBitmap[nowId], al_map_rgba(0, 255, 0, 100), nowPos * 100 + 140, 150, 0);
    al_draw_filled_ellipse(nowPos * 100 + 160, 80, 5, 5, al_map_rgba(0, 255, 0, 50));
    al_draw_line(nowPos * 100 + 160, 80, nowPos * 100 + 160 + nowSpeedX * 10, 80 + nowSpeedY * 10, al_map_rgba(0, 255, 0, 50), 2);
    al_draw_textf(font[30], al_map_rgb(0, 0, 0), 10, 10, 0, "Good : %i", pointGood);
    al_draw_textf(font[30], al_map_rgb(0, 0, 0), 10, 40, 0, "Bad : %i", pointBad);
    int count = (coefficient - minCo) * 50 + 1;
    for(int i = 0; i < count; i ++){
        al_draw_bitmap(interfaceImage[0], 20 + i * 11, 560, 0);
    }
}

int main(int argc, char **argv){
    srand(time(NULL));
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);

    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    cout << "Start ";
    display = al_create_display(SCREEN_W, SCREEN_H);
    //al_set_window_position(display, 0, 0);

    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }
    cout << "1 ";
    if(!al_install_mouse())
    {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }
    cout << "2 ";
    if(!al_init_image_addon())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    cout << "3 ";
    if(!al_init_primitives_addon())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    cout << "4 ";
    if(!al_install_keyboard())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    cout << "5 ";
    al_init_ttf_addon();
    al_init_font_addon();

    al_install_audio();
    al_init_acodec_addon();
    cout << "6 ";
    //al_reserve_samples(1);

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    cout << "7 ";

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    cout << "8 ";

    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_flip_display();
    al_start_timer(timer);
    //newModule(0, 100, 100, 0);
    InitImage();

    while(!doexit)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            doexit = true;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            switch(Mode){
                case 0:
                    Menu_Mode();
                break;
                case 1:
                    Game_Mode();
                    Game_Mode_Mouse();
                break;
            }
            redraw = true;
        }
        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
            cx = ev.mouse.x;
            cy = ev.mouse.y;
        }
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                        key[KEY_UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                        key[KEY_DOWN] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                        key[KEY_LEFT] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                        key[KEY_RIGHT] = true;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                        Mode = 0;
                    break;
            }
        }
        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                        //key1[KEY_UP] = false;
                        key[KEY_UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                        //key1[KEY_DOWN] = false;
                        key[KEY_DOWN] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                        //key1[KEY_LEFT] = false;
                        key[KEY_LEFT] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                        //key1[KEY_RIGHT] = false;
                        key[KEY_RIGHT] = false;
                    break;
            }
        }
        if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            key[mouse_1] = true;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            key[mouse_1] = false;
        }
        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            al_clear_to_color(al_map_rgb(255, 255, 255));
            PrintFPS();
            switch(Mode){
            case 0:
                Menu_Mode_Draw();
                break;
            case 1:
                Game_Mode_Draw();
                break;
            }
            al_flip_display();
        }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}

