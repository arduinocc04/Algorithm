#include <cstdio>

int T, n, h[110];
long long sums[110];
bool flag;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &h[i]);
        sums[0] = h[0];
        for(int i = 1; i < n; i++) sums[i] = sums[i-1] + h[i];
        flag = true;
        for(int i = 0; i < n; i++) if(sums[i] < i*(i+1)/2) flag = false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
