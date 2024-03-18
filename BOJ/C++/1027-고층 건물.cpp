#include <cstdio>
#include <algorithm>

bool can_see_each_other(const int * const buildings, int i, int j) {
    const long long y2_minus_y1 = buildings[j] - buildings[i];
    const long long x2_minus_x1 = j - i;
    for(int k = i + 1; k < j; ++k) {
        const long long x3_minus_x1 = k - i;
        const long long y3_minus_y1 = buildings[k] - buildings[i];
        if(y2_minus_y1*x3_minus_x1 <= y3_minus_y1*x2_minus_x1) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int buildings[60];
    {
    int height;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &height);
        buildings[i] = height;
    }
    }

    int max_cnt = -1;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            const int r = std::max(i, j);
            const int l = std::min(i, j);
            if(can_see_each_other(buildings, l, r)) ++cnt;
        }

        if(max_cnt < cnt)
            max_cnt = cnt;
    }

    printf("%d\n", max_cnt);
}