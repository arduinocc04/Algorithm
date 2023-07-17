#include <cstdio>
#include <algorithm>

int n, h, w, d, ma, mi;

int max(int a, int b, int c) {
    if(a >= b && a >= c) return a;
    if(b >= c && b >= a) return b;
    return c;
}

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= c && b <= a) return b;
    return c;
}

std::pair<int, std::pair<int, int>> things[200'010];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &w, &d);
        ma = max(h, w, d);
        mi = min(h, w, d);
        if(h != ma && h != mi) {
            things[i] = std::make_pair(mi, std::make_pair(h, ma));
        }
        else if(w != ma && w != mi) {
            things[i] = std::make_pair(mi, std::make_pair(w, ma));
        }
        else {
            things[i] = std::make_pair(mi, std::make_pair(d, ma));
        }
    }
    std::sort(things, things + n);
    // for(int i = 0; i < n; i++) {
    //     printf("%d %d %d\n", things[i].first, things[i].second.first, things[i].second.second);
    // }

    for(int i = 0; i < n - 1; i++) {
        if(things[i].first < things[n - 1].first && things[i].second.first < things[n - 1].second.first && things[i].second.second < things[n - 1].second.second) {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
