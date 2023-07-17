#include <cstdio>

int a, b;
int main() {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    printf((a/3 == b/3)?"Yes":"No");
    return 0;
}
