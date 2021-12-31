#include <cstdio>

int T, n;
char grid[310][310];
int cnt[3][2];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        for(int i = 0; i < 3; i++) cnt[i][0] = 0, cnt[i][1] = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'X') cnt[(i + j) %3][0]++;
            else if(grid[i][j] == 'O') cnt[(i + j) %3][1]++;
        }
        int minI, minJ, min = 1e9;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j) continue;
                if(min > cnt[i][0] + cnt[j][1]) {
                    min = cnt[i][0] + cnt[j][1];
                    minI = i;
                    minJ = j;
                }
            }
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            if((i + j)%3 == minI && grid[i][j] == 'X') {
                grid[i][j] = 'O';
            }
            else if((i + j)%3 == minJ && grid[i][j] == 'O') {
                grid[i][j] = 'X';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
}