#include <cstdio>

int T, n, x, a[510], tmp;
int main() {
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d %d", &n, &x);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n-1; i++) {
            if(a[i] > x) {
                tmp = x;
                x = a[i];
                a[i] = tmp;
                cnt++;
            }
        }
        bool flag = true;
        for(int i = 0; i < n-1; i++) if(a[i] > a[i+1]) flag = false;
        if(flag) printf("%d\n", cnt);
        else printf("-1\n");
    }
}