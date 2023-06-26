#include <cstdio>

int T, k, ncr[15][15];

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= b;
    return res;
}

int calc(int x) {
    int cnt = 1;
    int tmp = 10;
    int res = 1;
    while(true) {
        if(!(x / tmp)) break;
        cnt++;
        tmp *= 10;
    }
    for(int i = 1; i <= cnt -1; i++) {
        for(int j = 1; j <= i; j++) {
            res += ncr[i][j]*pow(8, i - j) - 1;
        }
    }

}

int main() {
    for(int i = 0; i < 15; i++) ncr[i][0] = 1;
    for(int i = 0; i < 15; i++) ncr[0][i] = 0;
    for(int i = 1; i < 15; i++) ncr[i][1] = i;
    for(int i = 2; i < 15; i++) {
        for(int j = 2; j < 15; j++) {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &k);

    }
    return 0;
}
