#include <utility>
#include <cstdio>
std::pair<int, int> a[1'000'010];

int T, m, n;

int main() {
    for(int i = 0; i < 1'000'010; i++) a[i].first = a[i].second = 0;
    for(int i = 2; 2*i < 1'000'010; i++) {
        for(int j = 2*i; j < 1'000'010; j += i) {
            if(!a[j].second) {
                a[j].second = i;
            }
            a[j].first++;
        }
    }
    scanf("%d", &T);
    for(int asdf = 1; asdf <= T; asdf++) {
        scanf("%d %d", &n, &m);
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(a[i].first == a[n].first && a[i].second >= m) cnt++;
        }
        printf("Case #%d: %d\n", asdf, cnt);
    }
}
