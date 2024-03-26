#include <iostream>
#include <algorithm>

#define MOD 1'000'000'000

int dp[110][11][11][11], n;

int main() {
    std::cin >> n;
    for(int i = 1; i <= 9; ++i)
        dp[1][i][i][i] = 1;

    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int m = 0; m <= 9; ++m) {
                for(int M = m + 1; M <= 9; ++M) {
                    if(j != 0) {
                        if(m <= j - 1 && j - 1 <= M) {
                            dp[i][j][m][M] += dp[i - 1][j - 1][m][M];
                            dp[i][j][m][M] %= MOD;
                        }
                        if(j == M) {
                            dp[i][j][m][M] += dp[i - 1][j - 1][m][M - 1];
                            dp[i][j][m][M] %= MOD;
                        }
                    }
                    if(j != 9) {
                        if(m <= j + 1 && j + 1 <= M) {
                            dp[i][j][m][M] += dp[i - 1][j + 1][m][M];
                            dp[i][j][m][M] %= MOD;
                        }
                        if(j == m) {
                            dp[i][j][m][M] += dp[i - 1][j + 1][m + 1][M];
                            dp[i][j][m][M] %= MOD;
                        }
                    }
                }
            }
        }
    }

    int s = 0;
    for(int i = 0; i <= 9; ++i) {
        s = (s + dp[n][i][0][9]) % MOD;
    }

    std::cout << s;
}
