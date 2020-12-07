#include <cstdio>

int n, r, c, cnt;

void calc(int sX, int sY, int eX, int eY) {
    if(sX == eX && sY == eY) {
        cnt++;
        if(sY == r && sX == c) printf("%d", cnt);
        return;
    }
    calc(sX, sY, eX/2+1, eY/2+1); //0 0 1 1
    calc(eX/2+1, sY, eX, eY/2+1); // 1 0 3 
    calc(sX, eY/2+1, eX/2+1, eY);
    calc(eX/2+1, eY/2+1, eX, eY);
    return;
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    calc(0, 0, (1<<n)-1, (1<<n)-1);
}