#include <cstdio>
#include <string.h>
int t, cnt;
char s[100010];
bool isUsed[100010];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s+1);
        cnt = 0;
        for(int i = 0; i < 100010; i++) isUsed[i] = false;
        int lenS = strlen(s+1);
        for(int i = 2; i <= lenS; i++) {
            if (s[i] == s[i-1] && !isUsed[i-1]) {
                cnt++;
                isUsed[i] = true;
                continue;
            }
            if(s[i] == s[i-2] && !isUsed[i-2]){
                cnt++;
                isUsed[i] = true;
                continue;
            }
        }
        printf("%d\n", cnt);
    }
}