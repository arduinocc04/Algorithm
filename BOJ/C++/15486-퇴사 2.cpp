#include <iostream>
#include <algorithm>

int main() {
    std::cout << "Hi!";
    int n, dp[1500001], c, d,b;
    std::pair<int, int> a[1500000];
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> c >> d;
        a[i] = std::make_pair(c,d);
    }
    for(int i = 0; i < n; i++) {
        if(i+1 >= n) {
            c = 1;
        }
        else {
            c = a[i+1].first;
        }
        for(int j = 0; j < c; j++) {
            b = a[i].first + i + j;
            if(b <= n) {
                dp[b] = std::max(dp[b], a[i].second + dp[i]);
            }
            else {
                break;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n+1; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    std::cout << max;
    return 0;
}