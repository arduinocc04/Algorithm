#include <cstdio>

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(n%2) {
            for(int i = n; i> 0; i--) {
                if(i != n/2 + 1 && i != 1) printf("%d ", i);
                else if(i == n/2 +1 ) printf("1 ");
                else printf("%d", n/2+1);
            }
        }
        else {
            for(int i = n; i > 0; i--) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}