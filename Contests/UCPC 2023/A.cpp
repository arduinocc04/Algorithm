#include <cstdio>

int n, tmp;

int main() {
    for(int i = 0; i < 10; i++) {
        scanf("%d", &tmp);
        if(tmp == 1) {
            n += 1;
        }
        else if(tmp == 2) {
            n += 2;
        }
        else if(tmp == 3) {
            n -= 1;
        }
    }
    printf("%d", n);
    n %= 4;
    if(n == 0) {
        printf("N");
    }
    else if(n == 1) {
        printf("E");
    }
    else if(n == 2) {
        printf("S");
    }
    else {
        printf("W");
    }
}