#include <cstdio>
#include <algorithm>

int n, p[10], ans;
std::pair<int, int> info[1'010];


int main() {
    scanf("%d", &n);
    for(int i = 0; i < 5; i++) scanf("%d", &p[i + 1]);
    for(int i = 0; i < n; i++) scanf("%d %d", &info[i].first, &info[i].second);
    ans = 240; // Sinchon
    std::sort(info, info + n);
    for(int i = 0; i < n; i++) {
        if(p[info[i].first] > 1) {
            p[info[i].first]--;
            ans += info[i].second;
            ans += info[i + 1].second - info[i].second;
        }
        else if(p[info[i].first] == 1) {
            p[info[i].first]--;
            ans += info[i].second;
        }
        // printf("ANS: %d\n", ans);
    }
    printf("%d\n", ans);
}