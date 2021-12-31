#include <cstdio>
#include <algorithm>
#include <queue>

int T, n, a[200010], target, k, ans, tmp;
std::priority_queue<int> pq;
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    if(k == n) {
        std::sort(a, a+n);
        printf("%d\n", a[(int)((n+1)/2)]);
        return 0;
    }
    ans = 0;
    for(int i = 0; i + k <= n; i++) {
        for(int j = 0; j < pq.size(); j++) pq.pop();
        for(int j = 0; j < k; j++) {
            pq.push(-a[i+j]);
        }
        for(int j = 0; j < (int)(k+1)/2 - 1; j++) pq.pop();
        tmp = -pq.top();
        if(tmp > ans) ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
