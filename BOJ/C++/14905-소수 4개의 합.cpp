#include <cstdio>
#include <vector>

std::vector<int> primes;
bool isPrime[100'000'010], a, b;
int x;

int canBeSum(int x) {
    for(auto i: primes) {
        if(isPrime[x - i]) return i;
    }
}

int main() {
    for(int i = 2; i < 100'000'010; i++) isPrime[i] = true;
    for(int i = 2; i < 100'000'005; i++) {
        if(!isPrime[i]) continue;
        //primes.push_back(i);
        for(long long j = i*i; j < 100'000'005; j+= i) {
            isPrime[j] = false;
        }
    }
    while(scanf("%d", &x) != EOF) {
        if(x < 8) printf("Impossible.\n");
        for(int i = 4; i < x; i++) {
            a = canBeSum(i), b = canBeSum(x-i);
            if(a && b) {
                printf("%d %d %d %d\n", a, i-a, b, x-i-b);
                goto cont;
            }
        }
        cont:
        continue;
    }
}