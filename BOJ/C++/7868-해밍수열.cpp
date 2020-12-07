#include <algorithm>
#include <iostream>
#include <vector>

unsigned long long pow(unsigned long long a, int b) {
    unsigned long long res = 1;
    for(int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    unsigned long long p1, p2, p3, a, b, c;
    int i;
    std::cin >> p1 >> p2 >> p3 >> i;
    std::vector<unsigned long long> result;
    result.clear();
    for(int j = 0; j < 60; j++) {
        b = pow(p1, j);
        for(int k = 0; k < 60; k++) {
            c = pow(p2, k);
            a = b*c;
            result.push_back(a);
            for(int l = 0; l < 60; l++) {
                if(j+k+l >= 59) {
                    break;
                }
                a *= p3;
                result.push_back(a);
            }
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << result[i];

    return 0;
}