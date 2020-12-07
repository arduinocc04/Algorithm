#include <cstdio>
#include <algorithm>
#define MAX 1010
int n, p[MAX], dp[MAX];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    dp[1] = p[0];
    for(int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i-1] + dp[1], p[i-1]);
        for(int j = 1; j < i; j++) for(int k = j; k < i; k++) if(j + k == i) dp[i] = std::max(dp[i], dp[j] + dp[k]);
    }
    printf("%d", dp[n]);
}