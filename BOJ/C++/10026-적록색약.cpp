#include <cstdio>

int n, map[110][110], visited[110][110], groups1, groups2, d[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void calc1(int x, int y, int target, int depth=0) {
    if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || map[x][y] != target) return;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        calc1(x + d[i][0], y + d[i][1], target, depth+1);
    }
    if(depth == 0) groups1++;
    return;
}
void calc2(int x, int y, int target, int depth=0) {
    if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || map[x][y] != target) return;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        calc2(x + d[i][0], y + d[i][1], target, depth+1);
    }
    if(depth == 0) groups2++;
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) calc1(i, j, map[i][j]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 'R') map[i][j] = 'G';
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) calc2(i, j, map[i][j]);
    }
    printf("%d %d\n", groups1, groups2);
}