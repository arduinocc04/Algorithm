#include <cstdio>

int n, m, tmpX, tmpY, map[510][510], dp[510][510], d[3][2] = {{-1, 0}, {1, 0}, {0, 1}};
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0;k < 3; k++) {
                tmpY = j + d[k][0];
                tmpX = i + d[k][1];
                if(0 <= tmpY && tmpY <= n-1 && 0 <= tmpX && tmpX <= m-1 && map[i][j] > map[tmpX][tmpY]) {
                    dp[tmpX][tmpY] += dp[i][j];
                }
            }
        }
    }
    printf("%d", dp[m-1][n-1]);
}