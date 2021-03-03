#include <cstdio>
#include <vector>

const int max = 1e7;
const int m = 1e7 + 10;
std::vector <int> primes;
bool isPrime[m];
int T, m, n[15];

int main() {
    for(int i = 2; i < max; i++) {
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j = i*i; j < max; j += i) {
            isPrime[j] = false;
        }
    }
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d", &n[i]);

    }
}