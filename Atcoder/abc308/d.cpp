#include <iostream>
#include <string>

int h, w;
std::string map[510];
bool visited[510][510];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char l[] = {'s', 'n', 'u', 'k', 'e'};
void dfs(int r, int c, int m) {
    if(map[r][c] != l[m]) {
        return;
    }
    visited[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int tmpR = r + dx[i];
        int tmpC = c + dy[i];
        if(tmpR < 0 || tmpR >= h || tmpC < 0 || tmpC >= w) continue;
        if(visited[tmpR][tmpC]) continue;
        dfs(tmpR, tmpC, (m + 1)%5);
    }

}

int main() {
    std::cin >> h >> w;
    for(int i = 0; i < h; i++) {
        std::cin >> map[i];
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            visited[i][j] = false;
        }
    }
    dfs(0, 0, 0);
    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) printf("%d", visited[i][j]);
    //     printf("\n");
    // }
    printf(visited[h-1][w-1]?"Yes":"No");
}