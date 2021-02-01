#include <cstdio>

long long pow(long long x, long long a) {
    if(a == 0) return 1;
    long long tmp = pow(x, a/2);
    tmp = tmp*tmp;
    if(a % 2) tmp *= x;
    return tmp;
}

int main() {
    for(int i = 1; i < 10; i++) {
        printf("%d: %lld\n", i, pow(i, 10));
    }
}