#include <cstdio>

int T, n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; i + j <= n; j++) {
            for(int k = 0; i + j + k <= n; k++) {
                printf("%d %d %d\n", i, j, k);
            }
        }
    }
    return 0;
}
