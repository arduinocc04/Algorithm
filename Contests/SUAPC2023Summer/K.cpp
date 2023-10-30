#include <cstdio>
#include <utility>

std::pair<int, int> rect1[8], rect2[8], cent1_x4, cent2_x4;

int main() {
    for(int i = 0; i < 4; i++) {
        scanf("%d %d", &rect1[i].first, &rect1[i].second);
    }
    for(int i = 0; i < 4; i++) {
        scanf("%d %d", &rect2[i].first, &rect2[i].second);
    }

    for(int i = 0; i < 4; i++) {
        cent1_x4.first += rect1[i].first;
        cent1_x4.second += rect1[i].second;

        cent2_x4.first += rect2[i].first;
        cent2_x4.second += rect2[i].second;
    }

    slopeUp = cent1_x4.second - cent2_x4.second;
    slopeDn = cent1_x4.first - cent2_x4.first;

    
}