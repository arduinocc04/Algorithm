#include <cstdio>
#define MOD 1'000'000'009
int T, n, 
long long dp[1'000'010];

int main() {
    scanf("%d", &T);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 1'000'000; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
   // for(int i =  0; i < 10; i++) printf("%d ", dp[i]);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    
}