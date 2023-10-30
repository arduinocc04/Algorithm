#include <iostream>
#include <string>
#include <vector>

int r, c;
std::string map[15];
int dx[] = {-1, 1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};
std::vector<std::pair<int, int>> cands;

bool dfs(int x, int y, int prev, int startX, int startY, int targetX, int targetY, bool phase2) {
    if(phase2) {
        if(x == startX && y == startY) return true;
    }
    else {
        if(x == targetX && y == targetY) phase2 = true;
    }
    for(int i = 0; i < 4; i++) {
        if(dx[prev]*dx[i] <= 0 && dy[prev]&dy[i] <= 0 && dx[prev]*dx[i] != dy[prev]*dy[i]) continue;
        int tmpX = x + dx[i], tmpY = y + dy[i];
        if(0 <= tmpX && tmpX < r && 0 <= tmpY && tmpY < c && map[tmpX][tmpY] == '.') {
            return dfs(tmpX, tmpY, i, startX, startY, targetX, targetY, phase2);
        }
    }
    return false;
}

int main() {
    std::cin >> r >> c;
    for(int i = 0; i < r; i++) std::cin >> map[i];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] == '.') cands.push_back(std::make_pair(i, j));
        }
    }
    for(int i = 0; i < cands.size(); i++) {
        for(int j = i + 1; j < cands.size(); j++) {
            if(!dfs(cands[i].first, cands[i].second, 4, cands[i].first, cands[i].second, cands[j].first, cands[j].second, false)) {
                printf("1");
                return 0;
            }
        }
    }
    printf("0");
}