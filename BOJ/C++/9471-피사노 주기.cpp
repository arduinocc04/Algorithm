#include <cstdio>

int T, n, m, fibs[500'010];
bool flag;

int main() {
    scanf("%d", &T);
    for(int C = 1; C <= T; C++) {
        scanf("%d %d", &n, &m);
        fibs[1] = 1;
        fibs[2] = 1;
        for(int i = 3; i < 500'010; i++) {
            fibs[i] = (fibs[i - 1] + fibs[i - 2]) % m;
            if(fibs[i] == 0) {
                flag = true;
                continue;
            }
            if(flag) {
                if(fibs[i] == 1) {
                    printf("%d %d\n", C, i - 1);
                    break;
                }
                else {
                    flag = false;
                }
            }
        }
    }
}