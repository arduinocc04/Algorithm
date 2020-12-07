#include <cstdio>

int T, n, q, l, r, tmp, pre[110][2], prev1, prev0;
char s[110];
bool flag;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%c", &s[i]);
        prev1 = 0;
        prev0 = 0;
        pre[0][0] = 0;
        pre[0][1] = 0;
        for(int i = 1; i < n; i++) {
            if(s[i-1] == '1') prev1++;
            else prev0++;
            pre[i][0] = prev0;
            pre[i][1] = prev1;
        }
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &l, &r);
            flag = false;
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
}