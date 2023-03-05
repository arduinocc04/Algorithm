#include <cstdio>
#include <cmath>

int b, c, a1, a2;

int main() {
    scanf("%d, %d, %d, %d", &b, &c, &a1, &a2);
    printf("%.10f", (b + std::sqrt((double)(b^2 + 4*c)))/2);
    return 0;
}