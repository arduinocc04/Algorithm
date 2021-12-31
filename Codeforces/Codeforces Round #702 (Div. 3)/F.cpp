#include <cstdio>

int T, n, a[200010], p, q, l, r, minVal, c[200010];

long long calc(int x) {
    long long ans = 0;
    for(int i = 0; i < n; i++) ans += (c[i] > x)?(c[i])-x:c[i];
    return ans;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
    }
    return 0;
}
