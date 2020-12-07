#include <cstdio>
#include <algorithm>
#include <vector>

int n, m;
char map[9][9], origin[9][9];
std::vector<std::pair<int,int>> starts, emptys;

std::pair<int,int> d[4] = {std::make_pair(-1,0), std::make_pair(1,0), std::make_pair(0, -1), std::make_pair(0,1)};

int DFS(std::pair<int,int> node) {
    std::pair<int, int> tmp;
    for(int i = 0; i < 4; i++) {
        tmp.first = node.first + d->first;
        tmp.second = node.second + d->second;
    }
    if(0 <= tmp.first <= m && 0 <= tmp.second <= n && map[tmp.second][tmp.first] == 0) {
        map[tmp.second][tmp.first] = 2;
        DFS(tmp);
    }
}
int dfs() {
    for(int i = 0; i < starts.size(); i++) {
        DFS(starts[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &origin[i][j]);
            if(origin[i][j] == 2) {
                starts.push_back(std::make_pair(i,j));
            }
            else if(origin[i][j] == 0) {
                emptys.push_back(std::make_pair(i, j));
            } 
        }
    }
    int ans = 987654321;
    for(int i = 0; i < emptys.size(); i++) {
        for(int j = i+1; j < emptys.size(); j++) {
            for(int k = j+1; k < emptys.size(); k++) {
                std::copy(&origin[0][0], &origin[0][0] + n*m, &map[0][0]);
                map[emptys[i].first]
                ans = std::max(ans, dfs());
            }
        }
    }
    printf("%d", ans);
    return 0;
}