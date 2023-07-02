#include <cstdio>
#include <deque>

int n, m, map[1010][1010], dist[1010][1010], startR, startC, l, nowX, nowY, depth, tmpX, tmpY;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

std::deque<std::pair<std::pair<int, int>, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = 987654321;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 2) {
                startR = i;
                startC = j;
                break;
            }
        }
    }

    q.push_back(std::make_pair(std::make_pair(startR, startC), 0));
    while(!q.empty()) {
        l = q.size();
        for(int i = 0; i < l; i++) {
            nowX = q.front().first.first;
            nowY = q.front().first.second;
            depth = q.front().second;
            dist[nowX][nowY] = depth;
            q.pop_front();
            for(int j = 0; j < 4; j++) {
                tmpX = nowX + dx[j]; tmpY = nowY + dy[j];
                if(0 <= tmpX && tmpX < n && 0 <= tmpY && tmpY < m && dist[tmpX][tmpY] == 987654321 && map[tmpX][tmpY] != 0) {
                    q.push_back(std::make_pair(std::make_pair(tmpX, tmpY), depth + 1));
                    dist[tmpX][tmpY] = -2;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] == 987654321) {
                if(map[i][j] == 0) dist[i][j] = 0;
                else dist[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}