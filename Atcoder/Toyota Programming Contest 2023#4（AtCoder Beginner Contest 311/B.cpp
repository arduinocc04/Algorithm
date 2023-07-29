#include <iostream>
#include <string>

bool allPeopleFree;
int n, d, m;
std::string s[110];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    std::cin >> n >> d;
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    m = 0;
    for(int i = 0; i < d; i++) {
        for(int j = i; j < d; j++) {
            allPeopleFree = true;
            for(int k = 0; k < n; k++) {
                if(s[k][j] == 'x') {
                    allPeopleFree = false;
                    break;
                } 
            }
            if(!allPeopleFree) break;
            m = max(m, j - i + 1);
        }
    }
    std::cout << m;
}