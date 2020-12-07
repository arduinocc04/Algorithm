#include <cstdio>

int n, m, partial[1040][1040], map[1040][1040],tmp, x1, y1, x2, y2;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    partial[0][0] = map[0][0];
    for(int i = 1; i < n; i++) {
        partial[0][i] = partial[0][i-1] + map[0][i];
    }
    partial[1][0] = partial[0][0] + map[1][0];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            partial[i][j] = partial[i][j-1] + map[i][j] + partial[i-1][j] - partial[i-1][j-1];
        }
        partial[i+1][0] = partial[i][0] + map[i+1][0];
    }
    /* debug
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", partial[i][j]);
        }
        printf("\n");
    }
    */
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        {
            x1--;
            x2--;
            y1--;
            y2--;
        }
        tmp = partial[x2][y2];
        if(x1 == 0 && y1 == 0) {
            printf("%d\n", tmp);
        }
        else if(x1 == 0) {
            tmp -= partial[x2][y1-1];
            printf("%d\n", tmp);
        }
        else if(y1 == 0) {
            tmp -= partial[x1-1][y2];
            printf("%d\n", tmp);
        }
        else {
            tmp -= partial[x2][y1-1];
            tmp -= partial[x1-1][y2];
            tmp += partial[x1-1][y1-1];
            printf("%d\n", tmp);
        }
    }
}