#include <cstdio>

unsigned long long T, p, a, b, c, aV, bV, cV;

unsigned long long min(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long tmp;
    if(a > b) tmp = b;
    else tmp = a;
    if(tmp > c) return c;
    return tmp;
}

int main() {
    scanf("%lld", &T);
    while(T--) {
        aV = 0, bV = 0, cV = 0;
        scanf("%lld %lld %lld %lld", &p, &a, &b, &c);
        aV = p%a, bV = p%b, cV = p%c;
        if(aV != 0 && bV != 0 && cV != 0) printf("%lld\n", min(a-aV, b-bV, c-cV));
        else printf("0\n");
    }
    return 0;
}
