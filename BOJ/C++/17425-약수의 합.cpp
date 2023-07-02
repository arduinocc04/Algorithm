#include <cstdio>

int T, n;
long long v[1'000'010], ps[1'000'010];

int main() {
    for(int i = 0; i < 1'000'010; i++) v[i] = 0;
    for(int i = 1; i < 1'000'005; i++) {
        v[i] += i;
        for(int j = i; i + j < 1'000'005; j += i) {
            v[i + j] += i;
        }
    }
    ps[0] = v[0];
    for(int i = 1; i < 1'000'010; i++) {
        ps[i] = v[i] + ps[i-1];
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        printf("%lld\n", ps[n]);
    }
}