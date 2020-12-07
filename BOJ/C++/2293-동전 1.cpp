#include <cstdio>
#include <algorithm>

unsigned int n, k, a[110], dp[10010];
int main() {
    scanf("%d %d", &n, &k);
    for(unsigned int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(unsigned int i = 0; i <= k; i++) dp[i] = 0;
    for(unsigned int i = 0; i < n; i++) dp[a[i]] = 1;
    for(unsigned int i = 2; i <= k; i++) {
        for(unsigned int j = 1; j <= i/2; j++) {
            dp[i] += dp[j] + dp[i - j];
        }
    }
    printf("%d", dp[k]);
    return 0;
}