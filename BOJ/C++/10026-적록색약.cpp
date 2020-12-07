#include <cstdio>

int n;
char picture[110][110];
bool visited[110][110];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y) {
    visited[x][y] = true;
    int tmpX, tmpY;
    for(int i = 0; i < 4; i++) {
        tmpX = x + d[i][0];
        tmpY = y + d[i][1];
        if(0 <= tmpX && tmpX < n && 0 <= tmpY && tmpY < n && !visited[tmpX][tmpY] && picture[tmpX][tmpY] == picture[x][y]) {
            dfs(tmpX, tmpY);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%c", &picture[i][j]); 
            visited[i][j] = false;
        }
    }
    int cnt = 0;
    bool flag;
    while(true) {
        flag = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    flag = false;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if(flag) break;
    }
    printf("%d", cnt);
    cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] == 'R') picture[i][j] = 'G';
            visited[i][j] = false;
        }
    }
    while(true) {
        flag = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    flag = false;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if(flag) break;
    }
    printf(" %d", cnt);

}