#include <cstdio>

int T, n, trees[60],cnt;
bool isUsed[60];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &trees[i]);
        for(int i = 0; i < 60; i++) isUsed[i] = false;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                isUsed[trees[j]-trees[i]] = true;
            }
        }
        cnt = 0;
        for(int i = 0; i < 60; i++) cnt += isUsed[i];
        printf("%d\n", cnt);
    }
    return 0;
}
