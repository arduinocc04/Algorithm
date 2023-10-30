#include <cstdio>

int a, b, x, y, f[50];

int find(int s) {
    for(int i = 1; i < 50; i++) {
        if(f[i] == s) return i;
    }
}

void calc(int a, int b, int x, int y) { // a: width, b: height
    if(a > b) {
        int prev = f[find(b) - 1];
        if(y <= prev) {
            calc(a, prev, )
        }
    }
}

int main() {
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i < 50; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

}