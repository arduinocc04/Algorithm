#include <cstdio>

int T, n, a[200010], tmp, cnt, b[200010], cnt2, i;
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
int max(int a, int b) {
    if(a > b) return a;
    return b;
}
int main() {
    scanf("%d", &T);
    while(T--)  {
        scanf("%d", &n);
        cnt = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        long long res = 0;
        int maxVal = a[1] - a[0];
        int maxIn = 0;
        for(int i = 0; i < n-1; i++) {
            res += abs(a[i+1] - a[i]);
            if (maxVal < abs(a[i+1] - a[i])) {
                maxVal = abs(a[i+1] - a[i]);
                maxIn = i;
            }
        }
        printf("maxin: %d\n", maxIn);
        /*
        if(maxIn == n-2) {
            a[n-2] = a[n-1];
        }
        else if (maxIn == 0) {
            a[0] = a[1];
        } */
        {   
            if(maxIn == 0) {
                a[maxIn] = a[maxIn + 1];
            }
            else if(maxIn + 2 >= n) {
                a[maxIn+1] = a[maxIn];
            }
            else if(abs(a[maxIn + 2] - a[maxIn]) > abs(a[maxIn + 1] - a[maxIn - 1])) {
                a[maxIn] = a[maxIn + 1];
            }
            else {
                a[maxIn+1] = a[maxIn];
            }
        }
        res = 0;
        for(int i = 0; i < n-1; i++) {
            res += abs(a[i+1] - a[i]);
        }
        printf("%lld\n", res);
    }
}