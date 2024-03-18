#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_DISABLED_BUTTON_CNT 11

int count_plus_or_minus(int src, int dst) {
    return std::abs(dst - src);
}

int main() {
    int to_go, disabled_button_cnt;
    std::vector<bool> is_disabled(MAX_DISABLED_BUTTON_CNT);

    std::cin >> to_go;
    std::cin >> disabled_button_cnt;

    int disabled_button;
    for(int i = 0; i < disabled_button_cnt; ++i) {
        std::cin >> disabled_button;
        is_disabled[disabled_button] = true;
    }

    int min_val = count_plus_or_minus(100, to_go);

    for(int i = is_disabled[0]; i < 1'000'010; ++i) {
        int t = i;
        bool possible = true;
        int length = 0;
        do {
            if(is_disabled[t % 10]) {
                possible = false;
                break;
            }
            ++length;
            t /= 10;
        }while(t != 0);

        if(possible)
            min_val = std::min(min_val, count_plus_or_minus(i, to_go) + length);
    }

    std::cout << min_val;
    return 0;
}
