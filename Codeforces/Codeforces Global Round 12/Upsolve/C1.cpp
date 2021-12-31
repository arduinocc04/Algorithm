#include <cstdio>

int T, n;
char grid[310][310];
int cnt[3];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        for(int i = 0; i < 3; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(grid[i][j] == 'X') cnt[(i + j) %3]++;
        int min = 0;
        for(int i = 0; i < 3; i++) if(cnt[min] > cnt[i]) min = i;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if((i + j)%3 == min && grid[i][j] == 'X') grid[i][j] = 'O';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
}