#include <cstdio>
#define MAX 300
const int mod = 1e9 + 7;
long long factorial[MAX], inverseFactorial[MAX];
long long pow(int x, int a) {
    if(a == 0) return 1;
    long long tmp = pow(x, a/2);
    tmp = tmp*tmp % mod;
    if(a % 2) return tmp*x %mod;
    return tmp;
}

long long combination(long long n, long long r) {
    return factorial[n] * inverseFactorial[r]%mod * inverseFactorial[n-r] % mod;
}

int main() {
    factorial[0] = 1, factorial[1] = 1;
    for(int i = 2; i < MAX; i++) factorial[i] = (factorial[i-1] * i) %mod;
    inverseFactorial[MAX-1] = pow(factorial[MAX-1], mod-2);
    printf("%lld\t%lld\n", factorial[MAX-1], inverseFactorial[MAX-1]);
    for(int i = MAX-2; i >= 0; i--) {
        inverseFactorial[i] = inverseFactorial[i+1] * (i+1) % mod;
    }
    long long n, r;
    while (true) {
        scanf("%lld %lld", &n, &r);
        if(n == r && n == 0) break;
        printf("%lld C %lld mod %d = %lld\n", n, r, mod, combination(n, r));
    }

}