#include <cstdio>
#include <algorithm>

int n, k, t, a[100'010];
long long all, bCnt;

int main() {
    scanf("%d %d %d", &n, &k, &t);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) all += a[i];
    if(all % k != 0) {
        printf("NO");
        return 0;
    }
    bCnt = all/k;
    std::sort(a, a + n);
    for(int i = 0; i < bCnt; i++) {
        all -= a[n - i - 1];
    }
    if(all > t) {
        printf("NO");
    }
    else {
        printf("YES");
    }
}