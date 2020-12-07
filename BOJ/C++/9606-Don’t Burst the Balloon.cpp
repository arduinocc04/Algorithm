#include <cstdio>
#include <tuple>
int n, w, x, y, h;
std::tuple<int, int, int> needles[15];

int main() {
    while(true) {
        scanf("%d %d", &n, &w);
        if(n == 0 && w == 0) break;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &h);
            needles[i] = std::make_tuple(x, y, h);
        }
    }
    return 0;
}