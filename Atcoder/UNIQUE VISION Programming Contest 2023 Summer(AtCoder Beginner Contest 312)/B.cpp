#include <iostream>
#include <string>

int n, m;
std::string ss[110];

bool calc(int r, int c) {
    // if(r == 9 && c == 1) printf("Hi");
    if(r + 8 >= n) return false;
    // if(r == 9 && c == 1) printf("Hi %d %d\n", c, m);
    if(c + 8 >= m) return false;
    // if(r == 9 && c == 1) printf("Hi %d %d\n", c, m);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(ss[r + i][c + j] == '.') return false;
        }
    }
    // if(r == 9 && c == 1) printf("Hi");
    for(int i = 6; i < 9; i++) {
        for(int j = 6; j < 9; j++) {
            if(r + i >= n) return false;
            if(c + j >= m) return false;
            if(ss[r + i][c + j] == '.') return false;
        }
    }
    // if(r == 9 && c == 1) printf("Hi");
    for(int i = 0; i < 3; i++) {
        if(ss[r + i][c + 3] == '#') return false;
    }
    // if(r == 9 && c == 1) printf("Hi");
    for(int i = 0; i < 3; i++) {
        if(ss[r + 3][c + i] == '#') return false;
    }
    // if(r == 9 && c == 1) printf("Hi");
    if(ss[r + 3][c + 3] == '#') return false;
    // if(r == 9 && c == 1) printf("Hi");
    for(int i = 6; i < 9; i++) {
        if(ss[r + i][c + 5] == '#') return false;
    }
    // if(r == 9 && c == 1) printf("Hi");
    for(int i = 6; i < 9; i++) {
        if(ss[r + 5][c + i] == '#') return false;
    }
    // if(r == 9 && c == 1) printf("Hi");
    if(ss[r + 5][c + 5] == '#') return false;
    // if(r == 9 && c == 1) printf("Hi");
    return true;
}

int main() {
    std::cin >> n >> m;
    for(int i = 0; i < n ;i++) {
        std::cin >> ss[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(calc(i, j)) {
                std::cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
}
