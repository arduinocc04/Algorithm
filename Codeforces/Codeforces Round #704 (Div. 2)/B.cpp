#include <cstdio>
#include <vector>

int T, n, p[100010], max, nowLen;
bool possibleMax[100010];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &p[i]);
        max = n;
        nowLen = n;
        for(int i = 0; i < 100010; i++) possibleMax[i] = true;
        possibleMax[max] = false;
        for(int i = n-1; i >= 0; i--) {
            if(p[i] == max) {
                for(int j = i; j < nowLen; j++) {
                    printf("%d ", p[j]);
                }
                nowLen -= (nowLen - i);
                for(int j = max-1; j >= 0; j--) {
                    if(possibleMax[j]) {
                        max = j;
                        break;
                    }
                }
            }
            possibleMax[p[i]] = false;
        }
        printf("\n");
    }
    return 0;
}
