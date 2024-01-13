#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <cstdio>
#define MOD 786'433

int n, k, a[250'010], x;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n + 1; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &x);
        long long ans = a[n];
        for(int j = n - 1; j >= 0; j--)
            ans = (ans*x + a[j]) % MOD;
        printf("%lld\n", ans);
    }
}
