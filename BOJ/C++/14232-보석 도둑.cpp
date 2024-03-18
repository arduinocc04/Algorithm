#include <iostream>
#include <vector>

#define MAX_SIZE 100'000'010

// std::vector<int> primes;
// std::vector<bool> is_prime(MAX_SIZE);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    /*
    for(int i = 2; i < MAX_SIZE; ++i)
        is_prime[i] = true;

    for(int i = 2; i < MAX_SIZE; ++i) {
        if(!is_prime[i])
            continue;
        primes.push_back(i);
        for(long long j = static_cast<long long>(i)*i; j < MAX_SIZE; j += i) {
            is_prime[j] = false;
        }
    }
    */

    unsigned long long k;
    std::cin >> k;

    std::vector<unsigned long long> ans;
    for(int p = 2; p < 1'000'010; ++p) {
        if(k == 1) break;
        while(k % p == 0) {
            ans.push_back(p);
            k /= p;
        }
    }

    if(k != 1)
        ans.push_back(k);

    std::cout << ans.size() << "\n";
    for(const unsigned long long i: ans) {
        std::cout << i << " ";
    }

    return 0;
}
