#include <cstdio>
#include <algorithm>
int n, t, a[300009];

int main() {
    int tmp, maxIn, maxVal, sameIn;
    bool flag, flag2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        maxIn = 0;
        maxVal = 0;
        sameIn = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            a[i] = tmp;
            if (maxVal < tmp) {
                maxIn = i;
                maxVal = tmp;
                sameIn = -1;
            }
            else if(maxVal == tmp) {
                sameIn = i;
            }
        }
        flag = false;
        flag2 = false;
        if (1<= maxIn) {
            if (a[maxIn-1] != maxVal) flag = true;
        }
        if (maxIn <= n-2) {
            if (a[maxIn+1] != maxVal) flag = true;
        }
        if (1<= sameIn) {
            if (a[sameIn-1] != maxVal) flag2 = true;
        }
        if (sameIn <= n-2) {
            if (a[sameIn+1] != maxVal) flag2 = true;
        }
        if(flag) printf("%d\n", maxIn+1);
        else if(flag2) printf("%d\n", sameIn+1);
        else printf("-1\n");
    }
}