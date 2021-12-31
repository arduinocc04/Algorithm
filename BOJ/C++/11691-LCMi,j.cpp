#include <cstdio>
#include <vector>
int prime[1000010];
int  n, dp[1000010];
const int mod = 1e9 + 7;

int eulerphi(int x) {
    int ret = 1;
    int p = 1;
    int start;
    if(prime[x] == x) return x-1;
    while(x != 1) {
        start = prime[x];
        p = 1;
        while(start == prime[x]) {
            p *= prime[x];
            x /= prime[x];
        }
        ret *= (p - p/start);
    }
    if(x != 1) ret *= (x - 1);
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i = 2; i < 1000010; i++) prime[i] = i;
    for(int i = 2; i < 1010; i++) {
        if(prime[i] != i) continue;
        for(int j = i*i; j < 1000010; j += i) {
            if(j < 0) break;
            if (prime[j] == j) prime[j] = i;
        }
    }
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + ((i*i)%mod)*eulerphi(i)/2)%mod;
    }
    long long ans = 0;
    for(int j = 1; j <= n; j++) {
        ans = (ans + j*dp[n/j]) % mod;
    }
    printf("%lld", ans);
}