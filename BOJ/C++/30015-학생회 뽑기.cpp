#include <iostream>
#include <algorithm>

int n, k, a[200'010];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> k;
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    int m = 0;
    for(int i = 19; i >= 0; --i) {
        int c = 1 << i;
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            if(a[j] & c)
                cnt++;
        }
        if(cnt >= k) {
            for(int j = 0; j < n; ++j) {
                if(!(a[j] & c))
                    a[j] = 0;
            }
            m |= c;
        }
    }

    std::cout << m << std::endl;

    return 0;
}
