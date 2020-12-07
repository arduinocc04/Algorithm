#include <cstdio>
int T, n, m, bottom[110], left[110], cnt;
int main() {
    scanf("%d", &T);
    while(T--)  {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &bottom[i]);
        for(int i = 0; i < m; i++) scanf("%d", &left[i]);
        cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(bottom[i] == left[j]) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}