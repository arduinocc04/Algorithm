#include <cstdio>

unsigned long long n, dp[1010][10];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) for(int j = 0; j < 10; j++) dp[i][j] = 0;
    for(int i = 0; i < 10; i++) dp[0][i] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 10; i++) res += dp[n-1][i];
    printf("%d", res % 10007);
}