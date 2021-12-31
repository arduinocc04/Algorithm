#include <cstdio>
#define MAX 2010
int com[MAX][MAX];
int main() {
    long long n, r, m;
    scanf("%lld %lld %lld", &n, &r, &m);
    for(int i = 0; i < MAX; i++) {
        com[i][0] = 1;
        for(int j = 1; j < MAX; j++) {
            com[i][j] = (com[i-1][j-1] + com[i-1][j])%m;
        }
    }
    int ret = 1;
    while(n || r) {
        if(n%m < r %m) {
            ret = 0;
            break;
        }
        ret *= com[n%m][r%m];
        n /= m, r /= m;
        ret %= m;
    }
    printf("%d\n", ret);
}