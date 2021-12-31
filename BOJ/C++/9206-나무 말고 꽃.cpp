#include <cstdio>
#include <cmath>
#define N 500000
double v, flowers[7][3];
int n, res;
double a, b, h, tmp, diff = 10000000, prev, newVal;


double f(double x) {
    double tmp= a * exp(-x*x) + b * sqrtf(x);
    return tmp * tmp * M_PI;
}

double absf(double x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    scanf("%lf %d", &v, &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &a, &b, &h);
        double m = h/N;
        double tmp = 0;
        prev = f(0);
        for(int j = 1; j <= N; j++) {
            newVal = f(j*m);
            tmp += (newVal + prev)*m/2;
            prev = newVal;
        }
        if(absf(v - tmp) < diff) {
            diff = absf(v-tmp);
            res = i;
        }
        //printf("%lf\n", tmp);
    }
    printf("%d\n", res);
}