#include <cstdio>
#include <algorithm>
int T, n, x, y;
std::pair<int, int> houses[1010];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            houses[i] = std::make_pair(x, y);
            
        }
    }
    return 0;
}
