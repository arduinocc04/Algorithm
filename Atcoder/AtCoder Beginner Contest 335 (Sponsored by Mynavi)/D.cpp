#include <cstdio>

int n, a[50][50];

void fill(int i, int j, int d, int k) {
    a[i][j] = k;
    if(d == 3) {
        if(j < n -1 && a[i][j + 1] == 0)
            fill(i, j + 1, 3, k+1);
        else if(i < n -1 && a[i+1][j] == 0)
            fill(i + 1, j, 1, k+1);
    }
    else if(d == 2) {
        if(i > 0 && a[i-1][j] == 0)
            fill(i - 1, j, 2, k+1);
        else if(j < n -1 && a[i][j + 1] == 0)
            fill(i, j + 1, 3, k+1);
    }
    else if(d == 1) {
        if(i < n - 1 && a[i + 1][j] == 0)
            fill(i + 1, j, 1, k+1);
        else if(j > 0 && a[i][j-1] == 0)
            fill(i, j-1, 0, k+1);
    }
    else {
        if(j > 0 && a[i][j-1] == 0)
            fill(i, j -1, 0, k+1);
        else if(i > 0 && a[i-1][j] == 0)
            fill(i - 1, j, 2, k+1);
    }
}

int main() {
    scanf("%d", &n);
    a[(n - 1)/2][(n - 1)/2] = -1;
    fill(0, 0, 3, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != -1)
                printf("%d ", a[i][j]);
            else
                printf("T ");
        }
        printf("\n");
    }
    return 0;
}
