#include <cstdio>

int n, a, b, x[60];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);

    if(n == 1) {
        printf("A");
        return 0;
    }

    if(n == 2) {
        if(x[0] == x[1]) {
            printf("%d", x[0]);
            return 0;
        }
        printf("A");
        return 0;
    }

    if(x[1] != x[0]) {
        a = (x[2] - x[1])/(x[1] - x[0]);
        if((x[2] - x[1]) % (x[1] - x[0]) != 0) {
            printf("B");
            return 0;
        }
        b = x[1] - a*x[0];
        for(int i = 1; i < n; i++) {
            if(x[i] != a*x[i - 1] + b) {
                printf("B");
                return 0;
            }
        }
        printf("%d", a*x[n - 1] + b);
    }
    else {
        for(int i = 0; i < n; i++) {
            if(x[i] != x[0]) {
                printf("B");
                return 0;
            }
        }
        printf("%d", x[0]);
    }
}

