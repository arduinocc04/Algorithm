#include <iostream>

int n , m, a[2'010];
bool dp[2'010][2'010];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    for(int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for(int i = n - 2; i >= 0; --i) {
        for(int j = i + 1; j < n; ++j) {
            if((j - i) == 1)
                dp[i][j] = (dp[i][j - 1] && (a[i] == a[j]));

            dp[i][j] = (dp[i][j] || (dp[i + 1][j - 1] && (a[i] == a[j])));
        }
    }

    std::cin >> m;

    for(int i = 0; i < m; ++i) {
        int s, e;
        std::cin >> s >> e;
        std::cout << dp[s - 1][e - 1] << "\n";
    }

    return 0;
}
