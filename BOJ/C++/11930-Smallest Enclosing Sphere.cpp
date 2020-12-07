#include <cstdio>
#include <math.h>
#include <utility>

#define ROUNDING(x, dig)	( floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig) )
int n;
double dots[1001][3];
double getDistanceDoubled(double p1[], double p2[]) {
    return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]) + (p1[2]-p2[2])*(p1[2]-p2[2]);
}
int main(){
    scanf("%d",&n);
    double x, y, z;
    for(int i=0;i<n;i++){
        scanf("%lf %lf %lf", &x, &y, &z);
        dots[i][0] = x;
        dots[i][1] = y;
        dots[i][2] = z;
    }
    x = 0;
    y = 0;
    z = 0;
    for(int i=0;i<n;i++){
        x += dots[i][0];
        y += dots[i][1];
        z += dots[i][2];
    }
    x /= (double)n;
    y /= (double)n;
    z /= (double)n;
    double ratio = 0.1;
    double maxVal, tmp;
    for(int i = 0; i < 20000; i++) {
        double point[3] = {x,y,z};
        maxVal = 0;
        int maxIn = 0;
        for(int j = 0; j < n; j++) {
            tmp = getDistanceDoubled(point, dots[j]);
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
    printf("%.2lf", ROUNDING(sqrt(maxVal),2));
}
