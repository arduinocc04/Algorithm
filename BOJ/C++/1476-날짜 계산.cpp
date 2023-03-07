#include <cstdio>

int e, s, m;

int main() {
    scanf("%d %d %d", &e, &s, &m);
    for(int n = 1; n < 1e9; n++) {
        if(n % 15 == e && n % 28 == s && n % 19 == m) {
            printf("%d", n);
        }
    }
}