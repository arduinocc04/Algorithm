#include <cstdio>
int T, n, p, k, x, y, last, dp[100010];
char a[100010];
int min(int a, int b) {
    if(a < b) return a;
    return b;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &p, &k);
        p--;
        scanf("%s", a);
        scanf("%d %d", &x, &y);
        for(int i = p; i < n; i++) {
            dp[i] = (i-p)*y;
        }
        int res = 1234567891;
        for(int i = p; i <= p+k; i++) {
            if(a[i] == '0') {
                    dp[i] += x;
            }
        }
        for(int i = p + k; i < n; i++) {
            if(a[i] == '0') {
                dp[i] = min(dp[i], dp[i-k] + x);
            }
            else{
                dp[i] = min(dp[i], dp[i-k]);
            }
        }
        
        printf("DP: ");
        for(int i = 0; i < n; i++) printf("%d ", dp[i]);
        printf("\n");
        
        for(int i = n-1; i >= n-k; i--) {
            res = min(res, dp[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}