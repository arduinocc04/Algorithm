#include <cstdio>

int n;
char a[110][110];
char res[110][110];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &a[i][j]);
            res[i][j] = a[i][j];
        }
    }
    int ru = a[0][n - 1];
    int lu = a[0][0];
    int rd = a[n - 1][n - 1];
    int ld = a[n - 1][0];
    for(int i = 1; i < n; i++) {
        res[0][i] = a[0][i-1];
    }
    for(int i = 1; i < n; i++) {
        res[i][n - 1] = a[i - 1][n - 1];
    }
    for(int i = n -2; i >= 0; i--) {
        res[n - 1][i] = a[n - 1][i + 1];
    }
    for(int i = n - 2; i >= 0; i--) {
        res[i][0] = a[i + 1][0];
    }
    res[0][1] = lu;
    res[1][n - 1] = ru;
    res[n - 1][n - 2] = rd;
    res[n - 2][0] = ld;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
