#include <iostream>
#include <algorithm>

#define MAX_DISH_CNT 3'003'010
#define MAX_SUSHI_CATEGORY_CNT 3'010

int dish_cnt, sushi_category_cnt, consecutive_dish_cnt, given_sushi;
int dishes[MAX_DISH_CNT], sushi_cnt[MAX_SUSHI_CATEGORY_CNT];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> dish_cnt >> sushi_category_cnt >> consecutive_dish_cnt >> given_sushi;

    for(int i = 0; i < dish_cnt; ++i)
        std::cin >> dishes[i];

    for(int i = 0; i <= consecutive_dish_cnt; ++i) { // for circular..
        dishes[i + dish_cnt] = dishes[i];
    }

    int now_category_cnt = 0;
    for(int i = 0; i < consecutive_dish_cnt; ++i) {
        ++sushi_cnt[dishes[i]];
    }

    for(int i = 1; i <= sushi_category_cnt; ++i)
        if(sushi_cnt[i])
            ++now_category_cnt;

    int max_category_cnt = now_category_cnt + static_cast<int>(sushi_cnt[given_sushi] == 0);

    for(int i = consecutive_dish_cnt; i <= dish_cnt + consecutive_dish_cnt; ++i) {
        if(sushi_cnt[dishes[i]]++ == 0)
            ++now_category_cnt;

        if(--sushi_cnt[dishes[i - consecutive_dish_cnt]] == 0)
            --now_category_cnt;

        max_category_cnt = std::max(max_category_cnt, now_category_cnt + static_cast<int>(sushi_cnt[given_sushi] == 0));
    }

    std::cout << max_category_cnt;
    return 0;
}