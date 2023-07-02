#include <cstdio>
#include <vector>

long long n, primes[15];
long long m, res;

long long calc(long long n, long long m) {
    return m/n;
}

void c(long long last, long long target, std::vector<long long> st) {
    if(st.size() == target) {
        long long p = 1;
        for(long long i = 0; i < st.size(); i++) p *= st[i];
        if(target%2) res += calc(p, m);
        else res -= calc(p, m);
        return;
    }
    for(long long i = last; i < n; i++) {
        st.push_back(primes[i]);
        c(i+1, target, st);
        st.pop_back();
    }
}

int main() {
    scanf("%d %lld", &n, &m);
    for(long long i = 0; i < n; i++) scanf("%d", &primes[i]);
    for(long long i = 1; i <= n; i++) c(0, i, std::vector<long long> ());
    printf("%lld", res);
}
