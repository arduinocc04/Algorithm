#include <iostream>

bool change_possible[50];
int people[50];
int vip[50];
int n, m, dp[50] = {0, };

int calc(int len) {
    if(len <= 3) return len;
    if(dp[len] != 0) return dp[len];
    return dp[len] = calc(len - 2) + calc(len - 1);
}

int main() {
    std::cin >> n;
    std::cin >> m;
    for(int i = 0; i < m; ++i) {
        std::cin >> vip[i];
    }
    for(int i = 1; i <= n; ++i) {
        change_possible[i] = true;
    }
    for(int i = 0; i < m; ++i) {
        change_possible[vip[i]] = false;
    }

    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        while(i + cnt <= n && change_possible[i + cnt])
            ++cnt;
        if(cnt == 0) continue;
        ans *= calc(cnt);
        if(i + cnt > n) break;
        i += cnt;
    }

    std::cout << ans;
}
