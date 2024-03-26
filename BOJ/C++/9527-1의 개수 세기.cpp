#include <iostream>

unsigned long long dp[100];
unsigned long long twos[100];

unsigned long long get_sum(int width) {
    if(width == 0) return 0;
    if(dp[width] != 0)
        return dp[width];

    for(int i = width - 1; i >= 0; --i)
        dp[width] += twos[i] + get_sum(i);
    return dp[width];
}

unsigned long long calc(unsigned long long x) {
    if(x <= 1)
        return x;

    int i;
    for(i = 63; i >= 0; --i) {
        if(x & (1ull << i)) {
            break;
        }
    }

    return (x^(1ull << i)) + 1 + calc(x^(1ull << i)) + get_sum(i); // + calc((1ull << i) - 1);
}

unsigned long long a, b;

int main() {
    std::cin >> a >> b;
    dp[1] = 1;
    twos[0] = 1;
    for(int i = 1; i < 63; ++i)
        twos[i] = 2*twos[i - 1];

    if(a == 0) {
        std::cout << calc(b);
    }
    else {
        std::cout << calc(b) - calc(a - 1);
    }
}