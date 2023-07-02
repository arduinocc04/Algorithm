#include <cstdio>

int n, v[10'010];
long long ans = 0;

long long calc(int n) {
    long long res = 1;
    int cnt = 0;
    int prev = v[n];
    while(n != 1) {
        n /= v[n];
        cnt++;
        if(v[n] != prev || n == 1) {
            res *= cnt + 1;
            cnt = 0;
        }
        prev = v[n];
    }
    return res;
}

int main() {
    for(int i = 0; i < 10'010; i++) v[i] = i;
    for(int i = 2; i < 10'010; i++) {
        if(v[i] != i) continue;
        for(int j = i; i + j < 10'010; j += i) {
            if(v[i+j] == v[i+j]) v[i+j] = i;
        }
    }

    scanf("%d", &n);

    // printf("%d\n", calc(12));

    for(int i = 1; i <= n; i++) {
        ans += calc(i)/2 + calc(i)%2;
        // printf("%d: %d\n", i, ans);
    }

    printf("%lld", ans);
}