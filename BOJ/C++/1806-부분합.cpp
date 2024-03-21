#include <iostream>
#include <algorithm>

unsigned int n, s, a[100'010];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> s;
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    unsigned int l = 0, r = 0, min_len = 987654321, now_s = 0;

    while(true) {
        if(r < n) {
            if(now_s < s) {
                now_s += a[r];
                ++r;
            }
            else {
                min_len = std::min(min_len, r - l);
                now_s -= a[l];
                ++l;
            }
        }
        else {
            if(now_s < s)
                break;
            else {
                min_len = std::min(min_len, r - l);
                now_s -= a[l];
                ++l;
            }
        }
    }
    if(min_len == 987654321)
        std::cout << 0;
    else
        std::cout << min_len;
}
