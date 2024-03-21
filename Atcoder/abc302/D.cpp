#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

std::vector<long long> a, b;

long long n, m, d;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> d;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    for(int i = 0; i < m; ++i)
        std::cin >> b[i];

    std::sort(b.begin(), b.end());

    long long ans = -1;
    for(int i = 0; i < n; ++i) {
        const long long max_val = a[i] + d;
        auto upper = std::upper_bound(b.begin(), b.end(), max_val);

        if(upper == b.end()) {
            if(std::abs(b[b.size() - 1] - a[i]) <= d) {
                ans = std::max(ans, a[i] + b[b.size() - 1]);
            }
        }
        if(upper != b.end() && upper != b.begin()) {
            const long long val = *(upper - 1);
            if(a[i] - val <= d)
                ans = std::max(ans, a[i] + val);
        }
    }

    std::cout << ans;
}