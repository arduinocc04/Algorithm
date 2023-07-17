#include <cstdio>
#include <math.h>

int n;
char res[2600][2600];

void calc(int depth, int r1, int c1, int r2, int c2, int r3, int c3) {
    if(depth == 1) {
        res[r2][c2] = '*';
        return;
    }
    
    if(r1 == r2) {
        for(int i = c1; i <= c2; i++) {
            res[r1][i] = '*';
        }
        int midc12 = c3;
        for(int i = c1; i <= midc12; i++) {
            res[r1 + i - c1][i] = '*';
            res[r2 + i - c1][c2 - i + c1] = '*';
        }
        int midr13 = (r1 + r3)/2;

        calc(depth - 1, r1, midc12, midr13, (c1 + midc12)/2 + 1, midr13, (c2 + midc12)/2 + 1);
        return;
    }

    for(int i = c2; i <= c3; i++) {
        res[r2][i] = '*';
    }
    int midc23 = c1;
    for(int i = c2; i <= c1; i++) {
        res[r2 - i + c2][i] = '*';
        res[r3 - i + c2][c3 - i + c2] = '*';
    }
    int midr12 = (r1 + r2)/2;
    calc(depth - 1, midr12, (c1 + c2)/2 + 1, midr12, (c1 + c3)/2 + 1, r2, c1);
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 2600; i++) {
        for(int j = 0; j < 2600; j++) res[i][j] = ' ';
    }
    if(n % 2) {
        calc(n, 0, std::pow(2, n) - 2, std::pow(2, n) - 2, 0, std::pow(2, n) - 2, std::pow(2, n+1)-4);
    }
    else {
        calc(n, 0, 0, 0, std::pow(2, n+1)-4, std::pow(2, n) - 2, std::pow(2, n) - 2);
    }
    for(int r = 0; r <= std::pow(2, n) - 2; r++) {
        for(int c = 0; c <= std::pow(2, n+1) - 4 - r; c++) {
            printf("%c", res[r][c]);
        }
        printf("\n");
    }
}