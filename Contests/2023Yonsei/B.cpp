#include <cstdio>
#include <algorithm>

int n;
std::pair<int, int> xh[300'010];

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int calcRight(int i, int t) {
    if(xh[i].second - 2*t > 1)
        return xh[i].first + t;
    return xh[i].first + xh[i].second/2;
}

int calcLeft(int i, int t) {
    if(xh[i].second - 2*t > 1)
        return xh[i].first - t;
    return xh[i].first - xh[i].second/2;
}

bool calc(int t) {
    for(int i = 1; i < n; i++) {
        if(calcRight(i - 1, t) >= calcLeft(i, t))
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &xh[i].first, &xh[i].second);
    }

    std::sort(xh, xh + n);
    int l = 0;
    int h = 1'000'000'000;
    while(l < h) {
        int m = (l + h)/2;
        if(calc(m)) l = m + 1;
        else h = m;
    }
    if(l == 1'000'000'000) {
        printf("forever");
        return 0;
    }
    printf("%d", l-1);
}
