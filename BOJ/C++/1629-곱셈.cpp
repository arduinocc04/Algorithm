#include <cstdio>
long long a, b, c;
long long pow(long long a, long long b) {
    if(b == 0) return 1;
    long long tmp = pow(a, b/2)%c;
    tmp = (tmp*tmp)%c;
    if(b%2) tmp = (tmp*a)%c;
    return tmp;
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", pow(a, b));
}