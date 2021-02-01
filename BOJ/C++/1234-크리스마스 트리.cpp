#include <cstdio>

int n, r, g, b;

long long calc(int k) {
    if(k == 1) return (r > 0) + (g > 0) + (b>0);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < g; j++) {
            for(int k = 0; k < b; k++) {
                if(i + j + k > k)
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &r, &g, &b);
}