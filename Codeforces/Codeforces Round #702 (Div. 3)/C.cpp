#include <cstdio>

int T;
unsigned long long x, l, r, mid, cubes[10010], tmp;
int main() {
    scanf("%d", &T);
    for(unsigned long long i = 1; i*i*i < 1e12+10; i++) {
        cubes[i] = i*i*i;
    }
    while(T--) {
        scanf("%lld", &x);
        for(unsigned long long i = 1; cubes[i] < x; i++) {
            l = 0, r = 10010, tmp = x - cubes[i];
            while(l+1 < r) {
                mid = (l+r)/2;
                if(cubes[mid] > tmp) r = mid;
                else l = mid;
            }
            if(cubes[l] + cubes[i] == x || cubes[r] + cubes[i] == x) {
                printf("YES\n");
                goto nwe;
            }
        }
        printf("NO\n");
        nwe:
        continue;
    }
    return 0;
}
