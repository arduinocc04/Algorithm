#include <cstdio>
#include <vector>
int map[10][10], origin[10][10], visited[10][10], n, m, tmp, ans, d[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, wallCnt;
std::vector<std::pair<int, int>> toWall;
std::vector<std::pair<int, int>> virus;

int max(int a, int b) {
    return (a>b)?a:b;
}

void calc(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 1 || visited[x][y]) return;
    tmp++;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        calc(x + d[i][0], y + d[i][1]);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i  = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &origin[i][j]);
            if(origin[i][j] == 0) toWall.push_back(std::make_pair(i, j));
            else if(origin[i][j] == 2) virus.push_back(std::make_pair(i, j));
            else wallCnt++;
        }
    }
    for(int i = 0; i < toWall.size(); i++) {
        for(int j = i+1; j < toWall.size(); j++) {
            for(int l = j+1; l < toWall.size(); l++) {
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < m; y++) {
                        map[x][y] = origin[x][y];
                        visited[x][y] = false;
                    }
                }
                map[toWall[l].first][toWall[l].second] = 1;
                map[toWall[j].first][toWall[j].second] = 1;
                map[toWall[i].first][toWall[i].second] = 1;
                tmp = 0;
                for(int i = 0; i < virus.size(); i++) calc(virus[i].first, virus[i].second);
                tmp = n*m - wallCnt - tmp - 3;
                ans = max(ans, tmp);
            }
        }
    }
    printf("%d\n", ans);
}