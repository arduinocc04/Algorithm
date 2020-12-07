#include <cstdio>

int T, x, y;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &x, &y);
        if(x == 1) {
            printf("%d %d\n", 0, y);
        }
        if(x == y) {
            printf("%d %d\n", x, x);
        }
        else {
            if(x > y) {
                
            }
        }
    }
}