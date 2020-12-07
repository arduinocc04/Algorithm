#include <cstdio>

int T, n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int i = 0;
        int j = 0;
        while(j < n) {
            j += i+1;
            i++;
            //printf("j: %d", j);
            //printf(" i: %d\n", i);
        }
        if(n == j-1) {
            printf("%d\n", i+1);
        }
        else{
            printf("%d\n", i);
        }
    }
}