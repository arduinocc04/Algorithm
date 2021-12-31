#include <cstdio>
#include <vector>

std::vector<int> primes;
bool isprime[10010];
int T, n, t;

int main() {
    scanf("%d", &T);
    for(int i = 0; i < 10010; i++) isprime[i] = true;
    for(int i = 2; i < 10010; i++) {
        if(!isprime[i]) continue;
        primes.push_back(i);
        for(int j = i*i; j < 10010; j += i) {
            isprime[j] = false;
        }
    }
    while(T--) {
        scanf("%d", &n);
        t = 0;
        while(primes[t+1] <= n/2) t++;
        for(int i = t; i >= 0; i--) {
            if(isprime[n - primes[i]]) {
                printf("%d %d\n", primes[i], n-primes[i]);
                break;
            }
        }  
    }
}