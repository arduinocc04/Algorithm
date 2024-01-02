#include <cstdio>

int n, m, a[1'000'010], s[1'000'010], cnt[1'010];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    s[0] = a[0] % m;
    for(int i = 1; i < n; i++) {
        s[i] = (a[i]%m + s[i - 1]) % m;
    }
    for(int i = 0; i < n; i++) ++cnt[s[i]];
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        if(cnt[i] > 1) {
            if(cnt[i] % 2)
                ans += (long long)cnt[i]*((cnt[i] - 1)/2);
            else
                ans += ((long long)cnt[i]/2)*(cnt[i] - 1);
        }
    }
    for(int i = 0; i < n; i++) if(!s[i]) ++ans;
    printf("%lld", ans);
}
