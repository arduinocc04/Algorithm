#include <cstdio>
#include <cmath>

#define ROUNDING(x, dig)	(floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig))
int n;
long double dots[40][3];
long double getDistanceSquared(long double p1[], long double p2[]) {
    return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]) + (p1[2]-p2[2])*(p1[2]-p2[2]);
}
int main(){
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        long double x, y, z;
        for(int i = 0; i < n; i++){
            scanf("%Lf %Lf %Lf", &x, &y, &z);
            dots[i][0] = x;
            dots[i][1] = y;
            dots[i][2] = z;
        }
        x = 0.0;
        y = 0.0;
        z = 0.0;
        for(int i = 0; i < n; i++){
            x += dots[i][0];
            y += dots[i][1];
            z += dots[i][2];
        }
        x /= n;
        y /= n;
        z /= n;
        long double ratio = 0.1;
        long double maxVal, tmp;
        for(int i = 0; i < 10000; i++) {
            long double point[3] = {x,y,z};
            maxVal = 0;
            int maxIn = 0;
            for(int j = 0; j < n; j++) {
                tmp = getDistanceSquared(point, dots[j]);
                if(tmp > maxVal) {
                    maxVal = tmp;
                    maxIn = j;
                }
            }
            x += (dots[maxIn][0] - x)*ratio;
            y += (dots[maxIn][1] - y)*ratio;
            z += (dots[maxIn][2] - z)*ratio;
            ratio *= 0.995;
        }
        printf("%.9lf\n", sqrt(maxVal));
    }
    return 0;
}