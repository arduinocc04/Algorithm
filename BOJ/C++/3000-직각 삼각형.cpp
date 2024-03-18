#include <cstdio>
#include <utility> // for std::pair

std::pair<int, int> points[100'010];
int n, xs[100'010], ys[100'010];

int main() {
    scanf("%d", &n);
    int x, y;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        points[i] = std::make_pair(x, y);
        ++xs[x]; // global variables are initalized by 0.
        ++ys[y];
    }

    unsigned long long cnt = 0;

    for(int i = 0; i < n; ++i) {
        x = points[i].first;
        y = points[i].second;
        cnt += static_cast<unsigned long long>((xs[x] - 1))*(ys[y] - 1);
    }

    printf("%llu\n", cnt);
}

