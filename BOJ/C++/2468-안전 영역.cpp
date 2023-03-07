#include <cstdio>

int n, map[110][110], visited[110][110], dx[] = {0, 0, 1, -1}, dy[] {-1, 1, 0, 0};

void dfs(int x, int y, int h, int group) {
    visited[x][y] = group;
    for(int k = 0; k < 4; k++) {
        int tmpX = x + dx[k];
        int tmpY = y + dy[k];
        if(0 <= tmpX && tmpX < n && 0 <= tmpY && tmpY < n && !visited[tmpX][tmpY] && map[tmpX][tmpY] > h) {
            dfs(tmpX, tmpY, h, group);
        }
    }
}

int main() {
    scanf("%d", &n);
    int maxH = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] > maxH) maxH = map[i][j];
        }
    }
    int MAX = 0;
    for(int h = 0; h < maxH; h++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        int group = 1;
        while(true) {
            bool flag = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (!visited[i][j] && map[i][j] > h) {
                        flag = false;
                        dfs(i, j, h, group);
                        break;
                    }
                }
                if(!flag) break;
            }
            group++;
            if(flag) break;
        }
        int max = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] > max) max = visited[i][j];
            }
        }
        if(max > MAX) MAX = max;
    }
    printf("%d", MAX);
    return 0;
}