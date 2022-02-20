#include <cstdio>

int C, h, w, whiteCnt, ans;
bool map[25][25], start[25][25];
char inC[25];

int d[4][3][2] = {{{0, 0}, {1, 0}, {0, 1}}, {{0, 0}, {1, 0}, {1, 1}}, {{0, 0}, {-1, 1}, {0, 1}}, {{0, 0}, {0, 1}, {1, 1}}};

void fill(bool state[25][25]) {
    int firstI = -1, firstJ = -1;
    int tmpI, tmpJ;
    bool possible;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!state[i][j]) {
                firstI = i, firstJ = j;
                break;
            }
        }
        if(firstI != -1) break;
    }
    if(firstJ == -1) {
        ans++;
        return;
    }
    for(int i = 0; i < 4; i++) {
        possible = true;
        for(int j = 0; j < 3; j++) {
            tmpI = firstI + d[i][j][1], tmpJ = firstJ + d[i][j][0];
            if(tmpI < 0 || tmpI >= h || tmpJ < 0 || tmpJ >= w || state[tmpI][tmpJ]) {
                possible = false;
                break;
            }
        }
        if(possible) {
            for(int j = 0; j < 3; j++) {
                tmpI = firstI + d[i][j][1], tmpJ = firstJ + d[i][j][0];
                state[tmpI][tmpJ] = true;
            }
            fill(state);
            for(int j = 0; j < 3; j++) {
                tmpI = firstI + d[i][j][1], tmpJ = firstJ + d[i][j][0];
                state[tmpI][tmpJ] = false;
            }
        }
    }
    return;
}

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d", &h, &w);
        for(int i = 0; i < h; i++) {
            scanf("%s", inC);
            for(int j = 0; j < w; j++) {
                map[i][j] = (inC[j] == '.')?false:true;
                // printf("%d ", map[i][j]);
            }
            // printf("\n");
        }
        whiteCnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!map[i][j]) whiteCnt++;
            }
        }
        if(whiteCnt % 3) {
            printf("0\n");
            continue;
        }
        if(whiteCnt == 0) {
            printf("1\n");
            continue;
        }
        /*for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                start[i][j] = map[i][j];
            }
        }*/
        ans = 0;
        fill(map);
        printf("%d\n", ans);
    }
    return 0;
}