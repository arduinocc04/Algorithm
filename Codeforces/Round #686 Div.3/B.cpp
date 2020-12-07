#include <cstdio>
#include <algorithm>
int T, n, flag, tmp, results[200010], p[200010];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) results[i] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            p[tmp-1] = i+1;
            results[tmp-1]++;
        }
        flag = -1;
        for(int i = 0; i < n; i++) {
            if(results[i] == 1) {
                flag = p[i];
                break;
            }
        }
        printf("%d\n", flag);
    }
}