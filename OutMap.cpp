#include <cstdio>

int main(){
    freopen("map.txt", "wt", stdout);
    for(int i = 0; i < 60; i ++){
        for(int j = 0; j < 100; j ++){
            if(i > 56)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}
