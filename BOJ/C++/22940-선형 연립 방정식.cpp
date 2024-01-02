#include <cstdio>

int n, A[10][10], B[10];

int det(int mat[][10], int n) {
    if(n == 1) return mat[0][0];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int minor[10][10];
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            for(int k = 1; k < n; k++) {
                minor[c][k - 1] = mat[j][k];
            }
            ++c;
        }
        if(i % 2)
            ans -= mat[i][0]*det(minor, n - 1);
        else
            ans += mat[i][0]*det(minor, n - 1);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
        scanf("%d", &B[i]);
    }
    int detA = det(A, n);
    for(int i = 0; i < n; i++) {
        int tmpMatrix[10][10];
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                tmpMatrix[j][k] = A[j][k];
        for(int j = 0; j < n; j++)
            tmpMatrix[j][i] = B[j];
        printf("%d ", det(tmpMatrix, n)/detA);
    }
}
