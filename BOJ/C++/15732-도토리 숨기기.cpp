#include <iostream>
#include <tuple>

#define MAX_RULE_CNT 10'010

std::tuple<int, int, int> rules[MAX_RULE_CNT];
unsigned int box_cnt, rule_cnt, acorn_cnt;

unsigned int get_acorn_cnt(unsigned long long box_num) {
    unsigned long long sum = 0;

    int l, r, stride;
    for(int i = 0; i < rule_cnt; ++i) {
        std::tie(l, r, stride) = rules[i];
        if(box_num < l)
            continue;

        if(r <= box_num) {
            sum += 1 + (r - l)/stride;
        }
        else {
            sum += 1 + (box_num - l)/stride;
        }
    }

    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> box_cnt >> rule_cnt >> acorn_cnt;
    for(int i = 0; i < rule_cnt; ++i) {
        std::cin >> std::get<0>(rules[i]);
        std::cin >> std::get<1>(rules[i]);
        std::cin >> std::get<2>(rules[i]);
    }

    int l = 1, r = box_cnt + 1;
    while(l < r) {
        const unsigned long long mid = static_cast<unsigned long long>(l + r)/2;
        if(get_acorn_cnt(mid) >= acorn_cnt) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    std::cout << r << std::endl;
    return 0;
}
