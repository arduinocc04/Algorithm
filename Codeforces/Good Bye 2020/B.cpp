#include <cstdio>
#define MAX 200010
int T, n, tmp, cnt, prev;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        prev= -1;
        cnt = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if(prev < tmp) {
                cnt++;
                prev = tmp;
            }
            else if(prev == tmp) {
                cnt++;
                prev = tmp+1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
