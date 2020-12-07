#include <cstdio>
#include <algorithm>
#define MAX 20
int n, dp[MAX], tmp, res, now;
std::pair<int, int> cs[MAX];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &cs[i].first, &cs[i].second);
    for(int i = 0; i < n; i++) dp[i] = 0;
    for(int i = 0; i < n; i++) for(int j = i; j < i + cs[i].first; j++) {
        tmp = j + cs[i].first;
        now = dp[i] + cs[i].second;
        if((tmp <= n) && (dp[tmp] < now)) dp[tmp] = now;
    }
    res = dp[0];
    for(int i = 0; i <= n; i++) if(res < dp[i]) res = dp[i];
    printf("%d", res);
    return 0;
}