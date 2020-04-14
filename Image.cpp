#include "Image.h"

ALLEGRO_BITMAP *map_image[300];
ALLEGRO_BITMAP *build_image[151][10];
ALLEGRO_BITMAP *Construction_image[6];
ALLEGRO_BITMAP *transport_image[30][5];
ALLEGRO_BITMAP *technology_image[16][5];
ALLEGRO_BITMAP *interface_image[100];
ALLEGRO_BITMAP *unit_image[5][10];
ALLEGRO_BITMAP *bullet_image[10];

void InitImage(){
    unit_image[0][0] = al_load_bitmap("res/image/Enemy/unit0_0.png");
    unit_image[0][1] = al_load_bitmap("res/image/Enemy/unit0_1.png");
    unit_image[0][2] = al_load_bitmap("res/image/Enemy/unit0_2.png");
    unit_image[0][3] = al_load_bitmap("res/image/Enemy/unit0_3.png");
    unit_image[0][4] = al_load_bitmap("res/image/Enemy/unit0_4.png");
    unit_image[0][5] = al_load_bitmap("res/image/Enemy/unit0_5.png");
    unit_image[0][6] = al_load_bitmap("res/image/Enemy/unit0_6.png");
    unit_image[0][7] = al_load_bitmap("res/image/Enemy/unit0_7.png");

    unit_image[1][0] = al_load_bitmap("res/image/Enemy/unit1_0.png");
    unit_image[1][3] = al_load_bitmap("res/image/Enemy/unit1_1_0.png");

    unit_image[2][0] = al_load_bitmap("res/image/Enemy/unit2_0.png");

    unit_image[3][0] = al_load_bitmap("res/image/Enemy/unit3_0.png");

    unit_image[4][0] = al_load_bitmap("res/image/Enemy/unit1_0.png");

    build_image[100][0] = al_load_bitmap("res/image/Enemy/mainbuild_0.png");
    build_image[101][0] = al_load_bitmap("res/image/Enemy/barracks_0.png");
    build_image[102][0] = al_load_bitmap("res/image/Enemy/tank_depo_0.png");
    build_image[103][0] = al_load_bitmap("res/image/Enemy/home_0_0.png");
    build_image[104][0] = al_load_bitmap("res/image/Enemy/home_1_0.png");
    build_image[105][0] = al_load_bitmap("res/image/Enemy/exploration_0.png");

    bullet_image[1] = al_load_bitmap("res/image/Bullet/bullet1.png");
    bullet_image[2] = al_load_bitmap("res/image/Bullet/bullet2.png");
    bullet_image[5] = al_load_bitmap("res/image/Bullet/bullet1.png");
    bullet_image[6] = al_load_bitmap("res/image/Bullet/bullet6.png");
    /*bullet_image[3] = al_load_bitmap("res/image/Bullet/bullet1.png");
    bullet_image[4] = al_load_bitmap("res/image/Bullet/bullet1.png");
    bullet_image[5] = al_load_bitmap("res/image/Bullet/bullet1.png");
*/
    map_image[11] = al_load_bitmap("res/image/rock_1.png");

    map_image[151] = al_load_bitmap("res/image/rock_3_1.png");
    map_image[152] = al_load_bitmap("res/image/rock_3_2.png");
    map_image[153] = al_load_bitmap("res/image/rock_3_3.png");
    map_image[154] = al_load_bitmap("res/image/rock_3_4.png");
    map_image[155] = al_load_bitmap("res/image/rock_3_5.png");
    map_image[156] = al_load_bitmap("res/image/rock_3_6.png");
    map_image[157] = al_load_bitmap("res/image/rock_3_7.png");
    map_image[158] = al_load_bitmap("res/image/rock_3_8.png");
    map_image[159] = al_load_bitmap("res/image/rock_3_9.png");

    transport_image[1][0] = al_load_bitmap("res/image/transport_0_0.png");
    transport_image[2][0] = al_load_bitmap("res/image/transport_1_0.png");
    transport_image[3][0] = al_load_bitmap("res/image/transport_2_0.png");

    build_image[0][0] = al_load_bitmap("res/image/home_0.png");
    build_image[0][1] = al_load_bitmap("res/image/home_0.png");
    build_image[0][2] = al_load_bitmap("res/image/home_0.png");
    build_image[0][3] = al_load_bitmap("res/image/home_0.png");
    build_image[0][4] = al_load_bitmap("res/image/home_0.png");
    build_image[0][5] = al_load_bitmap("res/image/home_0.png");
    build_image[0][6] = al_load_bitmap("res/image/home_0.png");
    build_image[0][7] = al_load_bitmap("res/image/home_0.png");
    build_image[0][8] = al_load_bitmap("res/image/home_0.png");
    build_image[0][9] = al_load_bitmap("res/image/home_0.png");

    build_image[1][0] = al_load_bitmap("res/image/home_1.png");
    build_image[1][1] = al_load_bitmap("res/image/home_1.png");
    build_image[1][2] = al_load_bitmap("res/image/home_1.png");
    build_image[1][3] = al_load_bitmap("res/image/home_1.png");
    build_image[1][4] = al_load_bitmap("res/image/home_1.png");
    build_image[1][5] = al_load_bitmap("res/image/home_1.png");
    build_image[1][6] = al_load_bitmap("res/image/home_1.png");
    build_image[1][7] = al_load_bitmap("res/image/home_1.png");
    build_image[1][8] = al_load_bitmap("res/image/home_1.png");
    build_image[1][9] = al_load_bitmap("res/image/home_1.png");

    build_image[2][0] = al_load_bitmap("res/image/home_2.png");
    build_image[2][1] = al_load_bitmap("res/image/home_2.png");
    build_image[2][2] = al_load_bitmap("res/image/home_2.png");
    build_image[2][3] = al_load_bitmap("res/image/home_2.png");
    build_image[2][4] = al_load_bitmap("res/image/home_2.png");
    build_image[2][5] = al_load_bitmap("res/image/home_2.png");
    build_image[2][6] = al_load_bitmap("res/image/home_2.png");
    build_image[2][7] = al_load_bitmap("res/image/home_2.png");
    build_image[2][8] = al_load_bitmap("res/image/home_2.png");
    build_image[2][9] = al_load_bitmap("res/image/home_2.png");

    build_image[20][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][1] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][2] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][3] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][4] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][5] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][6] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][7] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][8] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[20][9] = al_load_bitmap("res/image/warehouse_0.png");

    build_image[21][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[22][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[23][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[24][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[25][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[26][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[27][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[28][0] = al_load_bitmap("res/image/warehouse_0.png");
    build_image[29][0] = al_load_bitmap("res/image/warehouse_0.png");

    build_image[10][0] = al_load_bitmap("res/image/s_1.png");
    build_image[11][0] = al_load_bitmap("res/image/s_2.png");
    build_image[12][0] = al_load_bitmap("res/image/s_3.png");
    build_image[13][0] = al_load_bitmap("res/image/s_4.png");
    build_image[14][0] = al_load_bitmap("res/image/s_5.png");
    build_image[15][0] = al_load_bitmap("res/image/s_6.png");
    build_image[16][0] = al_load_bitmap("res/image/s_7.png");
    build_image[17][0] = al_load_bitmap("res/image/s_8.png");
    build_image[18][0] = al_load_bitmap("res/image/s_9.png");
    build_image[19][0] = al_load_bitmap("res/image/s_10.png");

    build_image[30][0] = al_load_bitmap("res/image/lab_0.png");

    build_image[40][0] = al_load_bitmap("res/image/airport_0.png");

    build_image[50][0] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][1] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][2] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][3] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][4] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][5] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][6] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][7] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][8] = al_load_bitmap("res/image/plant_0.png");
    build_image[50][9] = al_load_bitmap("res/image/plant_0.png");

    build_image[60][0] = al_load_bitmap("res/image/s_1.png");
    build_image[70][0] = al_load_bitmap("res/image/s_1.png");

    Construction_image[0] = al_load_bitmap("res/image/Construction_0.png");
    Construction_image[1] = al_load_bitmap("res/image/Construction_1.png");
    Construction_image[2] = al_load_bitmap("res/image/Construction_2.png");
    Construction_image[3] = al_load_bitmap("res/image/Construction_3.png");
    Construction_image[4] = al_load_bitmap("res/image/Construction_4.png");
    Construction_image[5] = al_load_bitmap("res/image/Construction_5.png");

    interface_image[0] = al_load_bitmap("res/image/interface/interface_0.png");
    interface_image[1] = al_load_bitmap("res/image/interface/interface_1.png");
    interface_image[2] = al_load_bitmap("res/image/interface/interface_2.png");
    interface_image[3] = al_load_bitmap("res/image/interface/interface_3.png");
    interface_image[4] = al_load_bitmap("res/image/interface/interface_4.png");
    interface_image[5] = al_load_bitmap("res/image/interface/interface_5.png");
    interface_image[6] = al_load_bitmap("res/image/interface/interface_6.png");
    interface_image[30] = al_load_bitmap("res/image/interface/interface_7.png");
    interface_image[31] = al_load_bitmap("res/image/interface/interface_8.png");
    interface_image[32] = al_load_bitmap("res/image/interface/interface_9.png");
    interface_image[33] = al_load_bitmap("res/image/interface/interface_10.png");
    interface_image[34] = al_load_bitmap("res/image/interface/interface_11.png");
    interface_image[35] = al_load_bitmap("res/image/interface/cursor.png");
    interface_image[36] = al_load_bitmap("res/image/interface/interface_12.png");
    interface_image[37] = al_load_bitmap("res/image/interface/interface_13.png");
    interface_image[38] = al_load_bitmap("res/image/interface/interface_14.png");
    interface_image[39] = al_load_bitmap("res/image/interface/interface_16.png");
    interface_image[40] = al_load_bitmap("res/image/interface/interface_15.png");
    interface_image[41] = al_load_bitmap("res/image/interface/interface_17.png");
    interface_image[42] = al_load_bitmap("res/image/interface/interface_18.png");
    interface_image[42] = al_load_bitmap("res/image/interface/interface_18.png");
    interface_image[43] = al_load_bitmap("res/image/interface/interface_19.png");
    interface_image[44] = al_load_bitmap("res/image/interface/interface_20.png");
    interface_image[45] = al_load_bitmap("res/image/interface/interface_21.png");
    interface_image[46] = al_load_bitmap("res/image/interface/interface_22.png");
    interface_image[47] = al_load_bitmap("res/image/interface/interface_23.png");
    interface_image[48] = al_load_bitmap("res/image/interface/interface_24.png");
    interface_image[49] = al_load_bitmap("res/image/interface/interface_25.png");
    interface_image[50] = al_load_bitmap("res/image/interface/interface_26.png");
    interface_image[51] = al_load_bitmap("res/image/interface/interface_27.png");
    interface_image[52] = al_load_bitmap("res/image/interface/interface_28.png");
    interface_image[53] = al_load_bitmap("res/image/interface/interface_29.png");
    interface_image[54] = al_load_bitmap("res/image/interface/interface_30.png");
    interface_image[55] = al_load_bitmap("res/image/interface/interface_31.png");
    interface_image[56] = al_load_bitmap("res/image/interface/interface_32.png");
    interface_image[57] = al_load_bitmap("res/image/interface/interface_33.png");
    interface_image[58] = al_load_bitmap("res/image/interface/interface_34.png");
    interface_image[59] = al_load_bitmap("res/image/interface/interface_35.png");

    interface_image[10] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[11] = al_load_bitmap("res/image/interface/metal/Ca.png");
    interface_image[12] = al_load_bitmap("res/image/interface/metal/Cr.png");
    interface_image[13] = al_load_bitmap("res/image/interface/metal/Cu.png");
    interface_image[14] = al_load_bitmap("res/image/interface/metal/K.png");
    interface_image[15] = al_load_bitmap("res/image/interface/metal/Li.png");
    interface_image[16] = al_load_bitmap("res/image/interface/metal/Mg.png");
    interface_image[17] = al_load_bitmap("res/image/interface/metal/Na.png");
    interface_image[18] = al_load_bitmap("res/image/interface/metal/Ni.png");
    interface_image[19] = al_load_bitmap("res/image/interface/metal/Sn.png");
    interface_image[20] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[21] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[22] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[23] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[24] = al_load_bitmap("res/image/interface/metal/Al.png");
    interface_image[25] = al_load_bitmap("res/image/interface/metal/Al.png");

    technology_image[0][0] = al_load_bitmap("res/image/interface/Technology/0_0.png");
    technology_image[0][1] = al_load_bitmap("res/image/interface/Technology/0_1.png");
    technology_image[0][2] = al_load_bitmap("res/image/interface/Technology/0_2.png");
    technology_image[0][2] = al_load_bitmap("res/image/interface/Technology/0_3.png");
    technology_image[1][0] = al_load_bitmap("res/image/interface/Technology/1_0.png");
    technology_image[1][1] = al_load_bitmap("res/image/interface/Technology/1_1.png");
    technology_image[2][2] = al_load_bitmap("res/image/interface/Technology/2_2.png");
}
