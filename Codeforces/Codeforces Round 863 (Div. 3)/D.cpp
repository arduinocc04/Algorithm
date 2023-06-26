#include <cstdio>

int T, n, x, y, f[50];
int main() {
    scanf("%d", &T);
    f[0] = 1;
    f[1] = 1;
    for(int i =2; i < 50; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    while(T--) {
        scanf("%d %d %d", &n, &x, &y);
    }
    return 0;
}
