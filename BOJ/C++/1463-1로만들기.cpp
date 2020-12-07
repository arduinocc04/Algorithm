#include <iostream>

int calc(int num, int depth, int *minResult) {
    if (depth >= *minResult) {
        return 0;
    }
    if(num == 1) {
        *minResult = depth;
    }
    if(num%3 == 0) {
        calc(num/3, depth+1, minResult);
    }
    if(num%2 == 0) {
        calc(num/2, depth+1, minResult);
    }
    return calc(num-1, depth + 1, minResult);
}

int main() {
    int x, minResult = 100000000;
    std::cin >> x;
    calc(x, 0, &minResult);
    std::cout << minResult;
    return 0;
}