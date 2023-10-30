#include <cstdio>

int l, a, b, c, d;

int max(int a, int b) {
    return (a>b)?a:b;
}

int main() {
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    printf("%d", l - max(a/c + (a%c > 0), b/d + (b%d > 0)));
}