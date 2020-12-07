#include <cstdio>
#include <algorithm>
int n, res[1000010], tmp;
std::pair<int, int> dots[1000010];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &dots[i].first);
        dots[i].second = i;
    }
    std::sort(dots, dots+n);
    for(int i = 0; i < n; i++) {
        tmp = i;
        while((tmp < n) && dots[tmp].first == dots[i].first) {
            tmp++;
        }
        res[dots[i].second] = tmp -1;
    }
    for(int i = 0; i < n; i++) printf("%d ", res[i]);
}