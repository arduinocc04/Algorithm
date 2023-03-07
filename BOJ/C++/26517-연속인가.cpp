#include <cstdio>

long long k, a, b, c, d;

int main() {
    scanf("%d %d %d %d %d", &k, &a, &b, &c, &d);
    if(a*k + b == c*k + d) {
        printf("Yes %d", a*k + b);
        return 0;
    }
    printf("No");
    return 0;
}