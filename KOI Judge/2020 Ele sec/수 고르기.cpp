#include <cstdio>
#include <algorithm>

int n, k, a[5010];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::sort(a, a+n);
    long long res = 0;
    int tmp = -1;
    int cnt = 0;
    for(int i = 1; i < k+1; i++) {
        res += a[n-i];
        tmp++;
        cnt += tmp;
    }
    res -= cnt;
    printf("%lld", res);
}