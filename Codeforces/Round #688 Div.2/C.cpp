#include <cstdio>
#include <algorithm>
int T, n, a[2010][2010], isexistvertical[2010][10], isexisthoritzonal[2010][10], cnt[10], xStart, xFinish, yStart, yFinish;
int main() {
    scanf("%d", &T);
    while(T--)  {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            scanf("%01d", &a[i][j]);
            cnt[a[i][j]]++;
        }
        if(n == 1) printf("0 0 0 0 0 0 0 0 0 0\n");
        for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++) isexisthoritzonal[i][j] = false, isexistvertical[i][j] = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                isexistvertical[i][a[i][j]] = true;
                isexisthoritzonal[j][a[j][i]] = true;
            }
        }
        for(int d = 0; d < 10; d++) {
            if(cnt[d] < 2) printf("0 ");
            for(int i = 0; i < n; i++) if(isexisthoritzonal[i][d]) xStart = i;
            for(int i = xStart+1; i < n; i++) if(isexisthoritzonal[i][d]) xFinish = i;
            
            for(int i = 0; i < n; i++) if(isexistvertical[i][d]) yStart = i;
            for(int i = yStart+1; i < n; i++) if(isexistvertical[i][d]) yFinish = i;
            res = std::max((xFinish-xStart)*(n))
        }
        printf("\n");
    }
}