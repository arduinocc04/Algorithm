#include <cstdio>

int n, video[65][65], resIdx;
char res[10'000];

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= a;
    return res;
}

int check(int sx, int ex, int sy, int ey) { // 모두 0이면 0, 모두 1이면 1, 다른 것이 있으면 -1 return.
    int std = video[sx][sy];
    for(int i = sx; i < ex; i++) {
        for(int j = sy; j < ey; j++) {
            if(std != video[i][j]) {
                return -1;
            }
        }
    }
    return std;
}

void calc(int sx, int ex, int sy, int ey) {
    int c = check(sx, ex, sy, ey);
    if(c != -1) {
        res[resIdx] = '0' + c;
        resIdx++;
    }
    else {
        res[resIdx] = '(';
        resIdx++;
        int mx = (sx + ex)/2;
        int my = (sy + ey)/2;
        calc(sx, mx, sy, my);
        calc(mx, ex, sy, my);
        calc(sx, mx, my, ey);
        calc(mx, ex, my, ey);
        res[resIdx] = ')';
        resIdx++;
    }
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &video[i][j]);
        }
    }
    calc(0, n, 0, n);
    for(int i = 0; i < resIdx; i++) {
        printf("%c", res[i]);
    }
}