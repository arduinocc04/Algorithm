#include <cstdio>
#include <utility>
#include <vector>
int T, n, k, p[110];
bool flag;
std::pair<int, int> dots[110];

int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int getDist(std::pair<int, int> a, std::pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < n; i++) scanf("%d %d", &dots[i].first, &dots[i].second);
        for(int i = 0; i < n; i++) {
            flag = true;
            for(int j = 0; j < n; j++) {
                if(getDist(dots[i], dots[j]) > k) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("1\n");
        else printf("-1\n");
    }
    return 0;
}
