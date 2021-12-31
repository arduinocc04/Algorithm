#include <cstdio>
#include <vector>
int T, n,cnt, start;
char grid[310][310];
std::vector<std::pair<int, std::pair<int,int>>> row;
std::vector<std::pair<int, std::pair<int,int>>> col;
bool leftTop, rightTop, flagr, flagc;
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> res;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        row.clear();
        col.clear();
        while(true) {
            res.clear();
            //leftTop = true, rightTop = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == '.') continue;
                    cnt = 0;
                    while(j+cnt < n && grid[i][j] == grid[i][j+cnt]) cnt++;
                    if(cnt > 2) {
                        res.push_back(std::make_pair(std::make_pair(i, j), std::make_pair(i, j+cnt)));
                        row.push_back(std::make_pair(i, std::make_pair(j, j+cnt)));
                        j += cnt;
                    }
                    /*
                    if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2] && grid[i][j] != '.') {
                        res.push_back(std::make_pair(true, std::make_pair(i, std::make_pair(j, j+2))));
                        j+= 2;
                       // grid[i][j+1] = (grid[i][j+1]=='X')?'O':'X';
                    }*/
                }
                /*
                flagr = true;
                for(int j = 0; j < n; j++) {
                    if(grid[i][0] != grid[i][j]) flagr = false;
                }
                if(flagr) row.push_back(i);

                flagc = true;
                for(int j = 0; j < n; j++) {
                    if(grid[0][i] != grid[j][i]) flagc = false;
                }
                if(flagc) col.push_back(i);
                */
                //if(grid[0][0] != grid[i][i]) leftTop = false;
                //if(grid[n-1][0] != grid[n-1-i][i]) rightTop = false;
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[j][i] == '.') continue;
                    cnt = 0;
                    while(j+cnt < n && grid[j][i] == grid[j+cnt][i]) cnt++;
                    if(cnt > 2) {
                        res.push_back(std::make_pair(std::make_pair(j, i), std::make_pair(j+cnt, i)));
                        col.push_back(std::make_pair(i, std::make_pair(j, j+cnt)));
                        j += cnt;
                    }
                }
            }
            if(res.size() == 0) break;
            /*
            printf("r: ");
            for(int i = 0; i < row.size(); i++) printf("%d", row[i]);
            printf("\n");
            printf("c: ");
            for(int i = 0; i < col.size(); i++) printf("%d", col[i]);
            printf("\n");
            */
            /*
            int tmp = 0;
            if(leftTop) {
                if(row.size() > 0) {
                    grid[row[0]][row[0]] = (grid[row[0]][row[0]]=='X')?'O':'X';
                    row[0] = -1;
                    if(row[0] == n/2 && (n%2)) rightTop = false;
                }
                else if(col.size() > 0) {
                    grid[col[0]][col[0]] = (grid[col[0]][col[0]]=='X')?'O':'X';
                    col[0] = -1;
                    if(col[0] == n/2 && (n%2)) rightTop = false;
                    tmp++;
                }
            }
            if(rightTop) {
                if(row.size() > 1) {
                    grid[row[1]][row[1]] = (grid[row[1]][row[1]]=='X')?'O':'X';
                    row[1] = -1;
                }
                else if(col.size() > tmp) {
                    grid[col[tmp]][col[tmp]] = (grid[col[tmp]][col[tmp]]=='X')?'O':'X';
                    col[tmp] = -1;
                }
            }
            tmp = 0;
            while(tmp < row.size() && row[tmp] == -1) tmp++;
            int tmp2 = 0;
            while(tmp2 < col.size() && col[tmp2] == -1) tmp2++;
            */
            /*
            int i, j, tmp = 0, tmp2 = 0;
            for(i = tmp; i < row.size(); i++) {
                for(j = tmp2; j < col.size(); j++) {
                    grid[row[i]][col[j]] = (grid[row[i]][col[j]]=='X')?'O':'X';
                    i++, j++;
                    if(i >= row.size() || j >= col.size()) break;
                }
                if(i >= row.size() || j >= col.size()) break;
            }
            while(i < row.size()) {
                grid[row[i]][0] = (grid[row[i]][0]=='X')?'O':'X';
                i++;
            }
            while(j < col.size()) {
                grid[col[j]][0] = (grid[col[j]][0]=='X')?'O':'X';
                j++;
            }
            */
            printf("%d\n", res.size());
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%c", grid[i][j]);
                }
                printf("\n");
            }
            /*
            for(int i = 0; i < res.size(); i++) {
                for(int j = 0; j < res.size(); j++) {
                    if(res[i].first.second == res[i].second.second && res[j].first.first == res[j].second.first && res[i].first.first <= res[j].first.first && res[j].first.first <= res[i].second.first && res[j].first.second <= res[i].first.second && res[i].first.second <= res[j].second.second) {
                        grid[res[j].first.first][res[i].first.second] = (grid[res[j].first.first][res[i].first.second]=='X')?'O':'X';
                        //if(res[i].first.second - res[i].first.first == 3) break;
                        break;
                    }
                }
            }
            */
           for(int i = 0; i < row.size(); i++) {
               for(int j = 0; j < col.size(); j++) {
                   if(row[i].second.first <= col[j].first && col[j].first <= row[i].second.second && col[j].second.first <= row[i].first && row[i].first <= col[j].second.second) {
                       grid[row[i].first][col[j].first] = (grid[row[i].first][col[j].first]=='X')?'O':'X';
                       col.erase(col.begin() + j);
                       break;
                   }
               }
           }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
