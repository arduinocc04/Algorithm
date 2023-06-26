#include <cstdio>

char a[1010], b[1010];
int dp[1010];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf(" %s ", a);
    scanf(" %s ", b);
    if(a[0] == b[0]) dp[0] = 1;
    for(int i = 0; i < min(sizeof(a)/sizeof(char), sizeof(b)/sizeof(char)); i++) {
        
    }
}