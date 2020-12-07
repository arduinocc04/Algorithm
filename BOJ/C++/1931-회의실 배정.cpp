#include <cstdio>
#include <algorithm>

int n;
std::pair<int, int> cons[100010];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &cons[i].second, &cons[i].first);
    std::sort(cons, cons+n);
    int cnt = 0;
    int hi = 0;
    for(int i = 0 ; i < n; i++) {
        if (cons[i].second >= hi) {
            cnt++;
            hi = cons[i].first;
        }
    }
    printf("%d", cnt);
}