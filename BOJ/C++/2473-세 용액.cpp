#include <iostream>
#include <algorithm>
#include <cstdlib>

int n, a[5'010], ans[3];
long long min_dist = 3'000'000'010;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a, a + n);

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            const int target = -a[i] - a[j];
            auto lower = std::lower_bound(a, a + n, target);
            if(lower != a) {
                if(lower - 1 != a + i && lower - 1 != a + j) {
                    const long long t = std::abs(static_cast<long long>(a[i]) + a[j] + *(lower - 1));
                    if(min_dist > t) {
                        min_dist = t;
                        ans[0] = a[i], ans[1] = a[j], ans[2] = *(lower - 1);
                    }
                }
            }
            if(lower != a + n) {
                if(lower != a + i && lower != a + j) {
                    const long long t = std::abs(static_cast<long long>(a[i]) + a[j] + *lower);
                    if(min_dist > t) {
                        min_dist = t;
                        ans[0] = a[i], ans[1] = a[j], ans[2] = *lower;
                    }
                }
            }
        }
    }

    std::sort(ans, ans + 3);

    std::cout << ans[0] << " " << ans[1] << " " << ans[2];
}
