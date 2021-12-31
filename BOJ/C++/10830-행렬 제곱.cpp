#include <cstdio>
#include <vector>
int n;
unsigned long long b;
const int mod = 1e3;

typedef std::vector<std::vector<int>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
    matrix res(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) res[i][j] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

matrix pow(matrix a, unsigned long long b) {
    matrix tmp(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) tmp[i][j] = 0;
    for(int i = 0; i < n; i++) tmp[i][i] = 1;
    while(b > 0) {
        if(b % 2) tmp = tmp*a;
        a = a*a;
        b/= 2;
    }
    return tmp;
}
int main() {
    scanf("%d %lld", &n, &b);
    matrix mat(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    matrix ans(n, std::vector<int>(n));
    ans = pow(mat, b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

}
