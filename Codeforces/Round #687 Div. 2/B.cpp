//B.cpp
#include <cstdio>

int T, n, k, c[100010];

int calc(int color) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] != color) {
            i += k;
            i--;
            cnt++;
        }
    }
    return cnt;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        int res = calc(1);
        for(int i = 2; i < 101; i++) {
            res = min(res, calc(i));
        }
        printf("%d\n", res);
    }
    return 0;
}