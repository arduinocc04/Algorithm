#include <iostream>
int n, cnt;
void calc(int &stack, int qC) {
    if(qC == n) {
        cnt += 1;
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < qC; j++) {
            if(stack[j] == i) {
                continue;
            }
        }

    }
}

int main() {
    std::cin >> n;
    cnt = 0
}