#include <cstdio>
#include <cmath>

int n, k, rgbs[110][3];
long double r, g, b, res;

long double getDistSquared(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);
}

long double min(long double a, long double b) {
    if(a > b) return b;
    return a;
}

long double calc(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2) {
    bool c[110];
    long double tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, tmp5 = 0, tmp6 = 0;
    int cnt1, cnt2;
    for(int j = 0; j < 100; j++) {
        cnt1 = 0, cnt2 = 0;
        tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, tmp5 = 0, tmp6 = 0;
        for(int i = 0; i < n; i++) {
            if(getDistSquared(x1, y1, z1, rgbs[i][0], rgbs[i][1], rgbs[i][2]) > getDistSquared(x2, y2, z2, rgbs[i][0], rgbs[i][1], rgbs[i][2])) {
                c[i] = true;
                tmp1 += rgbs[i][0];
                tmp2 += rgbs[i][1];
                tmp3 += rgbs[i][2];
                cnt1++;
            }
            else {
                c[i] = false;
                tmp4 += rgbs[i][0];
                tmp5 += rgbs[i][1];
                tmp6 += rgbs[i][2];
                cnt2++;
            }
        }
        x1 = tmp1/cnt1, y1 = tmp2/cnt1, z1 = tmp3/cnt1;
        x2 = tmp4/cnt2, y2 = tmp5/cnt2, z2 = tmp6/cnt2;
    }
    long double res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++) {
        if(c[i]) {
            res1 += getDistSquared(x1, y1, z1, rgbs[i][0], rgbs[i][1], rgbs[i][2]);
        }
        else {
            res2 += getDistSquared(x2, y2, z2, rgbs[i][0], rgbs[i][1], rgbs[i][2]);
        }
    }
    return res1 + res2;

}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d %d %d", &rgbs[i][0], &rgbs[i][1], &rgbs[i][2]);
    if(k == 1) {
        r = 0; g = 0; b = 0;
        for(int i = 0; i < n; i++) {
            r += rgbs[i][0];
            g += rgbs[i][1];
            b += rgbs[i][2];
        }
        r/= n; g /= n; b /= n;
        res = 0;
        for(int i = 0; i < n; i++) {
            res += std::pow(rgbs[i][0] - r, 2) + std::pow(rgbs[i][1] - g, 2) + std::pow(rgbs[i][2] - b, 2);
        }
        printf("%.6Lf", res);
    }
    else {
        long double res = min(calc(0, 0, 0, 1000, 1000, 1000), calc(0, 500, 0, 500, 0, 500));
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                res = min(res, calc(rgbs[i][0], rgbs[i][1], rgbs[i][2], rgbs[j][0], rgbs[j][1], rgbs[j][2]));
            }
        }
        printf("%.6Lf", res);
    }
    return 0;
}