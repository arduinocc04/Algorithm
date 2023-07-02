#include <string>
#include <iostream>

int n;
std::string str;

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    std::cin >> n;
    std::cin >> str;
    int firstL = -1;
    int lastR = -1;
    int lcnt = 0;
    int rcnt = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '(') {
            lcnt++;
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == ')') {
            rcnt++;
        }
    }
    if(firstL > lastR || (firstL == -1 || lastR == -1)) {
        std::cout << str;
    }
    else {
        int cnt = min(lcnt, rcnt);
        int tmp = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(str[i] == '(') {
                tmp++;
                if(tmp == cnt) {
                    firstL = i;
                    break;
                }
            }
        }
        tmp = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == ')') {
                tmp++;
                if(tmp == cnt) {
                    lastR = i;
                    break;
                }
            }
        }
        for(int i = 0; i < firstL; i++) {
            std::cout << str[i];
        }
        for(int i = lastR + 1; i < n; i++) {
            std::cout << str[i];
        }
    }
}