#include <cstdio>
#include <cmath>
#define MAX 5010
int n, k, rgbs[MAX][2];
long double r, g, b, res;

long double getDistSquared(long double x1, long double y1, long double x2, long double y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

long double min(long double a, long double b) {
    if(a > b) return b;
    return a;
}

long double calc(long double x1, long double y1, long double x2, long double y2) {
    bool c[MAX];
    long double tmp1 = 0, tmp2 = 0, tmp4 = 0, tmp5 = 0;
    int cnt1, cnt2;
    for(int j = 0; j < 100; j++) {
        cnt1 = 0, cnt2 = 0;
        tmp1 = 0, tmp2 = 0, tmp4 = 0, tmp5 = 0;
        for(int i = 0; i < n; i++) {
            if(getDistSquared(x1, y1, rgbs[i][0], rgbs[i][1]) > getDistSquared(x2, y2, rgbs[i][0], rgbs[i][1])) {
                c[i] = true;
                tmp1 += rgbs[i][0];
                tmp2 += rgbs[i][1];
                cnt1++;
            }
            else {
                c[i] = false;
                tmp4 += rgbs[i][0];
                tmp5 += rgbs[i][1];
                cnt2++;
            }
        }
        x1 = tmp1/cnt1, y1 = tmp2/cnt1;
        x2 = tmp4/cnt2, y2 = tmp5/cnt2;
    }
    long double res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++) {
        if(c[i]) {
            res1 += getDistSquared(x1, y1, rgbs[i][0], rgbs[i][1]);
        }
        else {
            res2 += getDistSquared(x2, y2, rgbs[i][0], rgbs[i][1]);
        }
    }
    return res1 + res2;
}

int main() {
    scanf("%d %d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &rgbs[i][0], &rgbs[i][1]);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            res = min(res, calc(rgbs[i][0], rgbs[i][1], rgbs[j][0], rgbs[j][1]));
        }
    }
    printf("%.6Lf", res);
    return 0;
}