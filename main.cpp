#include "info.h"

int NearFreeEnemyTransport(int pos_x, int pos_y){
    if(freeEnemyTransport.size() == 0)
        return -1;
    int min = 0, pos = 0;
    int dx = pos_x - unit[freeEnemyTransport[0]].pos_x;
    int dy = pos_y - unit[freeEnemyTransport[0]].pos_y;
    int r = dx * dx + dy * dy;
    min = r;
    for(int i = 0; i < freeEnemyTransport.size(); i ++){
        dx = pos_x - unit[freeEnemyTransport[i]].pos_x;
        dy = pos_y - unit[freeEnemyTransport[i]].pos_y;
        r = dx * dx + dy * dy;
        if(r < min){
            min = r;
            pos = i;
        }
    }
    return pos;
}

int searchNearPlayer(int pos_x, int pos_y){
    int ans = 0;
    for(int dx = -5; dx <= 5; dx ++){
        for(int dy = -5; dy <= 5; dy ++){
            if(dx + pos_x > 0 && dx + pos_x < 200 && dy + pos_y > 0 && dy + pos_y < 200){
                if(UnitMap[pos_x + dx][pos_y + dy][0] > 0)
                    ans ++;
                if(UnitMap[pos_x + dx][pos_y + dy][2] > 0)
                    ans ++;
            }
       }
    }
    return ans;
}

bool CanBuild(int pos_x, int pos_y){
    for(int dx = -1; dx <= 1; dx ++){
        for(int dy = -1; dy <= 1; dy ++){
            if(map1[pos_x + dx][pos_y + dy] != 0)
                return false;
        }
    }
    return true;
}

int searchBuild(int pos_x, int pos_y){
    vector<int> IFind;
    for(int i = 0; i < enemyBuild.size(); i ++){
        if(enemyBuild[i].id == 0)
            IFind.push_back(i);
    }
    int min, pos = -1;
    if(IFind.size() > 0){
        int dx = pos_x - enemyBuild[IFind[0]].pos_x,
        dy = pos_y - enemyBuild[IFind[0]].pos_y;
        int r = dx * dx + dy * dy;
        min = r;
        pos = 0;
    }
    for(int i = 1; i < IFind.size(); i ++){
        int dx = pos_x - enemyBuild[IFind[i]].pos_x,
        dy = pos_y - enemyBuild[IFind[i]].pos_y;
        int r = dx * dx + dy * dy;
        if(r < min){
            min = r;
            pos = i;
        }
    }
    return pos;
}

int NearBase(int pos_x, int pos_y){
    for(int dx = -5; dx <= 5; dx ++){
        for(int dy = -5; dy <= 5; dy ++){
            if(dx + pos_x > 0 && dx + pos_x < 200 && dy + pos_y > 0 && dy + pos_y < 200 &&
               UnitMap[pos_x + dx][pos_y + dy][3] - 1 >= 0 &&
               enemyBuild[UnitMap[pos_x + dx][pos_y + dy][3] - 1].id == 0){
                    return UnitMap[pos_x + dx][pos_y + dy][3] - 1;
           }
        }
    }
    return -1;
}

void Save(){
    ofstream setup("Save/Setup.cfg");
    setup << Debug << endl;
    setup << offset_x << " " << offset_y << endl;
    setup << TimeGame << endl;
    setup << Transformirum << endl;
    setup << Man << endl;
    setup << DigRes << endl;
    setup << time_v << endl;
    setup << FreeTransport << endl;
    setup << CanSelect << endl;
    setup << TypeChangeTransportGroup << endl;
    setup << NumTransportChangeGroup << endl;
    setup << LastUnit << endl;
    setup << SelectTransportJob[0] << " " << SelectTransportJob[1] << " " << SelectTransportJob[2] << endl;
    setup << CountEnemyBase << endl;

    ofstream Maps("Save/Map.cfg");
    for(int i = 0; i < 200; i ++){
        for(int j = 0; j < 200; j ++){
            Maps << map[i][j] << " " << map1[i][j] << " " << map2[i][j] << " " << UnitMap[i][j][0] << " " << UnitMap[i][j][1] << " " << UnitMap[i][j][2] << " " << UnitMap[i][j][3] << " " << visualMap[i][j] << endl;
        }
    }

    ofstream Open("Save/Open.cfg");
    for(int i = 0; i < 15; i ++){
        Open << openBuild[i] << " ";
    }
    for(int i = 0; i < 5; i ++){
        Open << openTransport[i] << " ";
    }
    for(int i = 0; i < 16; i ++){
        for(int j = 0; j < 5; j ++){
            Open << Technology[i][j] << " ";
        }
        Open << endl;
    }

    ofstream transportOut("Save/Transport.cfg");
    transportOut << transport.size() << endl;
    for(int i = 0; i < transport.size(); i ++){
        transportOut << transport[i].pos_x << " " << transport[i].pos_y << " " << transport[i].speed << " " << transport[i].speed_rotated << " " <<
        transport[i].alpha << " " << transport[i].alpha_k << " " << transport[i].w << " " << transport[i].Max_speed << " " << transport[i].MyRes << " " <<
        transport[i].Goal << " " << transport[i].Job << " " << transport[i].Job_build << " " << transport[i].id << " " << transport[i].TimeP << " " <<
        transport[i].AllTimeP << " " << transport[i].inSelect << " " << transport[i].patrul << " " << transport[i].MapGoalX << " " << transport[i].MapGoalY << " " <<
        transport[i].xp << endl;
    }
    transportOut << SelectTransport.size();
    for(int i = 0; i < SelectTransport.size(); i ++){
        transportOut << SelectTransport[i] << " ";
    }

    ofstream buildOut("Save/Build.cfg");
    buildOut << build.size() << endl;
    for(int i = 0; i < build.size(); i ++){
        buildOut << build[i].id << " " << build[i].pos << " " << build[i].pos_x << " " << build[i].pos_y << " " << build[i].level << " " << build[i].num_image << " " <<
        build[i].max_num_image << " " << build[i].time_m << " " << build[i].Max_time << " " << build[i].num << " " << build[i].price << " " << build[i].Construction << " " <<
        build[i].JobTransport << " " << build[i].wearout << " " << build[i].searchTransport << " " << build[i].xp << endl;
        for(int j = 0; j < 16; j ++){
            buildOut << build[i].MySubstance[j] << " ";
        }
        buildOut << endl;
    }
    buildOut << Interface_build.id << " " << Interface_build.pos << " " << Interface_build.pos_x << " " << Interface_build.pos_y << " " << Interface_build.level << " " << Interface_build.num_image << " " <<
    Interface_build.max_num_image << " " << Interface_build.time_m << " " << Interface_build.Max_time << " " << Interface_build.num << " " << Interface_build.price << " " << Interface_build.Construction << " " <<
    Interface_build.JobTransport << " " << Interface_build.wearout << " " << Interface_build.searchTransport << " " << Interface_build.xp << endl;

    ofstream enemyOut("Save/Enemy.cfg");
    enemyOut << unit.size() << endl;
    for(int i = 0; i < unit.size(); i ++){
        enemyOut << unit[i].pos_x << " " << unit[i].pos_y << " " << unit[i].alpha << " " << unit[i].alpha_k << " " << unit[i].speed << " " << unit[i].speed_rotated << " " <<
        unit[i].id << " " << unit[i].xp << " " << unit[i].Goal << " " << unit[i].timeP << " " << unit[i].MapGoalX << " " << unit[i].MapGoalY << " " <<
        unit[i].GoalX << " " << unit[i].GoalY << " " << unit[i].Job << endl;
    }
    enemyOut << enemyBuild.size() << endl;
    for(int i = 0; i < enemyBuild.size(); i ++){
        enemyOut << enemyBuild[i].pos_x << " " << enemyBuild[i].pos_y << " " << enemyBuild[i].id << " " << enemyBuild[i].Construction << " " <<
        enemyBuild[i].timeBuild << " " << enemyBuild[i].MaxTimeBuild << endl;
    }

    ofstream bulletOut("Save/Bullet.cfg");
    bulletOut << bullet.size() << endl;
    for(int i = 0; i < bullet.size(); i ++){
        bulletOut << bullet[i].pos_x << " " << bullet[i].pos_y << " " << bullet[i].alpha << " " << bullet[i].speed << " " << bullet[i].id << " " << bullet[i].TimeFly << endl;
    }
}

int searchBase(int pos_x, int pos_y){
    vector<int> IFind;
    for(int i = 0; i < enemyBuild.size(); i ++){
        if(enemyBuild[i].id == 0){
            IFind.push_back(i);
        }
    }
    int min, pos = -1;
    if(IFind.size() > 0){
        int dx = pos_x - build[IFind[0]].pos_x,
        dy = pos_y - build[IFind[0]].pos_y;
        int r = dx * dx + dy * dy;
        min = r;
        pos = 0;
    }
    for(int i = 1; i < IFind.size(); i ++){
        int dx = pos_x - build[IFind[i]].pos_x,
        dy = pos_y - build[IFind[i]].pos_y;
        int r = dx * dx + dy * dy;
        if(r < min){
            min = r;
            pos = i;
        }
    }
    return pos;
}

struct Point{
    int x, y;
    Point(int x, int y)
    :x(x)
    ,y(y)
    {}
};

Point LastDfs1(-1, -1);

int dfs(int x, int y, int pos_x0, int pos_y0){
    LastDfs1 = Point(x, y);
    queue<Point> q;
    q.push(Point(x, y));
    map2[x][y] = 1;
    while(!q.empty()){
        Point point = q.front();
        q.pop();
        if((point.x == pos_x0 && point.y == pos_y0) || (pos_x0 - x) * (pos_x0 - x) + (pos_y0 - y) * (pos_y0 - y) > 10)
            break;
        for(int dx = -1; dx <= 1; dx ++){
            for(int dy = -1; dy <= 1; dy ++){
                if(dx + point.x < 200 && dx + point.x >= 0 && dy + point.y >= 0 && dy + point.y < 200){
                    if(dx * dx + dy * dy == 1){
                        if(map2[point.x + dx][point.y + dy] == 0 && UnitMap[point.x + dx][point.y + dy][1] == 0){
                            map2[point.x + dx][point.y + dy] = map2[point.x][point.y] + 1;
                            q.push(Point(point.x + dx, point.y + dy));
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void deleteInMap2(){
    int pos_x = LastDfs1.x;
    int pos_y = LastDfs1.y;
    //cout << UnitMap[pos_x][pos_y][2] << endl;
    for(int dx = -10; dx <= 10; dx ++){
        for(int dy = -10; dy <= 10; dy ++){
            if(dx + pos_x >= 0 && dx + pos_x < 200 && dy + pos_y >= 0 && dy + pos_y < 200){
                if(map2[dx + pos_x][dy + pos_y] != -1)
                    map2[dx + pos_x][dy + pos_y] = 0;
            }
        }
    }
}

int searchTransport(int pos_x, int pos_y){
    vector <int> IFind;
    for(int dx = -6; dx <= 6; dx ++){
        for(int dy = -6; dy <= 6; dy ++){
            if(dx + pos_x >= 0 && dx + pos_x < 200 && dy + pos_y >= 0 && dy + pos_y < 200){
                if(UnitMap[pos_x + dx][pos_y + dy][0] > 0)
                    IFind.push_back(UnitMap[pos_x + dx][pos_y + dy][0] - 1);
            }
        }
    }
    int min, pos = -1;
    if(IFind.size() > 0){
        int dx = pos_x * 32 - transport[IFind[0]].pos_x,
        dy = pos_y * 32 - transport[IFind[0]].pos_y;
        int r = dx * dx + dy * dy;
        min = r;
        pos = 0;
    }
    for(int i = 1; i < IFind.size(); i ++){
        int dx = pos_x * 32 - transport[IFind[i]].pos_x,
        dy = pos_y * 32 - transport[IFind[i]].pos_y;
        int r = dx * dx + dy * dy;
        if(r < min){
            min = r;
            pos = i;
        }
    }
    return pos;
}

void InitEnemy(){
    int EnemyBasePosX = rand()%90 + 100;
    int EnemyBasePosY = rand()%90 + 100;

    enemyBuild.push_back(EnemyBuild(EnemyBasePosX, EnemyBasePosY, 0));
    while(map1[enemyBuild[0].pos_x][enemyBuild[0].pos_y] != 0){
        enemyBuild[0].pos_x += rand()%3 - 1;
        enemyBuild[0].pos_y += rand()%3 - 1;
    }
    enemyBuild[0].Construction = 6;
    map2[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
    map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
    UnitMap[enemyBuild.back().pos_x][enemyBuild.back().pos_y][3] = enemyBuild.size();

    enemyBuild.push_back(EnemyBuild(EnemyBasePosX, EnemyBasePosY, 1));

    while(map1[enemyBuild[1].pos_x][enemyBuild[1].pos_y] != 0 || map2[enemyBuild[1].pos_x][enemyBuild[1].pos_y] == -1){
        enemyBuild[1].pos_x += rand()%3 - 1;
        enemyBuild[1].pos_y += rand()%3 - 1;
    }
    map2[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
    map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
    enemyBuild[1].Construction = 0;
    UnitMap[enemyBuild.back().pos_x][enemyBuild.back().pos_y][3] = enemyBuild.size();
}

void DrawEnemy(int min_x, int min_y, int max_x, int max_y){
    for(int i = 0; i < enemyBuild.size(); i ++){
        //cout << enemyBuild[i].id + 100 << endl;
        if(enemyBuild[i].pos_x >= min_x && enemyBuild[i].pos_x <= max_x
        && enemyBuild[i].pos_y >= min_y && enemyBuild[i].pos_y <= max_y){
            al_draw_bitmap(build_image[enemyBuild[i].id + 100][0], enemyBuild[i].pos_x * 32 - offset_x, enemyBuild[i].pos_y * 32 - offset_y, 0);
            if(enemyBuild[i].Construction < 6)
                al_draw_bitmap(Construction_image[enemyBuild[i].Construction], enemyBuild[i].pos_x * 32 - offset_x, enemyBuild[i].pos_y * 32 - offset_y, 0);
        }
    }
    for(int i = 0; i < unit.size(); i ++){
        unit[i].visible = false;
        if(unit[i].pos_x >= offset_x && unit[i].pos_x <= offset_x + 800 &&
           unit[i].pos_y >= offset_y && unit[i].pos_y <= offset_y + 600){
            unit[i].visible = true;
            //cout << unit[i].id << " " << unit[i].animation << endl;
            al_draw_rotated_bitmap(unit_image[unit[i].id][(int)unit[i].animation], 16, 16, unit[i].pos_x - offset_x, unit[i].pos_y - offset_y, unit[i].alpha, 0);
            if(unit[i].id == 1){
                al_draw_rotated_bitmap(unit_image[unit[i].id][(int)unit[i].animation + 3], 16, 16, unit[i].pos_x - offset_x, unit[i].pos_y - offset_y, unit[i].alpha_k, 0);
            }
        }
    }
}

int toUnit(int x, int y){
    if(UnitMap[x / 32][y / 32][1] > 0)
        return UnitMap[x / 32][y / 32][1] - 1;
    return -1;
}

int ColNum(int n){
    int ans = 0;
    while(n > 0){
        n /= 10;
        ans ++;
    }
    return ans;
}

double LengthLine(double x0, double y0, double x1, double y1){
    double dx = x0 - x1,
           dy = y0 - y1;
    return sqrt(dx * dx + dy * dy);
}

void NewUnit(double pos_x, double pos_y, double alpha, int id){
    unit.push_back(Unit(pos_x, pos_y, alpha, id));
    switch(id){
        case 0:
            unit.back().xp = 3;
            unit.back().speed = 0.5;
            unit.back().speed_rotated = 2 * one_grad;
            unit.back().maxTimeP = 20;
            unit.back().Job = 2;
        break;
        case 1:
            unit.back().xp = 10;
            unit.back().speed = 1;
            unit.back().speed_rotated = 8 * one_grad;
            unit.back().maxTimeP = 120;
        break;
        case 2:
            unit.back().xp = 5;
            unit.back().speed = 0;
            unit.back().speed_rotated = 6 * one_grad;
            unit.back().maxTimeP = 0;
        break;
        case 3:
            unit.back().xp = 6;
            unit.back().speed = 10;
            unit.back().speed_rotated = 10 * one_grad;
            freeEnemyTransport.push_back(unit.size() - 1);
        break;
    }
    UnitMap[(int)(pos_x / 32)][(int)(pos_y / 32)][1] = unit.size();
}

int have_unit_in_this_palce(int x, int y){
    LastUnit = UnitMap[x / 32][y / 32][1] - 1;
    if(UnitMap[x / 32][y / 32][1] > 0)
        return UnitMap[x / 32][y / 32][1] - 1;
    else
        return -1;
}

void Chet(int Unicode){
    //cout << Unicode << " ";
    if(Unicode <= 26){
        string UnicodeString = " ";
        UnicodeString[0] = Unicode + 'a' - 1;
        ChetString.insert(ChetString.size(), UnicodeString);
        system("cls");
        //cout << endl << ChetString;
    }
    else if(Unicode == 75 || Unicode == 67){
        if(ChetString == "transfi")
            Transformirum += 1000;
        else if(ChetString == "man")
            Man += 50;
        else if(ChetString == "res"){
            for(int i = 0; i < 16; i ++){
                substance[i] += 10;
            }
        }
        else if(ChetString == "all"){
            for(int i = 0; i < 16; i ++){
                substance[i] += 100;
            }
            Man += 1000;
            Transformirum += 10000;
        }
        else if(ChetString == "transport"){
            transport.push_back(Transport((build[0].pos_x + rand() % 5 - 2) * 32, (build[0].pos_y + rand() % 5 - 2) * 32, (rand()%360 - 180) * one_grad, 2));
        }
        ChetString.clear();
    }
}

int HaveConstruction(){
    for(int i = 0; i < build.size(); i ++){
        if(build[i].Construction < 6)
            return i;
    }
    return -1;
}

int ThisBuildTransportHaveJob(int Job, int pos){
    int num = 0;
    for(int i = 0; i < transport.size(); i ++){
        if(transport[i].Job_build == pos && transport[i].Job == Job)
            num ++;
    }
    return num;
}

void LevelUp(int pos){
    if(ThisBuildTransportHaveJob(1, pos) == 1){
        build[pos].Max_time -= build[pos].level * 5;
        Man += Man_num[build[pos].id] * build[pos].level;
    }
}

int Can_generation(int size, int i, int j){
    for(int x = 0; x < size && x + i < 200; x ++){
        for(int y = 0; y < size && y + j < 200; y ++){
            if(map[x + i][y + j] != 0)
                return false;
        }
    }
    return true;
}

int FreeMineRes(int num){
    for(int i = 0; i < 16; i ++){
        if(build[num].MySubstance[i] > 0)
            return i;
    }
    return -1;
}

int generation(){
    for(int j = 0; j < 200; j ++){
        for(int i = 0; i < 200; i ++){
            //map[i][j] = (rand()%5) * 10 + rand()%3;
            if(map[i][j] == 0){
                if(i > 0 && j > 0 && (map[i - 1][j] > 11 || map[i][j - 1] > 11 || map[i - 1][j - 1] > 11))
                    map[i][j] = 11;
                else if(rand() % 5 == 0){
                    int size = rand() % 3 + 1;
                    if(size > 2){
                        while(!Can_generation(size, i, j) && size >= 2)
                            size --;
                    }
                    if(size == 2)
                        size = 1;
                    int num = 0;
                    if(size > 2 && (i < 98 || i > 102 || j < 98 || j > 102)){
                        int num = 0;
                        for(int y = 0; y < size && y + i < 200; y ++){
                            for(int x = 0; x < size && x + i < 200; x ++){
                                num ++;
                                map2[i + x][j + y] = -1;
                                map[i + x][j + y] = size * 50 + num;
                                if(x == 0 || x == size - 1 || y == 0 || y == size - 1)
                                    map1[i + x][j + y] = 1;
                                else{
                                    double z = rand() % 100;
                                    double ans = 0;
                                    for(int q = 0; q < 16; q ++){
                                        ans += pros_s[q];
                                        if(ans >= z){
                                            map1[i + x][j + y] = q + 2;
                                            //cout << i + x << " " << j + y << " " << map1[(int)(i + x)][(int)(j + y)] << endl;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                        map[i][j] = 11;
                }
                else
                        map[i][j] = 11;
            }
        }
    }
}

bool On_build(double pos_x, double pos_y, int Num){
    return build[Num].pos_x * 32 < pos_x && build[Num].pos_x * 32 + 32 > pos_x &&
       build[Num].pos_y * 32 < pos_y && build[Num].pos_y * 32 + 32 > pos_y;
}

int Near_warehouse(double pos_x, double pos_y){
    double Min = 100000000000;
    int pos = -1;
    for(int i = 0; i < build.size(); i ++){
        if(build[i].id == 2 && build[i].Construction == 6 &&
           sqrt((build[i].pos_x * 32 - pos_x) * (build[i].pos_x * 32 - pos_x) + (build[i].pos_y * 32 - pos_y) * (build[i].pos_y * 32 - pos_y)) < Min){
           Min = sqrt((build[i].pos_x * 32 - pos_x) * (build[i].pos_x * 32 - pos_x) + (build[i].pos_y * 32 - pos_y) * (build[i].pos_y * 32 - pos_y));
           pos = i;
           }
    }
    return pos;
}

double Alpha(double dx, double dy){
    double alpha;
    if(dy != 0){
        alpha = -atan(dx / dy);
        if(dy < 0)
            alpha = alpha + Pi;
        else if(dx > 0){
            alpha = alpha + 2 * Pi;
        }
    }
    else{
        alpha = Pi / 2;
        if(dx <= 0)
            alpha += Pi;
    }
    return alpha;
}

int already_busy(int x, int y){
    for(int i = 0; i < build.size(); i ++){
        if(x >= build[i].pos_x * 32 && x <= build[i].pos_x * 32 + 32
        && y >= build[i].pos_y * 32 && y <= build[i].pos_y * 32 + 32)
            return i;
    }
    return -1;
}

bool all_false_open_dialog(){
    for(int i = 0; i < 10; i ++){
        if(open_dialog[i] == true)
            return false;
    }
    return true;
}

int MouseToGameField(){
    CanSelect = true;
    if(cx <= 200 && cy >= 400){
        if(cx <= 15)
            offset_x = 40;
        else if(cx >= 185)
            offset_x = 5360;
        else
            offset_x = cx * 32 - 460;

        if(cy <= 410)
            offset_y = 40;
        else if(cy >= 570)
            offset_y = 5760;
        else{
            offset_y = (cy - 390) * 32 - 600;
        }
    }
    if(SelectTransport.size() > 0){
        if(SelectTransportJob[0]){
            int GoalUnit = toUnit(cx + offset_x, cy + offset_y);
            if(GoalUnit > -1){
                for(int i = 0; i < SelectTransport.size(); i ++){
                    transport[SelectTransport[i]].Job = 1;
                    transport[SelectTransport[i]].Goal = GoalUnit;
                }
            }
        }
        else if(SelectTransportJob[1] || SelectTransportJob[2]){
            for(int i = 0;  i < SelectTransport.size(); i ++){
                transport[SelectTransport[i]].Job = 2;
                int pos_x1 = (cx + offset_x) / 32, pos_y1 = (cy + offset_y) / 32;
                int direction = rand()%8;
                while(UnitMap[pos_x1][pos_y1][0] != 0){
                    if(pos_x1 <= 0 || pos_x1 >= 199 || pos_y1 <= 0 || pos_y1 >= 199){
                        direction += 4;
                        direction %= 8;
                    }
                    switch(direction){
                        case 0:
                            pos_x1 --;
                            if(UnitMap[pos_x1][pos_y1][0] > 0)
                                pos_y1 --;
                            break;
                        case 1:
                            pos_y1--;
                            break;
                        case 2:
                            pos_x1 ++;
                            if(UnitMap[pos_x1][pos_y1][0] > 0)
                                pos_y1 --;
                            break;
                        case 3:
                            pos_x1 ++;
                            break;
                        case 4:
                            pos_x1 ++;
                            if(UnitMap[pos_x1][pos_y1][0] > 0)
                                pos_y1 ++;
                            break;
                        case 5:
                            pos_y1 ++;
                            break;
                        case 6:
                            pos_x1 --;
                            if(UnitMap[pos_x1][pos_y1][0] > 0)
                                pos_y1 ++;
                            break;
                        case 7:
                            pos_x1 --;
                            break;
                    }
                }
                //cout << pos_x1 << " " << pos_y1 << endl;
                UnitMap[pos_x1][pos_y1][0] = 1;
                transport[SelectTransport[i]].MapGoalX = pos_x1;
                transport[SelectTransport[i]].MapGoalY = pos_y1;
            }
            for(int i = 0;  i < SelectTransport.size(); i ++){
                UnitMap[transport[SelectTransport[i]].MapGoalX][transport[SelectTransport[i]].MapGoalY][0] = 0;
            }
        }
        return 0;
    }
    select_x0 = cx + offset_x;
    select_y0 = cy + offset_y;
    select_x1 = cx + offset_x;
    select_y1 = cy + offset_y;
    int my = already_busy(cx + offset_x, cy + offset_y);
    //cout << my << endl << endl;
    if(my > -1){
        Interface_build = build[my];
        Interface_build.pos = my;
    }
}

void new_substance(int num){
    if(rand()% (2 - DigRes) == 0 && map1[build[num].pos_x][build[num].pos_y] - 2 >= 0){
        build[num].MySubstance[map1[build[num].pos_x][build[num].pos_y] - 2] = rand()%3 + 1;
    }
}

int have_free_transport(){
    for(int i = 0; i < transport.size(); i ++){
        if(transport[i].Job == -1 && transport[i].id == 1){
            return i;
        }
    }
    return -1;
}

void FreeToWork(int pos){
    for(int i = 0; i < transport.size(); i ++){
        if(transport[i].Job == -1 && transport[i].id == 1){
            transport[i].Job = 1;
            transport[i].Job_build = pos;
            transport[i].Goal = pos;
            double dx = build[transport[i].Goal].pos_x * 32 + 16 - transport[i].pos_x,
            dy = build[transport[i].Goal].pos_y * 32 + 16 - transport[i].pos_y;
            transport[i].alpha_k = Alpha(-dx, -dy);
            build[pos].JobTransport ++;
            FreeTransport --;
        }
    }
}


void Init(){
    cout << "Start Init() " << endl;
    effect = al_load_sample("res/1.wav");

    font[18] = al_load_ttf_font("res/fonts/11.ttf", 18, 0);
    font[16] = al_load_ttf_font("res/fonts/11.ttf", 16, 0);
    font[12] = al_load_ttf_font("res/fonts/11.ttf", 12, 0);
    font[10] = al_load_ttf_font("res/fonts/11.ttf", 10, 0);
    font[22] = al_load_ttf_font("res/fonts/11.ttf", 22, 0);
    font[8] = al_load_ttf_font("res/fonts/11.ttf", 8, 0);

    font[9] = al_load_ttf_font("res/fonts/3.ttf", 9, 0);
    font[17] = al_load_ttf_font("res/fonts/3.ttf", 17, 0);

    cout << "load font completed! " << endl;

    //map_image[50] = al_load_bitmap("res/image/rock_1_1.png");
    InitImage();

    cout << "load image completed! " << endl;

    generation();

    cout << "generation completed! " << endl;

    name_build[0] = "Home";
    name_build[1] = "Mine";
    name_build[2] = "Warehouse";
    name_build[3] = "Lab";
    name_build[4] = "Airport";
    name_build[5] = "Plant";
    name_build[6] = "Haven't got";

    name_transport[0] = "Trins";
    name_transport[1] = "Light Electro";
    name_transport[2] = "Medium Electro";
    name_transport[3] = "Heavy Electro";
    name_transport[4] = "Titan";

    cout << "load name completed!" << endl;

    build.push_back(Build(0, 25, 25, Max_num_image_array[0]));
    while(map1[build[0].pos_x][build[0].pos_y] != 0){
        build[0].pos_x += rand()%3 - 1;
        build[0].pos_y += rand()%3 - 1;
    }
    build[0].Construction = 6;
    map2[build.back().pos_x][build.back().pos_y] = -1;
    UnitMap[build.back().pos_x][build.back().pos_y][2] = build.size();

    build.push_back(Build(2, 25 + rand() % 3 - 1, 25 + rand() % 3 + 1, Max_num_image_array[2]));
    while(map1[build[1].pos_x][build[1].pos_y] != 0 && !(build[1].pos_x == build[0].pos_x && build[1].pos_y == build[0].pos_y)){
        build[1].pos_x += rand()%3 - 1;
        build[1].pos_y += rand()%3 - 1;
    }
    build[1].Construction = 6;
    map2[build.back().pos_x][build.back().pos_y] = -1;
    UnitMap[build.back().pos_x][build.back().pos_y][2] = build.size();

    cout << "load build comleted!" << endl;

    transport.push_back(Transport((build[0].pos_x + rand() % 5 - 2) * 32, (build[0].pos_y + rand() % 5 - 2) * 32, (rand()%360 - 180) * one_grad, 1));
    transport.push_back(Transport((build[0].pos_x + rand() % 5 - 2) * 32, (build[0].pos_y + rand() % 5 - 2) * 32, (rand()%360 - 180) * one_grad, 1));
    transport.push_back(Transport((build[0].pos_x + rand() % 5 - 2) * 32, (build[0].pos_y + rand() % 5 - 2) * 32, (rand()%360 - 180) * one_grad, 1));

    for(int i = 0; i < 50; i ++){
        int x = (rand()%180 + 10) * 32, y = (rand()%180 + 10) * 32;
        if(map1[x / 32][y / 32] == 0){
            NewUnit(x, y, (rand()%360 - 180) * one_grad, 0);
            if(rand()%2 == 0)
                NewUnit(x + 32, y + 32, 0, 3);
        }
    }
    //PlayerPoint.push_back(playerPoint(20, 20));
    //PlayerPoint.push_back(playerPoint(110, 110));

    Interface_build = build[0];
    Interface_build.pos = 0;
    Max_Level_Office = 1;

    cout << "load map obgect completed!" << endl;

    for(int i = 0; i < 16 ;i ++){
        Technology[i][0] = true;
        PriceTechnology[i][0] = 5;
    }

    InitEnemy();

    cout << "init completed! ";

    //substance[0] = 10;
    //substance[1] = 10;
}

void Enemy1Logic(int i){
    if(unit[i].Goal <= -1){
        unit[i].animation = 0;
        if(build.size() > 0){
            int Goal = searchBuild((unit[i].pos_x) / 32, (unit[i].pos_y) / 32);
            if(Goal >= 0){
                unit[i].Goal = Goal;
                //cout << (unit[i].pos_x + 16) / 32 << " " << (unit[i].pos_y + 16) / 32 << " " << unit[i].Goal << endl;
                //cout << i << " " << unit[i].Goal << endl;
            }
        }
    }
    else if(LengthLine(build[unit[i].Goal].pos_x * 32 + 16, build[unit[i].Goal].pos_y * 32 + 16, unit[i].pos_x, unit[i].pos_y) > 70){
        if(LengthLine(build[unit[i].Goal].pos_x * 32 + 16, build[unit[i].Goal].pos_y * 32 + 16, unit[i].pos_x, unit[i].pos_y) < 320){
            if(LengthLine(unit[i].MapGoalX * 32 + 16, unit[i].MapGoalY * 32 + 16, unit[i].pos_x, unit[i].pos_y) > 8){
                double dx = unit[i].MapGoalX * 32 + 16 - unit[i].pos_x,
                dy = unit[i].MapGoalY * 32 + 16 - unit[i].pos_y;

                if(unit[i].alpha_k == unit[i].alpha){
                    unit[i].pos_x += sin(Pi - unit[i].alpha) * unit[i].speed;
                    unit[i].pos_y += cos(Pi - unit[i].alpha) * unit[i].speed;
                }

                if(dx * dx + dy * dy < unit[i].speed * unit[i].speed){
                    unit[i].pos_x = unit[i].MapGoalX * 32 + 16;
                    unit[i].pos_y = unit[i].MapGoalY * 32 + 16;
                }

                unit[i].alpha_k = Alpha(-dx, -dy);

                if(abs(unit[i].alpha - unit[i].alpha_k) <= unit[i].speed_rotated || abs(unit[i].alpha - 2 * Pi - unit[i].alpha_k) <= unit[i].speed_rotated)
                    unit[i].alpha = unit[i].alpha_k;
                else{
                    if(unit[i].alpha_k > unit[i].alpha){
                        if(unit[i].alpha_k - unit[i].alpha > Pi)
                            unit[i].alpha -= unit[i].speed_rotated;
                        else if(unit[i].alpha_k - unit[i].alpha < Pi)
                            unit[i].alpha += unit[i].speed_rotated;
                    }
                    else{
                        if(unit[i].alpha - unit[i].alpha_k > Pi)
                            unit[i].alpha -= unit[i].speed_rotated;
                        else if(unit[i].alpha - unit[i].alpha_k < Pi)
                            unit[i].alpha += unit[i].speed_rotated;
                    }
                }

                if(unit[i].alpha > 2 * Pi)
                    unit[i].alpha -= 2 * Pi;
                else if(unit[i].alpha < 0)
                    unit[i].alpha += 2 * Pi;
                /* ---------------- АНИМАЦИЯ ---------------
                if(unit[i].visible){
                    if(unit[i].animation < 5.6)
                        unit[i].animation += 0.4;
                    else if(unit[i].animation >= 5.6)
                        unit[i].animation = 0;
                }
                */
            }
            else if(LengthLine(build[unit[i].Goal].pos_x * 32 + 16, build[unit[i].Goal].pos_y * 32 + 16, unit[i].pos_x, unit[i].pos_y) < 70){
                /* ---------------- АНИМАЦИЯ ---------------
                if(unit[i].animation < 7.6 && unit[i].animation >= 6)
                    unit[i].animation += 0.4;
                else
                    unit[i].animation = 0;
                */
                double dx = build[unit[i].Goal].pos_x * 32 + 16 - unit[i].pos_x,
                dy = build[unit[i].Goal].pos_y * 32 + 16 - unit[i].pos_y;
                unit[i].alpha_k = Alpha(-dx, -dy);

                if(unit[i].timeP >= unit[i].maxTimeP){
                    bullet.push_back(Bullet(unit[i].pos_x, unit[i].pos_y, unit[i].alpha_k, unit[i].id + 5));
                    unit[i].timeP = 0;
                    //unit[i].animation = 6;
                }
            }
            else{
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy ++){
                        if(dx * dx + dy * dy == 1){
                            if(map2[build[unit[i].Goal].pos_x + dx][build[unit[i].Goal].pos_x + dy] == 0){
                                dfs(build[unit[i].Goal].pos_x + dx, build[unit[i].Goal].pos_y + dy, unit[i].pos_x / 32, unit[i].pos_y / 32);
                                break;
                            }
                        }
                    }
                }
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy ++){
                        if(dx * dx + dy * dy == 1){
                            if(map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] > 0 &&
                               map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] < map2[(int)(unit[i].pos_x / 32)][(int)(unit[i].pos_y / 32)]){
                                unit[i].MapGoalX = dx + unit[i].pos_x / 32;
                                unit[i].MapGoalY = dy + unit[i].pos_y / 32;
                                break;
                            }
                        }
                    }
                }
                deleteInMap2();
            }
        }
        else{
            unit[i].Goal = -1;
            unit[i].MapGoalX = unit[i].pos_x / 32;
            unit[i].MapGoalY = unit[i].pos_y / 32;
        }
    }
}

int Enemy0Logic(int i){
    if(unit[i].Goal <= -1){
        unit[i].animation = 0;
        if(transport.size() > 0){
            int Goal = searchTransport((unit[i].pos_x + 16) / 32, (unit[i].pos_y + 16) / 32);
            if(Goal > -1){
                unit[i].Goal = Goal;
                unit[i].Job = 1;
                PlayerPoint.push_back(playerPoint(transport[unit[i].Goal].pos_x / 32, transport[unit[i].Goal].pos_y / 32));
            }
        }
    }

    if(unit[i].Job == 1){
        if(LengthLine(transport[unit[i].Goal].pos_x, transport[unit[i].Goal].pos_y, unit[i].pos_x, unit[i].pos_y) > 70){
            if(LengthLine(transport[unit[i].Goal].pos_x, transport[unit[i].Goal].pos_y, unit[i].pos_x, unit[i].pos_y) < 320){
                if(LengthLine(unit[i].MapGoalX * 32 + 16, unit[i].MapGoalY * 32 + 16, unit[i].pos_x, unit[i].pos_y) > 8 && map2[unit[i].MapGoalX][unit[i].MapGoalY] != -1){
                    double dx = unit[i].MapGoalX * 32 + 16 - unit[i].pos_x,
                    dy = unit[i].MapGoalY * 32 + 16 - unit[i].pos_y;
                    unit[i].alpha = Alpha(-dx, -dy);
                    unit[i].pos_x += sin(Pi - unit[i].alpha) * unit[i].speed;
                    unit[i].pos_y += cos(Pi - unit[i].alpha) * unit[i].speed;
                    if(unit[i].visible){
                        if(unit[i].animation < 5.6)
                            unit[i].animation += 0.4;
                        else if(unit[i].animation >= 5.6)
                            unit[i].animation = 0;
                    }
                    if(UnitMap[(int)unit[i].pos_x / 32][(int)unit[i].pos_y / 32][1] > 0){
                        bool CandeleteInMap2 = false;
                        if(map2[(int)transport[unit[i].Goal].pos_x / 32][(int)transport[unit[i].Goal].pos_y / 32] > -1){
                            map2[(int)transport[unit[i].Goal].pos_x / 32][(int)transport[unit[i].Goal].pos_y / 32] = 1;
                            dfs(transport[unit[i].Goal].pos_x / 32, transport[unit[i].Goal].pos_y / 32, unit[i].pos_x / 32, unit[i].pos_y / 32);
                            CandeleteInMap2 = true;
                        }
                        for(int dx = -1; dx <= 1; dx++){
                            for(int dy = -1; dy <= 1; dy ++){
                                if(dx * dx + dy * dy == 1){
                                    if(map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] > 0 &&
                                       map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] < map2[(int)(unit[i].pos_x / 32)][(int)(unit[i].pos_y / 32)]){
                                        unit[i].MapGoalX = dx + unit[i].pos_x / 32;
                                        unit[i].MapGoalY = dy + unit[i].pos_y / 32;
                                        break;
                                    }
                                }
                            }
                        }
                        if(CandeleteInMap2)
                            deleteInMap2();
                    }
                }
                else{
                    bool CandeleteInMap2 = false;
                    if(map2[(int)transport[unit[i].Goal].pos_x / 32][(int)transport[unit[i].Goal].pos_y / 32] > -1){
                        map2[(int)transport[unit[i].Goal].pos_x / 32][(int)transport[unit[i].Goal].pos_y / 32] = 1;
                        dfs(transport[unit[i].Goal].pos_x / 32, transport[unit[i].Goal].pos_y / 32, unit[i].pos_x / 32, unit[i].pos_y / 32);
                        CandeleteInMap2 = true;
                    }
                    for(int dx = -1; dx <= 1; dx++){
                        for(int dy = -1; dy <= 1; dy ++){
                            if(dx * dx + dy * dy == 1){
                                if(map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] > 0 &&
                                   map2[(int)(dx + unit[i].pos_x / 32)][(int)(dy + unit[i].pos_y / 32)] < map2[(int)(unit[i].pos_x / 32)][(int)(unit[i].pos_y / 32)]){
                                    unit[i].MapGoalX = dx + unit[i].pos_x / 32;
                                    unit[i].MapGoalY = dy + unit[i].pos_y / 32;
                                    break;
                                }
                            }
                        }
                    }
                    if(CandeleteInMap2)
                        deleteInMap2();
                }
            }
            else{
                unit[i].Goal = -1;
                unit[i].MapGoalX = unit[i].pos_x / 32;
                unit[i].MapGoalY = unit[i].pos_y / 32;
            }
        }
        else{
            if(unit[i].animation < 7.6 && unit[i].animation >= 6)
                unit[i].animation += 0.4;
            else
                unit[i].animation = 0;

            double dx = transport[unit[i].Goal].pos_x - unit[i].pos_x,
            dy = transport[unit[i].Goal].pos_y - unit[i].pos_y;
            unit[i].alpha = Alpha(-dx, -dy);

            if(unit[i].timeP >= unit[i].maxTimeP){
                bullet.push_back(Bullet(unit[i].pos_x, unit[i].pos_y, unit[i].alpha, unit[i].id + 5));
                unit[i].timeP = 0;
                unit[i].animation = 6;
            }
        }
    }
    else if(unit[i].Job == 2){
        //------------------------------------------ДЕСАНТ---------------------------
        if(PlayerPoint.size() == 0){
            return 0;
        }
        if(unit[i].Goal <= -1 && freeEnemyTransport.size() > 0){
            int MyTransportPos = rand() % (int)freeEnemyTransport.size();
            int MyTransport = freeEnemyTransport[MyTransportPos];
            freeEnemyTransport.erase(freeEnemyTransport.begin() + MyTransportPos);
            unit[MyTransport].Goal = i;
            unit[i].Goal = MyTransport;

            int MyPoint = rand() % (int)PlayerPoint.size();
            if(UnitMap[unit[i].GoalX][unit[i].GoalY][1] > 0 || map2[unit[i].GoalX][unit[i].GoalY] == -1){
                unit[i].GoalX = PlayerPoint[MyPoint].pos_x;
                unit[i].GoalY = PlayerPoint[MyPoint].pos_y;
            }
            while(UnitMap[unit[i].GoalX][unit[i].GoalY][1] > 0 || map2[unit[i].GoalX][unit[i].GoalY] == -1){
                unit[i].GoalX += rand()%3 - 1;
                unit[i].GoalY += rand()%3 - 1;
                if(unit[i].GoalX < 0 || unit[i].GoalX >= 200 || unit[i].GoalY < 0 || unit[i].GoalY >= 200)
                    return 0;
            }
            UnitMap[unit[i].GoalX][unit[i].GoalY][1] = i + 1;
            unit[unit[i].Goal].GoalX = unit[i].pos_x / 32;
            unit[unit[i].Goal].GoalY = unit[i].pos_y / 32;
        }
        else{
            //cout << unit[unit[i].Goal].GoalX << " " << unit[unit[i].Goal].GoalY << " . " << (int)unit[unit[i].Goal].pos_x / 32 << " " << (int)unit[unit[i].Goal].pos_y / 32 << endl;
            if(LengthLine(unit[i].pos_x, unit[i].pos_y, unit[unit[i].Goal].pos_x, unit[unit[i].Goal].pos_y) < 30){
                unit[i].pos_x = unit[unit[i].Goal].pos_x;
                unit[i].pos_y = unit[unit[i].Goal].pos_y;
                unit[unit[i].Goal].GoalX = unit[i].GoalX;
                unit[unit[i].Goal].GoalY = unit[i].GoalY;
            }
            if(LengthLine(unit[i].pos_x, unit[i].pos_y, unit[i].GoalX * 32 + 16, unit[i].GoalY * 32 + 16) < 8){
                unit[unit[i].Goal].Goal = -1;
                unit[unit[i].Goal].GoalX = -1;
                unit[unit[i].Goal].GoalY = -1;
                freeEnemyTransport.push_back(unit[i].Goal);
                unit[i].Goal = -1;
                unit[i].GoalX = -1;
                unit[i].GoalY = -1;
                unit[i].Job = 1;
            }
        }
    }
}

void Enemy3Logic(int i){
    if(unit[i].GoalX != -1 && unit[i].GoalY != -1){
        if(unit[i].Goal > -1){
            if(unit[i].speed < 5){
                unit[i].speed += 0.1;
            }
            double dx = unit[i].GoalX * 32 + 16 - unit[i].pos_x,
            dy = unit[i].GoalY * 32 + 16 - unit[i].pos_y;
            unit[i].alpha = Alpha(-dx, -dy);
            unit[i].pos_x += sin(Pi - unit[i].alpha) * unit[i].speed;
            unit[i].pos_y += cos(Pi - unit[i].alpha) * unit[i].speed;
        }
    }
    else{
        if(unit[i].speed > 0)
            unit[i].speed -= 0.1;
    }

}

void Enemy2Logic(int i){
    if(unit[i].GoalX == -1 || unit[i].GoalY == -1){
        if(unit[i].speed > 0)
            unit[i].speed -= 0.1;
        int d = rand()%500;
        //cout << "Unit " << i << " " << unit[i].GoalX << " " << unit[i].GoalY << " ";
        if(NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32) >= 0){
            if(enemyBuild[NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32)].Construction == 6){
                if(d == 0 && CountEnemyBase < 10){
                    //новое поселение
                    int pos_x = rand()%130 + 50, pos_y = rand()%130 + 50;
                    int g = 0;
                    while(NearBase(pos_x, pos_y) == -1 && g < 10){
                        pos_x = rand()%130 + 50;
                        pos_y = rand()%130 + 50;
                        g ++;
                    }
                    while(!CanBuild(pos_x, pos_y)){
                        pos_x += rand()%3 - 1;
                        pos_y += rand()%3 - 1;
                    }
                    if(pos_x <= 190 && pos_x > 10 && pos_y <= 190 && pos_y > 10){
                        unit[i].GoalX = pos_x;
                        unit[i].GoalY = pos_y;
                    }
                    unit[i].Job = 1;
                    unit[i].Goal = 1;
                }
                else if(d < 3 && NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32) >= 0){
                    int pos_x = enemyBuild[NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32)].pos_x;
                    int pos_y = enemyBuild[NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32)].pos_y;
                    while(!CanBuild(pos_x, pos_y)){
                        pos_x += rand()%3 - 1;
                        pos_y += rand()%3 - 1;
                    }
                    int dx = enemyBuild[NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32)].pos_x - pos_x;
                    int dy = enemyBuild[NearBase(unit[i].pos_x / 32, unit[i].pos_y / 32)].pos_y - pos_y;
                    int r = dx * dx + dy * dy;
                    if(pos_x <= 190  && pos_x > 10 && pos_y <= 190 && pos_y > 10 && r < 24){
                        unit[i].GoalX = pos_x;
                        unit[i].GoalY = pos_y;
                    }
                    unit[i].Job = 2;
                    unit[i].Goal = rand()%5 + 1;
                }
            }
        }
        else{
            int pos = searchBase(unit[i].pos_x / 32, unit[i].pos_y / 32);
            if(d == 0 && CountEnemyBase < 10){
                //новое поселение
                int pos_x = rand()%130 + 50, pos_y = rand()%130 + 50;
                int g = 0;
                while(NearBase(pos_x, pos_y) == -1 && g < 10){
                    pos_x = rand()%130 + 50;
                    pos_y = rand()%130 + 50;
                    g ++;
                }
                while(!CanBuild(pos_x, pos_y)){
                    pos_x += rand()%3 - 1;
                    pos_y += rand()%3 - 1;
                }
                int dx = enemyBuild[pos].pos_x - pos_x;
                int dy = enemyBuild[pos].pos_y - pos_y;
                int r = dx * dx + dy * dy;
                if(pos_x <= 190  && pos_x > 10 && pos_y <= 190 && pos_y > 10 && r < 24){
                    unit[i].GoalX = pos_x;
                    unit[i].GoalY = pos_y;
                }
                unit[i].Job = 1;
                unit[i].Goal = 1;
            }
            else if(d < 3){
                int pos_x = enemyBuild[pos].pos_x;
                int pos_y = enemyBuild[pos].pos_y;
                while(!CanBuild(pos_x, pos_y)){
                    pos_x += rand()%3 - 1;
                    pos_y += rand()%3 - 1;
                }
                if(pos_x <= 190  && pos_x > 10 && pos_y <= 190 && pos_y > 10){
                    unit[i].GoalX = pos_x;
                    unit[i].GoalY = pos_y;
                }
                unit[i].Job = 2;
                unit[i].Goal = rand()%5 + 1;
            }
        }
        //cout << "Have Job " << unit[i].Job << "to " << unit[i].GoalX << " " << unit[i].GoalY << endl;
    }
    else{
        if(LengthLine(unit[i].pos_x, unit[i].pos_y, unit[i].GoalX * 32 + 16, unit[i].GoalY * 32 + 16) < 8){// у места постройки
            unit[i].speed = 0;
            if(unit[i].Job == 1){
                enemyBuild.push_back(EnemyBuild(unit[i].GoalX, unit[i].GoalY, 0 + (int)Debug * 6));
                while(map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] != 0){
                    enemyBuild.back().pos_x += rand()%3 - 1;
                    enemyBuild.back().pos_y += rand()%3 - 1;
                }
                map2[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
                map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
                UnitMap[enemyBuild.back().pos_x][enemyBuild.back().pos_y][3] = enemyBuild.size();
                unit[i].GoalX = -1;
                unit[i].GoalY = -1;
                CountEnemyBase ++;
            }
            else{
                enemyBuild.push_back(EnemyBuild(unit[i].GoalX, unit[i].GoalY, unit[i].Goal));
                while(map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] != 0){
                    enemyBuild.back().pos_x += rand()%3 - 1;
                    enemyBuild.back().pos_y += rand()%3 - 1;
                }
                map2[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
                map1[enemyBuild.back().pos_x][enemyBuild.back().pos_y] = -1;
                UnitMap[enemyBuild.back().pos_x][enemyBuild.back().pos_y][3] = enemyBuild.size();
                unit[i].GoalX = -1;
                unit[i].GoalY = -1;
            }
        }
        else{
            double dx = unit[i].GoalX * 32 + 16 - unit[i].pos_x,
            dy = unit[i].GoalY * 32 + 16 - unit[i].pos_y;
            unit[i].alpha_k = Alpha(-dx, -dy);
            if(LengthLine(unit[i].pos_x, unit[i].pos_y, unit[i].GoalX * 32 + 16, unit[i].GoalY * 32 + 16) < 100)
                unit[i].speed_rotated = 2 * one_grad;
            else
                unit[i].speed_rotated = 10 * one_grad;

            if(unit[i].speed < 4){
                unit[i].speed += 0.1;
            }
            unit[i].pos_x += sin(Pi - unit[i].alpha) * unit[i].speed;
            unit[i].pos_y += cos(Pi - unit[i].alpha) * unit[i].speed;
            if(abs(unit[i].alpha - unit[i].alpha_k) <= unit[i].speed_rotated)
                unit[i].alpha = unit[i].alpha_k;
            else
                unit[i].alpha += unit[i].speed_rotated;

            if(unit[i].alpha > 2 * Pi)
                unit[i].alpha -= 2 * Pi;
        }
    }
}

void EnemyLogic(){
    if(countFps < 10)
        countFps ++;
    else
        countFps = 0;
    if(countFps = 0){
        for(int i = 0; i < enemyBuild.size(); i ++){
            if(enemyBuild[i].timeBuild < enemyBuild[i].MaxTimeBuild){
                enemyBuild[i].timeBuild += 10;
                //cout << enemyBuild[i].timeBuild << " ";
            }
            else{
                if(enemyBuild[i].Construction < 6){
                    enemyBuild[i].Construction ++;
                }
                else{
                    int pos_x, pos_y;
                    switch (enemyBuild[i].id){
                    case 0:
                        if(CountEnemyBase < 10 || CountEnemyTransport < 3 * CountEnemyBase){
                            pos_x = enemyBuild[i].pos_x * 32 + 16, pos_y = enemyBuild[i].pos_y * 32 + 16;
                            while(map2[pos_x / 32][pos_y / 32] == -1 || UnitMap[pos_x / 32][pos_y / 32][1] != 0){
                                pos_x += (rand()%3 - 1) * 32;
                                pos_y += (rand()%3 - 1) * 32;
                                if(pos_x / 32 >= 200 || pos_x < 0 || pos_y / 32 >= 200 || pos_y < 0){
                                    break;
                                }
                            }
                            NewUnit(pos_x, pos_y, rand() % 360 * one_grad, 2);
                            transport.back().Goal = i;
                            enemyBuild[i].MaxTimeBuild = 900 + rand() % 61 - 30;
                            CountEnemyTransport ++;
                        }
                        break;
                    case 1:
                        pos_x = enemyBuild[i].pos_x * 32 + 16, pos_y = enemyBuild[i].pos_y * 32 + 16;
                        while(map2[pos_x / 32][pos_y / 32] == -1 || UnitMap[pos_x / 32][pos_y / 32][1] != 0){
                            pos_x += (rand()%3 - 1) * 32;
                            pos_y += (rand()%3 - 1) * 32;
                            if(pos_x / 32 >= 200 || pos_x < 0 || pos_y / 32 >= 200 || pos_y < 0){
                                break;
                            }
                        }
                        NewUnit(pos_x, pos_y, rand() % 360 * one_grad, 0);
                        enemyBuild[i].MaxTimeBuild = 1800 + rand() % 61 - 30;
                        break;
                    case 2:
                        pos_x = enemyBuild[i].pos_x * 32 + 16, pos_y = enemyBuild[i].pos_y * 32 + 16;
                        while(map2[pos_x / 32][pos_y / 32] == -1 || UnitMap[pos_x / 32][pos_y / 32][1] != 0){
                            pos_x += (rand()%3 - 1) * 32;
                            pos_y += (rand()%3 - 1) * 32;
                            if(pos_x / 32 >= 200 || pos_x < 0 || pos_y / 32 >= 200 || pos_y < 0){
                                break;
                            }
                        }
                        NewUnit(pos_x, pos_y, rand() % 360 * one_grad, 1);
                        enemyBuild[i].MaxTimeBuild = 3600 + rand() % 61 - 30;
                        break;
                    case 5:
                        pos_x = enemyBuild[i].pos_x * 32 + 16, pos_y = enemyBuild[i].pos_y * 32 + 16;
                        while(map2[pos_x / 32][pos_y / 32] == -1 || UnitMap[pos_x / 32][pos_y / 32][1] != 0){
                            pos_x += (rand()%3 - 1) * 32;
                            pos_y += (rand()%3 - 1) * 32;
                            if(pos_x / 32 >= 200 || pos_x < 0 || pos_y / 32 >= 200 || pos_y < 0){
                                break;
                            }
                        }
                        NewUnit(pos_x, pos_y, rand() % 360 * one_grad, 3);
                        enemyBuild[i].MaxTimeBuild = 3600 + rand() % 61 - 30;
                        break;
                    }
                }
                enemyBuild[i].timeBuild = 0;
            }
        }
    }
    for(int i = 0; i < unit.size(); i ++){
        if(unit[i].timeP < unit[i].maxTimeP)
            unit[i].timeP ++;
        UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = 0;
        UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = 0;
        UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = 0;
        UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = 0;
        //if(!Debug){
            switch(unit[i].id){
                case 0:
                    Enemy0Logic(i);
                break;
                case 1:
                    Enemy1Logic(i);
                break;
                case 2:
                    Enemy2Logic(i);
                break;
                case 3:
                    Enemy3Logic(i);
                break;
            }
       //}
        UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = i + 1;
        UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = i + 1;
        UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = i + 1;
        UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = i + 1;
        if(unit[i].xp <= 0){
            if(unit[i].id == 2){
                CountEnemyTransport --;
            }
            for(int j = 0; j < transport.size(); j ++){
                if(transport[j].Job == 1 && transport[j].id > 1){
                    if(transport[j].Goal == i) {
                        transport[j].Job = 2;
                        transport[j].Goal = -1;
                    }
                    else if(transport[j].Goal > i){
                        transport[j].Goal --;
                    }
                }
            }
            UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = 0;
            UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y - 16) / 32][1] = 0;
            UnitMap[(int)(unit[i].pos_x + 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = 0;
            UnitMap[(int)(unit[i].pos_x - 16) / 32][(int)(unit[i].pos_y + 16) / 32][1] = 0;
            unit.erase(unit.begin() + i);
        }
    }
}

void TransportKillEvent(int i){
    if(transport[i].id == 1){
        for(int j = 0; j < build.size(); j ++){
            if(build[j].JobTransport == i){
                build[j].JobTransport = -1;
                build[j].searchTransport = true;
            }
        }
        if(transport[i].Job < 1)
            FreeTransport --;
    }
    else{
        if(transport[i].inSelect){
            for(int j = 0; j < SelectTransport.size(); j ++){
                if(SelectTransport[j] == i){
                    SelectTransport.erase(SelectTransport.begin() + j);
                }
            }
        }
    }
    for(int j = 0; j < unit.size(); j ++){
        if(unit[j].id == 0){
            if(unit[j].Goal > i){
                unit[j].Goal --;
            }
            else if(unit[j].Goal == i)
                unit[j].Goal = -1;
        }
    }
    transport.erase(transport.begin() + i);
}

void CivilTransportLogic(int i){
    if(transport[i].Job > 0){
        if(transport[i].speed < transport[i].Max_speed){
            transport[i].speed += 0.1;
        }
        double dx = build[transport[i].Goal].pos_x * 32 + 16 - transport[i].pos_x,
        dy = build[transport[i].Goal].pos_y * 32 + 16 - transport[i].pos_y;
        transport[i].alpha_k = Alpha(-dx, -dy);
        transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
        transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
        if(abs(transport[i].alpha - transport[i].alpha_k) <= transport[i].speed_rotated)
            transport[i].alpha = transport[i].alpha_k;
        else
            transport[i].alpha += transport[i].speed_rotated;

        if(transport[i].alpha > 2 * Pi)
            transport[i].alpha -= 2 * Pi;

        if(On_build(transport[i].pos_x, transport[i].pos_y, transport[i].Goal) > 0){
            switch(transport[i].Job){
                case 1:
                if(build[transport[i].Job_build].Construction == 6){
                    build[transport[i].Job_build].JobTransport --;
                    LevelUp(transport[i].Job_build);
                    transport[i].Job_build = -1;
                    transport[i].Job = -1;
                    FreeTransport ++;
                    if(HaveConstruction() > -1){
                        transport[i].Job_build = HaveConstruction();
                        transport[i].Job = 1;
                        FreeTransport --;
                        build[transport[i].Job_build].JobTransport ++;
                    }
                }
                if(build[transport[i].Goal].id == 2 && build[transport[i].Goal].Construction == 6){
                    transport[i].Goal = transport[i].Job_build;
                }
                else{
                    if(build[transport[i].Job_build].Construction < 6){
                        transport[i].Goal = Near_warehouse(transport[i].pos_x, transport[i].pos_y);
                        build[transport[i].Job_build].Construction ++;
                    }
                    else if(build[transport[i].Job_build].Construction == 6){
                        build[transport[i].Job_build].JobTransport --;
                        LevelUp(transport[i].Job_build);
                        transport[i].Job_build = -1;
                        transport[i].Job = -1;
                        FreeTransport ++;
                    }
                }
                break;
                case 2:
                    if(transport[i].Goal != transport[i].Job_build){
                        if(transport[i].MyRes >= 0){
                            substance[transport[i].MyRes] ++;
                            transport[i].MyRes = -1;
                            transport[i].Goal = transport[i].Job_build;
                        }
                    }
                    else{
                        int HaveRes = FreeMineRes(transport[i].Job_build);
                        if(HaveRes >= 0){
                            build[transport[i].Job_build].MySubstance[HaveRes] --;
                            transport[i].MyRes = HaveRes;
                            transport[i].Goal = Near_warehouse(transport[i].pos_x, transport[i].pos_y);
                        }
                    }
                break;
            }
        }
    }
    else{
        transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
        transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
        if(transport[i].speed > 0)
            transport[i].speed -= 0.1;
    }
}

void MilitareTransportLogic(int i){
    if(transport[i].TimeP < transport[i].AllTimeP){
        transport[i].TimeP ++;
    }
    if(transport[i].patrul && transport[i].Job == 0){
        int SeeLength = 6;
        for(int dx = -SeeLength; dx <= SeeLength; dx ++){
            for(int dy = -SeeLength; dy <= SeeLength; dy ++){
                if(dx * dx + dy * dy <= SeeLength * SeeLength){
                    if(UnitMap[(int)transport[i].pos_x / 32 + dx][(int)transport[i].pos_y / 32 + dy][1] > 0){
                        transport[i].Job = 1;
                        transport[i].Goal = UnitMap[(int)transport[i].pos_x / 32 + dx][(int)transport[i].pos_y / 32 + dy][1] - 1;
                        break;
                    }
                }
            }
        }
    }
    if(transport[i].inSelect){
        transport[i].patrul = SelectTransportJob[2];
    }
    switch(transport[i].Job){
        case 1:
            if(transport[i].TimeP == transport[i].AllTimeP){
                double dx = unit[transport[i].Goal].pos_x - transport[i].pos_x,
                dy = unit[transport[i].Goal].pos_y - transport[i].pos_y;
                transport[i].alpha_k = Alpha(-dx, -dy);
                if(abs(transport[i].alpha - transport[i].alpha_k) <= transport[i].speed_rotated)
                    transport[i].alpha = transport[i].alpha_k;
                //cout << transport[i].alpha << " " << transport[i].alpha_k << endl;
                bullet.push_back(Bullet(transport[i].pos_x, transport[i].pos_y, transport[i].alpha_k, transport[i].id  - 1));
                transport[i].TimeP = 0;
            }

            if(LengthLine(transport[i].pos_x, transport[i].pos_y, unit[transport[i].Goal].pos_x, unit[transport[i].Goal].pos_y) < 100)
                transport[i].speed_rotated = 2 * one_grad;
            else
                transport[i].speed_rotated = 10 * one_grad;

            if(transport[i].speed < transport[i].Max_speed){
                transport[i].speed += 0.1;
            }
            transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
            transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
            if(abs(transport[i].alpha - transport[i].alpha_k) <= transport[i].speed_rotated)
                transport[i].alpha = transport[i].alpha_k;
            else
                transport[i].alpha += transport[i].speed_rotated;

            if(transport[i].alpha > 2 * Pi)
                transport[i].alpha -= 2 * Pi;
            break;
        case 2:
            transport[i].speed_rotated = 10 * one_grad;
            if(LengthLine(transport[i].pos_x, transport[i].pos_y, transport[i].MapGoalX * 32 + 16, transport[i].MapGoalY * 32 + 16) > 32){
                if(transport[i].speed < transport[i].Max_speed){
                    transport[i].speed += 0.1;
                }
                double dx = transport[i].MapGoalX * 32 + 16 - transport[i].pos_x,
                dy = transport[i].MapGoalY * 32 + 16- transport[i].pos_y;
                transport[i].alpha_k = Alpha(-dx, -dy);
                transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
                transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
                if(abs(transport[i].alpha - transport[i].alpha_k) <= transport[i].speed_rotated)
                    transport[i].alpha = transport[i].alpha_k;
                else
                    transport[i].alpha += transport[i].speed_rotated;

                if(transport[i].alpha > 2 * Pi)
                    transport[i].alpha -= 2 * Pi;
            }
            else{
                transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
                transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
                if(transport[i].speed > 0)
                    transport[i].speed -= 0.1;
                else
                    transport[i].Job = 0;
            }
            break;
        case 0:
            transport[i].pos_x += sin(Pi - transport[i].alpha) * transport[i].speed;
            transport[i].pos_y += cos(Pi - transport[i].alpha) * transport[i].speed;
            if(transport[i].speed > 0)
                transport[i].speed -= 0.1;
            break;
    }
}

void TransportLogic(){
    for(int i = 0; i < transport.size(); i ++){
        UnitMap[(int)(transport[i].pos_x - 10)/ 32][(int)(transport[i].pos_y - 10) / 32][0] = 0;
        UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y - 10) / 32][0] = 0;
        UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = 0;
        UnitMap[(int)(transport[i].pos_x - 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = 0;
        if(transport[i].id == 1){
            CivilTransportLogic(i);
        }
        else{
            MilitareTransportLogic(i);
        }
        if(transport[i].xp < 0){
            TransportKillEvent(i);
            UnitMap[(int)(transport[i].pos_x - 10)/ 32][(int)(transport[i].pos_y - 10) / 32][0] = 0;
            UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y - 10) / 32][0] = 0;
            UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = 0;
            UnitMap[(int)(transport[i].pos_x - 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = 0;
        }
        else{
            UnitMap[(int)(transport[i].pos_x - 10) / 32][(int)(transport[i].pos_y - 10) / 32][0] = i + 1;
            UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y - 10) / 32][0] = i + 1;
            UnitMap[(int)(transport[i].pos_x + 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = i + 1;
            UnitMap[(int)(transport[i].pos_x - 10) / 32][(int)(transport[i].pos_y + 10) / 32][0] = i + 1;
        }

    }
}

void Game_Mode(){
    TimeGame += Second60;

    if(Transformirum > 1000000000)
        Transformirum = 10000000000;
    if(Man > 10000)
        Man = 10000;

    if(SelectTransport.size() == 0 && CanSelect){
        select_x1 = cx + offset_x;
        select_y1 = cy + offset_y;
    }
    if(!key[mouse_1]){
        if(select_x0 > 0 && select_x1 > 0 && select_y0 > 0 && select_y1 > 0){
            for(int i = 0; i < transport.size(); i ++){ ///-----------------Поменять на проверку по мапе---------------------
                if(transport[i].pos_x >= min(select_x0, select_x1) && transport[i].pos_x <= max(select_x1, select_x0) &&
                   transport[i].pos_y >= min(select_y0, select_y1) && transport[i].pos_y <= max(select_y1, select_y0)
                   && transport[i].id > 1){
                    SelectTransport.push_back(i);
                    transport[SelectTransport.back()].inSelect = true;
                }
            }
        }
        select_x1 = -1;
        select_x0 = -1;
        select_y1 = -1;
        select_y0 = -1;
        CanSelect = false;

        if(capture >= 0 && already_busy(cx + offset_x, cy + offset_y) == -1 && !(cx >= 567 && cx <= 839 && cy > 51 && cy <= 111)
        && Transformirum >= price_build[capture] && Man >= -Man_num[capture]
        && map1[(int)(offset_x + cx) / 32][(int)(offset_y + cy) / 32] != 1 && openBuild[capture]){
            build.push_back(Build(capture, (int)((cx + offset_x) / 32), (int)((cy + offset_y) / 32), Max_num_image_array[capture]));
            Transformirum -= price_build[capture];
            FreeToWork(build.size() - 1);
            map2[build.back().pos_x][build.back().pos_y] = -1;
            UnitMap[build.back().pos_x][build.back().pos_y][2] = build.size();
        }
        capture = -1;
    }
    if(cx <= 51 && offset_x >= 40)
        offset_x -= 2 + (51 - cx) / 10;
    if(cx >= 949 && offset_x <= 200 * 32 - 40 - 1000)
        offset_x += 2 + (cx - 949) / 10;
    if(cy <= 51 && offset_y >= 40)
        offset_y -= 2 + (51 - cy) / 10;
    if(cy >= 549 && offset_y <= 200 * 32 - 40 - 600)
        offset_y += 2 + (cy - 549) / 10;

    for(int i = 0; i < build.size(); i ++){
        if(build[i].Construction < 6){
            int free = have_free_transport();
            if(free >= 0){
                transport[free].Job = 1;
                transport[free].Job_build = i;
                transport[free].Goal = i;
                double dx = build[transport[free].Goal].pos_x * 32 + 16 - transport[free].pos_x,
                dy = build[transport[free].Goal].pos_y * 32 + 16 - transport[free].pos_y;
                transport[free].alpha_k = Alpha(-dx, -dy);
                build[i].JobTransport ++;
                FreeTransport --;
            }
        }
        else{
            if(build[i].wearout > 0){
                switch(build[i].id){
                    case 1:
                        //cout << build[i].time_m << " ";
                        if(build[i].time_m < build[i].Max_time)
                            build[i].time_m ++;
                        else{
                            build[i].time_m = 0;
                            if(build[i].num < build[i].level)
                                build[i].num ++;
                            new_substance(i);
                            build[i].wearout --;
                        }
                    break;
                }
            }
            else if(build[i].MySubstance[map1[build[i].pos_x][build[i].pos_y] - 2] == 0){
                build[i].searchTransport = false;
                for(int j = 0; j < transport.size(); j ++){
                    if(transport[j].id == 1){
                        if(transport[i].Job == 2 && (transport[j].Job_build == i || transport[j].Goal == i)){
                            transport[j].Job = -1;
                            FreeTransport ++;
                        }
                    }
                }
            }
        }
        if(build[i].searchTransport && build[i].JobTransport == 0){
            int free = have_free_transport();
            if(free >= 0){
                transport[free].Job = 2;
                transport[free].Job_build = i;
                transport[free].Goal = i;
                double dx = build[transport[free].Goal].pos_x * 32 + 16 - transport[free].pos_x,
                dy = build[transport[free].Goal].pos_y * 32 + 16 - transport[free].pos_y;
                transport[free].alpha_k = Alpha(-dx, -dy);
                build[i].JobTransport ++;
                FreeTransport --;
            }
        }
        else if(!build[i].searchTransport && build[i].JobTransport == 1){
            for(int j = 0; j < transport.size(); j ++){
                if(transport[j].Job == 2 && transport[j].Job_build == i && transport[j].MyRes == -1){
                    build[transport[j].Job_build].JobTransport --;
                    FreeTransport ++;
                    transport[j] = Transport(transport[j].pos_x, transport[j].pos_y, transport[j].alpha, transport[j].id);
                }
             }
        }
        if(build[i].xp <= 0){
            for(int j = 0; j < transport.size(); j ++){
                if(transport[j].id == 1){
                    if(transport[j].Job_build == i || transport[j].Goal == i)
                        transport[j].Job = 0;
                }
            }
            for(int j = 0; j < unit.size(); j ++){
                if(unit[j].id == 1){
                    if(unit[j].Goal == i)
                        unit[j].Goal = -1;
                    else if(unit[j].Goal > i)
                        unit[j].Goal --;
                }
            }
            for(int j = i + 1; j < build.size(); j ++){
                UnitMap[build[j].pos_x][build[j].pos_y][2] = j;
            }
            UnitMap[build[i].pos_x][build[i].pos_y][2] = 0;
            build.erase(build.begin() + i);
        }
    }
    EnemyLogic();

    for(int i = 0; i < bullet.size(); i ++){
        if(bullet[i].TimeFly <= 150){
            bullet[i].TimeFly ++;
            bullet[i].pos_x += bullet[i].speed * sin(Pi - bullet[i].alpha);
            bullet[i].pos_y += bullet[i].speed * cos(Pi - bullet[i].alpha);
            if(UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][1] > 0 && bullet[i].id <= 4){
                unit[UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][1] - 1].xp -= bullet[i].id;
                PlayerPoint.push_back(playerPoint(bullet[i].pos_x / 32, bullet[i].pos_y / 32));
                bullet.erase(bullet.begin() + i);
            }
            else if(UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][0] > 0 && bullet[i].id == 5){
                transport[UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][0] - 1].xp -= bullet[i].id;
                bullet.erase(bullet.begin() + i);
            }
            else if(UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][2] > 0 && bullet[i].id == 6){
                build[UnitMap[(int)(bullet[i].pos_x / 32)][(int)(bullet[i].pos_y / 32)][2] - 1].xp -= bullet[i].id;
                bullet.erase(bullet.begin() + i);
            }
        }
        else{
            bullet.erase(bullet.begin() + i);
        }
    }
    TransportLogic();
}

void Game_Mode_Mouse(){
    //cout << Man << " ";
    select_x0 = -1;
    select_y0 = -1;
    if(SelectTransport.size() > 0){
        if(cx >= 864 && cx <= 894 && cy >= 399 && cy <= 429){
            while(SelectTransport.size() > 0){
                transport[SelectTransport[0]].inSelect = false;
                SelectTransport.erase(SelectTransport.begin());
            }
            SelectTransportJob[0] = false;
            SelectTransportJob[1] = false;
            SelectTransportJob[2] = false;
        }
        else if(cx >= 895 && cx <= 925 && cy >= 399 && cy <= 429){
            SelectTransportJob[0] = false;
            SelectTransportJob[2] = false;
            SelectTransportJob[1] = !SelectTransportJob[1];
        }
        else if(cx >= 864 && cx <= 894 && cy >= 431 && cy <= 461){
            SelectTransportJob[1] = false;
            SelectTransportJob[2] = false;
            SelectTransportJob[0] = !SelectTransportJob[0];
        }
        else if(cx >= 895 && cx <= 925 && cy >= 431 && cy <= 461){
            SelectTransportJob[1] = false;
            SelectTransportJob[0] = false;
            SelectTransportJob[2] = !SelectTransportJob[2];
        }
    }
    if(all_false_open_dialog()){
        if(cx >= 51 && cx <= 816 && cy >= 51 && cy <= 549){
            MouseToGameField();
        }
    }
    else{
        bool is_search_build = false;
        if(open_dialog[2]){
            if(cx >= 100 && cx <= 800 && cy >= 100 && cy <= 500){
                if(cx >= 128 && cy >= 192 && (cx - 128) % 40 <= 30 && (cy - 192) % 65 <= 30){
                    int itemX = (cx - 128) / 40, itemY = (cy - 192) / 65;
                    if(substance[itemX] >= PriceTechnology[itemX][itemY] && Technology[itemX][itemY] == 1){
                        substance[itemX] -= PriceTechnology[itemX][itemY];
                        Technology[itemX][itemY] = 2;
                        if(itemY < 5)
                            Technology[itemX][itemY + 1] = 1;
                        int numResearch = itemX * 100 + itemY;
                        switch(numResearch){
                        case 0:
                            openBuild[4] = 1;
                            break;
                        case 100:
                            openTransport[0] = true;
                            break;
                        case 101:
                            openTransport[1] = true;
                            if(Technology[2][1] == 2)
                                Technology[2][2] = 1;
                            else
                                Technology[2][2] = 0;
                            break;
                        case 2:
                            DigRes = true;
                            break;
                        case 1:
                            openBuild[5] = true;
                            break;
                        case 202:
                            openTransport[2] = true;
                            break;
                        case 201:
                            if(Technology[1][1] == 2)
                                Technology[2][2] = 1;
                            else
                                Technology[2][2] = 0;
                            break;
                        }
                    }
                }
            }
            else
                open_dialog[2] = false;
        }
        else if(open_dialog[0]){
            is_search_build = true;
            if(cx >= 361 && cx <= 840 && cy >= 52 && cy <= 102 && substance[(cx - 361) / 30] > 0){
                substance[(cx - 361) / 30] --;
                Transformirum += price_substance[(cx - 361) / 30];
            }
            else if(cx >= 51 && cx <= 816 && cy >= 51 && cy <= 549){
                MouseToGameField();
            }
        }
        else if(open_dialog[1]){
            if(cx >= 567 && cx <= 839 && cy > 51 && cy <= 111){
                capture = (cx - 557) / 46;
            }
            else if(cx >= 51 && cx <= 816 && cy >= 51 && cy <= 549 && !is_search_build){
                MouseToGameField();
                is_search_build = true;
            }
        }
        else if(open_dialog[3]){
            if(cx > 599 && cx < 839 && cy > 500 && cy < 550){
                int Id = (cx - 599) / 46;
                if(openTransport[Id] && Transformirum >= PriceTransport[Id] && Man > 0){
                    Transformirum -= PriceTransport[Id];
                    Man --;
                    if(Id == 0)
                        FreeTransport ++;
                    transport.push_back(Transport(build[Interface_build.pos].pos_x * 32 + 16, build[Interface_build.pos].pos_y * 32 + 16, rand()%360 * one_grad, Id + 1));
                    if(UnitMap[(int)(build[Interface_build.pos].pos_x * 32 + 16) / 32][(int)(build[Interface_build.pos].pos_y * 32 + 16) / 32][0] > 0){
                        int pos_x1 = transport.back().pos_x / 32, pos_y1 = transport.back().pos_y / 32;
                        int direction = rand()%8;
                        while(UnitMap[pos_x1][pos_y1][0] > 0){
                            if(pos_x1 == 0 || pos_x1 == 199 || pos_y1 == 0 || pos_y1 == 199){
                                direction += 4;
                                direction %= 8;
                            }
                            switch(direction){
                                case 0:
                                    pos_x1 --;
                                    if(UnitMap[pos_x1][pos_y1][0] > 0)
                                        pos_y1 --;
                                    break;
                                case 1:
                                    pos_y1--;
                                    break;
                                case 2:
                                    pos_x1 ++;
                                    if(UnitMap[pos_x1][pos_y1][0] > 0)
                                        pos_y1 --;
                                    break;
                                case 3:
                                    pos_x1 ++;
                                    break;
                                case 4:
                                    pos_x1 ++;
                                    if(UnitMap[pos_x1][pos_y1][0] > 0)
                                        pos_y1 ++;
                                    break;
                                case 5:
                                    pos_y1 ++;
                                    break;
                                case 6:
                                    pos_x1 --;
                                    if(UnitMap[pos_x1][pos_y1][0] > 0)
                                        pos_y1 ++;
                                    break;
                                case 7:
                                    pos_x1 --;
                                    break;
                            }
                        }
                        transport.back().pos_x = pos_x1 * 32;
                        transport.back().pos_y = pos_y1 * 32;
                    }
                    if(transport.back().id > 1){
                        UnitMap[(int)(transport.back().pos_x / 32)][(int)(transport.back().pos_y / 32)][0] = transport.size();
                    }
                }
            }
            else if(cx >= 51 && cx <= 816 && cy >= 51 && cy <= 549 && !is_search_build){
                MouseToGameField();
                is_search_build = true;
            }
        }
        else if(open_dialog[4]){
            is_search_build = true;
            if(cx >= 361 && cx <= 840 && cy >= 501 && cy <= 551 && Transformirum > price_substance[(cx - 361) / 30] * 1.5){
                substance[(cx - 361) / 30] ++;
                Transformirum -= price_substance[(cx - 361) / 30] * 1.5;
            }
            else if(cx >= 51 && cx <= 816 && cy >= 51 && cy <= 549){
                MouseToGameField();
            }
        }
    }
    if(cx >= 863 && cx <= 893 && cy >= 287 && cy <= 317){
        open_dialog[0] = !open_dialog[0];
        open_dialog[1] = false;
        open_dialog[3] = false;
        open_dialog[4] = false;
    }
    else if(cx >= 863 && cx <= 893 && cy >= 254 && cy <= 284){
        open_dialog[1] = !open_dialog[1];
        open_dialog[0] = false;
        open_dialog[3] = false;
        open_dialog[4] = false;
    }
    else if(cx >= 863 && cx <= 893 && cy >= 319 && cy <= 349 && build[Interface_build.pos].id == 4){ //862, 318
        open_dialog[0] = false;
        open_dialog[1] = false;
        open_dialog[3] = !open_dialog[3];
        open_dialog[4] = false;
    }
    else if(cx >= 863 && cx <= 893 && cy >= 319 && cy <= 349 && build[Interface_build.pos].id == 5){
        open_dialog[0] = false;
        open_dialog[1] = false;
        open_dialog[4] = !open_dialog[4];
        open_dialog[3] = false;
    }
    else if(cx <= 200 && cy >= 400 && !open_dialog[3]){
        if(cx <= 15)
            offset_x = 40;
        else if(cx >= 185)
            offset_x = 5360;
        else
            offset_x = cx * 32 - 460;

        if(cy <= 410)
            offset_y = 40;
        else if(cy >= 570)
            offset_y = 5760;
        else{
            offset_y = (cy - 390) * 32 - 600;
        }
    }
    else if(cx >= 905 && cx <= 935 && cy >= 287 && cy <= 317 && build[Interface_build.pos].id == 1 && FreeTransport > 0 &&
            ((build[Interface_build.pos].wearout == 0 && build[Interface_build.pos].MySubstance[map2[build[Interface_build.pos].pos_x][build[Interface_build.pos].pos_y] - 2] > 0) || (build[Interface_build.pos].wearout > 0))){
        build[Interface_build.pos].searchTransport = !build[Interface_build.pos].searchTransport;
        if(build[Interface_build.pos].searchTransport){
            int free = have_free_transport();
            if(free >= 0){
                transport[free].Job = 2;
                transport[free].Job_build = Interface_build.pos;
                transport[free].Goal = Interface_build.pos;
                build[Interface_build.pos].JobTransport ++;
                FreeTransport --;
            }
            else
                build[Interface_build.pos].searchTransport = !build[Interface_build.pos].searchTransport;
        }
    }
    else if(build[Interface_build.pos].id == 3 && cx >= 863 && cx <= 893 && cy >= 319 && cy <= 349){//862, 318
        open_dialog[2] = !open_dialog[2];
    }
    else if(cx >= 895 && cx < 925 && cy >= 255 && cy <= 285 &&
            price_build[build[Interface_build.pos].id] * build[Interface_build.pos].level <= Transformirum &&
            build[Interface_build.pos].level < Max_level[build[Interface_build.pos].id] &&
            Man_num[build[Interface_build.pos].id] * build[Interface_build.pos].level + Man >= 0 && build[Interface_build.pos].Construction == 6){
        Transformirum -= price_build[build[Interface_build.pos].id] * build[Interface_build.pos].level;
        build[Interface_build.pos].Construction = 0;
        build[Interface_build.pos].level ++;
        build[Interface_build.pos].wearout = build[Interface_build.pos].level * 10;
        FreeToWork(Interface_build.pos);
    }
        //al_draw_bitmap(interface_image[49], 877, 52, 0);
    //cout << Man << endl;
}

void Game_Mode_Draw(){
    min_x = offset_x / 32 - 1;
    max_x = (offset_x + SCREEN_W - 120) / 32 + 1;
    min_y = offset_y / 32 - 1;
    max_y = (offset_y + SCREEN_H) / 32 + 1;

    for(int i = min_x; i <= max_x; i ++){
        for(int j = min_y; j <= max_y; j ++){
            if(map[i][j] >= 10)
                al_draw_bitmap(map_image[map[i][j]], i * 32 - offset_x, j * 32 - offset_y, 0);
        }
    }

    for(int i = 0; i < build.size(); i ++){
        if(build[i].pos_x >= min_x && build[i].pos_x <= max_x
        && build[i].pos_y >= min_y && build[i].pos_y <= max_y){
        //cout << build[i].max_num_image << "    ";
            if(build[i].num_image < build[i].max_num_image){
                build[i].num_image ++;
            }
            else{
                build[i].num_image = 0;
            }
            //cout << build[i].id * 10 + build[i].level - 1 << " " << build[i].num_image << endl;
            al_draw_bitmap(build_image[build[i].id * 10 + build[i].level - 1][build[i].num_image], build[i].pos_x * 32 - offset_x, build[i].pos_y * 32 - offset_y, 0);

            if(build[i].Construction < 6)
                al_draw_bitmap(Construction_image[build[i].Construction], build[i].pos_x * 32 - offset_x, build[i].pos_y * 32 - offset_y, 0);
            switch(build[i].id){
                case 1:
                    double alpha = 360 * build[i].time_m / build[i].Max_time * one_grad;
                    al_draw_bitmap(interface_image[5], build[i].pos_x * 32 - offset_x + 12 * sin(-alpha) + 15, build[i].pos_y * 32 - offset_y + 12 * cos(-alpha) + 15, 0);
                break;
            }
            if(build[i].Construction == 6 && map1[build[i].pos_x][build[i].pos_y] >= 2){
                if(build[i].MySubstance[map1[build[i].pos_x][build[i].pos_y] - 2] == 0)
                    al_draw_tinted_bitmap(interface_image[8 + map1[build[i].pos_x][build[i].pos_y]], al_map_rgba(255, 255, 255, 0), build[i].pos_x * 32 - offset_x + 3, build[i].pos_y * 32 - offset_y - 20, 0);
                else
                    al_draw_tinted_bitmap(interface_image[8 + map1[build[i].pos_x][build[i].pos_y]], al_map_rgba(10, 105, 10, 0), build[i].pos_x * 32 - offset_x + 3, build[i].pos_y * 32 - offset_y - 20, 0);
            }
            al_draw_line(build[i].pos_x * 32 - offset_x,  build[i].pos_y * 32 - offset_y - 8,  build[i].pos_x * 32 - offset_x + build[i].xp / 2,  build[i].pos_y * 32 - offset_y - 8, al_map_rgb(153, 211, 33), 1);
        }
    }

    DrawEnemy(min_x, min_y, max_x, max_y);

    for(int i = 0; i < bullet.size(); i ++){
        if(bullet[i].pos_x >= offset_x && bullet[i].pos_x <= offset_x + 800 &&
           bullet[i].pos_y >= offset_y && bullet[i].pos_y <= offset_y + 600){
            //cout << "bullet id = " << bullet[i].id << endl;
            al_draw_rotated_bitmap(bullet_image[bullet[i].id], 4, 4, bullet[i].pos_x - offset_x + 4, bullet[i].pos_y - offset_y + 4, bullet[i].alpha, 0);
        }
    }

    for(int i = 0; i < transport.size(); i ++){
        if(transport[i].pos_x >= offset_x && transport[i].pos_x <= offset_x + 800 &&
           transport[i].pos_y >= offset_y && transport[i].pos_y <= offset_y + 600){
            if(transport[i].inSelect)
                al_draw_bitmap(interface_image[45], transport[i].pos_x - offset_x - 17, transport[i].pos_y - offset_y - 17, 0);
            al_draw_rotated_bitmap(transport_image[transport[i].id][0], 10, 10, transport[i].pos_x - offset_x, transport[i].pos_y - offset_y, transport[i].alpha, 0);
             //al_draw_textf(font[17], al_map_rgb(0, 0, 0), transport[i].pos_x - offset_x, transport[i].pos_y - offset_y - 35, 0, "%d",i);
        }
    }

    al_draw_rectangle(select_x0 - offset_x, select_y0 - offset_y, select_x1 - offset_x, select_y1 - offset_y, al_map_rgb(42, 187, 189), 2);

    //----------------------------------------ИНТЕРФЕЙС--------------------------------------------------------------------------------------

    if(open_dialog[0]){
        for(int i = 0; i < 16; i ++){
            if(substance[i] > 999)
                substance[i] = 999;
            al_draw_bitmap(interface_image[2], 360 + 30 * i, 51, 0);
            al_draw_bitmap(interface_image[10 + i], 361 + 30 * i, 55, 0);
            al_draw_textf(font[10], al_map_rgb(0, 0, 0), 376 + 30 * i, 86, ALLEGRO_ALIGN_CENTRE, "%i", substance[i]);
        }
    }

    if(open_dialog[1]){
        for(int i = 0; i < 6; i ++){
            al_draw_bitmap(interface_image[4], 567 + 46 * i, 51, 0); // 102 540
            if(openBuild[i])
                al_draw_bitmap(build_image[i * 10][0], 573 + 46 * i, 55, 0); // 106 546
        }
        if(cx >= 567 && cx <= 839 && cy > 51 && cy <= 111){
            if(openBuild[(cx - 567) / 46]){
                if(price_build[(cx - 567) / 46] > Transformirum && -Man_num[(cx - 567) / 46] <= Man)
                    al_draw_textf(font[16], al_map_rgb(105, 10, 10), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%s, Tr -%d, Man %d", name_build[(cx - 567) / 46], price_build[(cx - 567) / 46], Man_num[(cx - 567) / 46]);
                else
                   al_draw_textf(font[16], al_map_rgb(10, 105, 10), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%s, Tr -%d, Man %d", name_build[(cx - 567) / 46], price_build[(cx - 567) / 46], Man_num[(cx - 567) / 46]);
            }
            else{
                al_draw_textf(font[16], al_map_rgb(105, 10, 10), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%s", name_build[(cx - 567) / 46]);
            }
        }
    }

    if(open_dialog[4]){
        for(int i = 0; i < 16; i ++){
            if(substance[i] > 999)
                substance[i] = 999;
            al_draw_bitmap(interface_image[2], 360 + 30 * i, 501, 0);
            al_draw_bitmap(interface_image[10 + i], 361 + 30 * i, 505, 0);
            al_draw_textf(font[10], al_map_rgb(0, 0, 0), 376 + 30 * i, 536, ALLEGRO_ALIGN_CENTRE, "%i", substance[i]);
        }
    }

    if(capture >= 0 && open_dialog[1]){
        if(already_busy(cx + offset_x, cy + offset_y) == -1 && Transformirum >= price_build[capture] && map1[(int)(offset_x + cx) / 32][(int)(offset_y + cy) / 32] != 1 && openBuild[capture]){
            al_draw_tinted_bitmap(build_image[capture * 10][0], al_map_rgba(0, 255, 0, 1), (int)((cx + offset_x) / 32) * 32 - offset_x, (int)((cy + offset_y) / 32) * 32 - offset_y, 0);
        }
        else
            al_draw_tinted_bitmap(build_image[capture * 10][0], al_map_rgba(255, 0, 0, 1), (int)((cx + offset_x) / 32) * 32 - offset_x, (int)((cy + offset_y) / 32) * 32 - offset_y, 0);
    }

    al_draw_bitmap(interface_image[0], 0, 0, 0);

    al_draw_bitmap(interface_image[1], 862, 286, 0);
    al_draw_bitmap(interface_image[3], 862, 254, 0);

    if(SelectTransport.size() > 0){
        al_draw_bitmap(interface_image[54], 862, 398, 0);
        al_draw_bitmap(interface_image[55], 894, 398, 0);
        al_draw_bitmap(interface_image[56], 862, 430, 0);
        al_draw_bitmap(interface_image[58], 894, 430, 0);
        if(SelectTransportJob[1])
            al_draw_bitmap(interface_image[57], 894, 398, 0);
        if(SelectTransportJob[0])
            al_draw_bitmap(interface_image[57], 862, 430, 0);
        if(SelectTransportJob[2])
            al_draw_bitmap(interface_image[57], 894, 430, 0);
        /*for(int i = 0; i < SelectTransport.size(); i ++){
             al_draw_textf(font[17], al_map_rgb(0, 0, 0), 970, 50 + 20 * i, 0, "%d", SelectTransport[i]);
        }*/
    }


    al_draw_bitmap(interface_image[44], build[Interface_build.pos].pos_x * 32 - offset_x - 8, build[Interface_build.pos].pos_y * 32 - offset_y - 8, 0);

    if(build[Interface_build.pos].id == 1 && FreeTransport > 0 &&
        ((build[Interface_build.pos].wearout == 0 && build[Interface_build.pos].MySubstance[map2[build[Interface_build.pos].pos_x][build[Interface_build.pos].pos_y] - 2] > 0) || (build[Interface_build.pos].wearout > 0))){
        if(build[Interface_build.pos].searchTransport)
            al_draw_bitmap(interface_image[53], 894, 286, 0);
        else
            al_draw_bitmap(interface_image[52], 894, 286, 0);
    }

    if(build[Interface_build.pos].id == 5){
        al_draw_bitmap(interface_image[59], 862, 318, 0);
    }

    al_draw_bitmap(build_image[Interface_build.id * 10 + Interface_build.level - 1][Interface_build.num_image], 878, 88, 0);

    al_draw_textf(font[12], al_map_rgb(29, 167, 169), 840, 163, 0, "%s", name_build[Interface_build.id]);
    al_draw_textf(font[12], al_map_rgb(29, 167, 169), 845, 187, 0, "%d", Interface_build.level);

    if(build[Interface_build.pos].level < Max_level[build[Interface_build.pos].id]){
        al_draw_bitmap(interface_image[6], 894, 254, 0);
        if(cx >= 895 && cx < 920 && cy >= 255 && cy <= 285){
            al_draw_textf(font[16], al_map_rgb(29, 167, 169), 500, 3, ALLEGRO_ALIGN_CENTRE, "Tr:-%d", build[Interface_build.pos].level * price_build[build[Interface_build.pos].id]);
            al_draw_textf(font[16], al_map_rgb(29, 167, 169), 600, 3, ALLEGRO_ALIGN_CENTRE, "Man:%d", build[Interface_build.pos].level * Man_num[build[Interface_build.pos].id]);
            if(build[Interface_build.pos].level * price_build[build[Interface_build.pos].id] > Transformirum || -build[Interface_build.pos].level * Man_num[build[Interface_build.pos].id] > Man){
                al_draw_bitmap(interface_image[51], 425, 0, 0);
            }
            else{
                al_draw_bitmap(interface_image[50], 425, 0, 0);
            }
        }
    }

    al_draw_textf(font[16], al_map_rgb(29, 167, 169), 10, 3, 0, "Tr:%i", Transformirum);
    al_draw_textf(font[16], al_map_rgb(29, 167, 169), 60 + ColNum(Transformirum) * 16, 3, 0, "Man:%i", Man);
    al_draw_textf(font[16], al_map_rgb(29, 167, 169), 120 + ColNum(Transformirum) * 16 + ColNum(Man) * 16, 3, 0, "Time:%d", (int)TimeGame);

    al_draw_bitmap(interface_image[38], 0, 390, 0);
    for(int i = 0; i < build.size(); i ++){
        al_draw_pixel(build[i].pos_x, build[i].pos_y + 401, al_map_rgb(100, 255, 100));
        al_draw_pixel(build[i].pos_x, build[i].pos_y + 402, al_map_rgb(100, 255, 100));
        al_draw_pixel(build[i].pos_x + 1, build[i].pos_y + 401, al_map_rgb(100, 255, 100));
        al_draw_pixel(build[i].pos_x + 1, build[i].pos_y + 402, al_map_rgb(100, 255, 100));
    }
    for(int i = 0; i < transport.size(); i ++){
        al_draw_pixel(transport[i].pos_x / 32, transport[i].pos_y / 32 + 401, al_map_rgb(150, 255, 100));
    }
    for(int i = 0; i < unit.size(); i ++){
        al_draw_pixel((unit[i].pos_x + 16) / 32, (unit[i].pos_y + 16) / 32 + 401, al_map_rgb(241, 154, 154));
    }
    for(int i = 0; i < enemyBuild.size(); i ++){
        al_draw_pixel(enemyBuild[i].pos_x, enemyBuild[i].pos_y + 401, al_map_rgb(239, 180, 50));
        al_draw_pixel(enemyBuild[i].pos_x, enemyBuild[i].pos_y + 402, al_map_rgb(239, 180, 50));
        al_draw_pixel(enemyBuild[i].pos_x + 1, enemyBuild[i].pos_y + 401, al_map_rgb(239, 180, 50));
        al_draw_pixel(enemyBuild[i].pos_x + 1, enemyBuild[i].pos_y + 402, al_map_rgb(239, 180, 50));
    }
    for(int i = 0; i < PlayerPoint.size(); i ++){
        al_draw_pixel(PlayerPoint[i].pos_x, PlayerPoint[i].pos_y + 401, al_map_rgb(255, 255, 255));
    }
    al_draw_rectangle(offset_x / 32, 401 + offset_y / 32, (offset_x + 1000) / 32, 401 + (offset_y + 600) / 32, al_map_rgb(255, 255, 100), 1);

    switch(build[Interface_build.pos].id){
    case 3:
        al_draw_bitmap(interface_image[39], 862, 318, 0);
        if(open_dialog[2]){
            al_draw_bitmap(interface_image[40], 100, 100, 0);
            for(int i = 0; i < 16; i ++){
                al_draw_bitmap(interface_image[41], 128 + 40 * i, 127, 0);
                al_draw_bitmap(interface_image[10 + i], 131 + 40 * i, 133, 0);
                al_draw_textf(font[12], al_map_rgb(0, 0, 0), 145 + 40 * i, 163, ALLEGRO_ALIGN_CENTRE, "%i", substance[i]);
                for(int j = 0; j < 5; j ++){
                    if(Technology[i][j]){
                        al_draw_bitmap(interface_image[42], 128 + 40 * i, 127 + (j + 1) * 65, 0);
                        if(technology_image[i][j] != NULL){
                            al_draw_bitmap(technology_image[i][j], 132.5 + 40 * i, 132.5 + (j + 1) * 65, 0);
                        }
                    }
                }
            }
        }
        break;
    case 4:
        al_draw_bitmap(interface_image[43], 862, 318, 0);
        if(open_dialog[3]){
            for(int i = 1; i < 6; i ++){
                al_draw_bitmap(interface_image[4], 839 - 46 * (6 - i), 500, 0);
                if(openTransport[i - 1] && transport_image[i][0] != NULL)
                    al_draw_bitmap(transport_image[i][0], 851 - 46 * (6 - i), 510, 0);
            }
            if(cx < 839 && cx > 609 && cy > 500 && cy < 560){
                if(Transformirum < PriceTransport[(cx - 586) / 46] && Man > 0)
                    al_draw_textf(font[16], al_map_rgb(105, 10, 10), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%s, Tr:-%d, Man:-1", name_transport[(cx - 609) / 46], PriceTransport[(cx - 609)/46]);
                else
                    al_draw_textf(font[16], al_map_rgb(10, 105, 10), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%s, Tr:-%d, Man:-1", name_transport[(cx - 609) / 46], PriceTransport[(cx - 609)/46]);
            }
        }
        break;
    }
    //if(UnitMap[(int)(cx + offset_x) / 32][(int)(cy + offset_y) / 32][0] > 0)
        al_draw_textf(font[16], al_map_rgb(255, 255, 255), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%d", map2[(int)(cx + offset_x) / 32][(int)(cy + offset_y) / 32]);
    /*for(int i = min_x; i <= max_x; i ++){
        for(int j = min_y; j <= max_y; j ++){
            //if(map[i][j] >= 10)
            al_draw_textf(font[16], al_map_rgb(255, 255, 255), i * 32 - offset_x + 5, j * 32 - offset_y + 5, ALLEGRO_ALIGN_CENTRE, "%d", UnitMap[i][j][2]);
        }
    }*/
    //int unitNum = UnitMap[(int)(cx + offset_x) / 32][(int)(cy + offset_y) / 32][1] - 1;
    //al_draw_textf(font[16], al_map_rgb(255, 255, 255), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%d %d", (int)(cx + offset_x) / 32, (int)(cy + offset_y) / 32);
    //if(unitNum >= 0){
    //    al_draw_textf(font[16], al_map_rgb(255, 255, 255), cx, cy - 60, ALLEGRO_ALIGN_CENTRE, "%d %d %d %d %d",(int)(unit[unitNum].alpha), (int)(unit[unitNum].alpha_k / one_grad), unit[unitNum].Goal, unit[unitNum].MapGoalX, unit[unitNum].MapGoalY);
    //}
}

void Main_Menu(){

}

void Main_Menu_Mouse(){
    if(cx >= 0 && cx <= 243 && cy >= 100 && cy <= 146)
        Mode = 1;
    else if(cx >= 111 && cx <= 320 && cy >= 500 && cy <= 546)
        doexit = true;
}

void Main_Menu_Draw(){
    min_x = (offset_x + 340) / 32;
    max_x = (offset_x + SCREEN_W) / 32 + 1;
    min_y = offset_y / 32 - 1;
    max_y = (offset_y + SCREEN_H) / 32 + 1;
    for(int i = min_x; i <= max_x; i ++){
        for(int j = min_y; j < max_y; j ++){
            //cout << map[(int)(i + offset_x / 32)][(int)(j + offset_y / 32)] << " ";
            if(map[i][j] >= 10)
                al_draw_bitmap(map_image[map[i][j]], i * 32 - offset_x, j * 32 - offset_y, 0);
        }
    }
    for(int i = 0; i < build.size(); i ++){
        if(build[i].pos_x >= min_x && build[i].pos_x <= max_x
        && build[i].pos_y >= min_y && build[i].pos_y <= max_y){
            al_draw_bitmap(build_image[build[i].id * 10 + build[i].level - 1][build[i].num_image], build[i].pos_x * 32 - offset_x, build[i].pos_y * 32 - offset_y, 0);
            if(build[i].num_image < build[i].max_num_image){
                build[i].num_image ++;
            }
            else{
                build[i].num_image = 0;
            }
        }
        if(build[i].Construction < 6)
            al_draw_bitmap(Construction_image[build[i].Construction], build[i].pos_x * 32 - offset_x, build[i].pos_y * 32 - offset_y, 0);
    }

    for(int i = 0; i < transport.size(); i ++){
        if(transport[i].pos_x >= offset_x + 340 && transport[i].pos_x <= offset_x + 800 &&
           transport[i].pos_y >= offset_y && transport[i].pos_y <= offset_y + 600){
            al_draw_rotated_bitmap(transport_image[transport[i].id][0], 10, 10, transport[i].pos_x - offset_x, transport[i].pos_y - offset_y, transport[i].alpha, 0);
            //cout << transport[i].Job;
        }
    }

    if(cx >= 0 && cx <= 243 && cy >= 100 && cy <= 146)
        al_draw_bitmap(interface_image[32], 0, 100, 0);
    else
        al_draw_bitmap(interface_image[30], 0, 100, 0);

    if(cx >= 111 && cx <= 320 && cy >= 500 && cy <= 546)
        al_draw_bitmap(interface_image[34], 111, 500, 0);
    else
        al_draw_bitmap(interface_image[33], 111, 500, 0);

    al_draw_bitmap(interface_image[31], 320, 0, 0);
    //al_draw_textf(font[16], al_map_rgb(0, 0, 0), cx, cy - 40, ALLEGRO_ALIGN_CENTRE, "%d %d", (cx + offset_x) / 32, (cy + offset_y) / 32);
}

int main(int argc, char **argv)
{
    //freopen("debug.out", "wt", stdout);
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
    al_reserve_samples(1);

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
    Init();

    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_draw_bitmap(build_image[100][0], 0, 0, 0);

    al_flip_display();
    al_start_timer(timer);
    al_hide_mouse_cursor(display);

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
                case 1:
                    Game_Mode();
                break;
                case 2:
                    Main_Menu();
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
            Chet(ev.keyboard.keycode);
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
                case ALLEGRO_KEY_SPACE:
                        Debug = !Debug;
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
            switch(Mode){
            case 1:
                Game_Mode_Mouse();
                break;
            case 0:
                Main_Menu_Mouse();
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            key[mouse_1] = false;
        }
        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            al_clear_to_color(al_map_rgb(255, 255, 255));
            switch(Mode){
            case 1:
                Game_Mode_Draw();
                break;
            case 0:
                Main_Menu_Draw();
                break;
            }
            al_draw_bitmap(interface_image[35], cx, cy, 0);
            al_flip_display();
        }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    Save();
    return 0;
}

