#include <cstdio>

int T, n, x1, y1, x2, y2;

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int abs(int x) {
    if(x > 0) return x;
    return -x;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
        if(x1 > n/2) x1 = n/2 - (x1 - n/2 -1);
        if(x2 > n/2) x2 = n/2 - (x2 - n/2 -1);
        if(y1 > n/2) y1 = n/2 - (y1 - n/2 -1);
        if(y2 > n/2) y2 = n/2 - (y2 - n/2 -1);
        int startBelt = min(x1, y1);
        int endBelt = min(x2, y2);
        printf("%d\n", abs(startBelt - endBelt));
    }
    return 0;
}
