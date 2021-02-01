#include <cstdio>
#define MAX 1010
const int mod = 1e9 + 7;
int com[MAX][MAX];

int main() {
    for(int i = 0; i < MAX; i++) {
        com[i][0] = 1;
        for(int j = 1; j < MAX; j++) {
            com[i][j] = (com[i-1][j-1] + com[i-1][j])%mod;
        }
    }
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", com[n][r]);
}