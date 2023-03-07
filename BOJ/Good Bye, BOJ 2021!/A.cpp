#include <cstdio>
#include <vector>
#define MAX 1000000
int prime[MAX], n;
std::vector<int> primes;

int main() {
    scanf("%d", &n);
    for(int i = 2; i < MAX; i++) prime[i] = true;
    for(int i = 2; i*i< MAX; i++) {
        if(!prime[i]) continue;
        primes.push_back(i);
        for(int j = i*i; j < MAX; j += i) {
            prime[j] = false;
        }
    }
    //for(auto i:primes) printf("%d ", i);
    for(int i = 0; i < primes.size() -1; i++) {
        if(primes[i]*primes[i+1] > n) {
            printf("%d\n", primes[i]*primes[i+1]);
            break;
        }
    }
    return 0;
}