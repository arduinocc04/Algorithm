#include <cstdio>

int r, c, map[760][760], diagru[760][760], diaglu[760][760];

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);
            map[i][j] -= '0';
        }
    }
    for(int i = 0; i < r; i++) diagru[i][0] = map[i][0];
    for(int i = 0; i < c; i++) diagru[r - 1][i] = map[r-1][i];

    for(int i = 1; i < r; i++) {
        for(int j = 1; j <= i; j++) {
            diagru[i - j][j] = diagru[i - (j - 1)][j-1] + map[i - j][j];
        }
    }
    for(int i = 1; i < r - 1; i++) {
        for(int j = 1; j <= i; j++) {
            diagru[r - i - j][j] = diagru[i - (j-1)][j-1] + map[i - j][j];
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", diagru[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < r; i++) diaglu[i][c - 1] = map[i][c - 1];
    for(int i = 0; i < c; i++) diaglu[r - 1][i] = map[r-1][i];
}