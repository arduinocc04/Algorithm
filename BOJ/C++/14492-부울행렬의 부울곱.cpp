#include <cstdio>

int n;
bool a[310][310], b[310][310];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[i][k] && b[k][j]) {
                    ++cnt;
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
}
