#include <cstdio>
#include <string.h>
#define MAX 110

char a[MAX], b[MAX];
int c,n, cntA[3], cntB[3];
int main() {
    scanf("%d", &c);
    for(int q = 1; q <= c; q++) {
        scanf("%s", a);
        scanf("%s", b);
        n = strlen(a);
        cntA = {0, 0, 0}, cntB = {0, 0, 0};
        for(int i = 0; i < n; i++) {
            if(a[i] == '0' || a[i] == '1') cnt[a[i]-'0']++;
            else cnt[2]++;
            if(b[i] == '0' || b[i] == '1') cnt[b[i]-'0']++;
            else cnt[2]++;
        }
        if(cntA[0] + cntA[2] < cntB[0]) {
            printf("Case %d: -1\n", q);
            continue;
        }
        
    }
}