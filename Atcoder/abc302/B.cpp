#include <iostream>
#include <string>
#include <vector>
#include <utility>

int h, w;
std::string board[110];
std::string target = "snuke";

bool find(int r, int c, int dir, int cnt, std::vector<std::pair<int, int>> & hist) {
    if(cnt == 5) {
        return true;
    }
    if(r < 0 || r >= h)
        return false;
    if(c < 0 || c >= w)
        return false;

    if(board[r][c] != target[cnt]) return false;

    hist.push_back({r, c});

    if(dir == 0)
        return find(r, c + 1, dir, cnt + 1, hist);
    else if(dir == 1)
        return find(r, c - 1, dir, cnt + 1, hist);
    else if(dir == 2)
        return find(r + 1, c, dir, cnt + 1, hist);
    else if(dir == 3)
        return find(r - 1, c, dir, cnt + 1, hist);
    else if(dir == 4)
        return find(r + 1, c + 1, dir, cnt + 1, hist);
    else if(dir == 5)
        return find(r + 1, c - 1, dir, cnt + 1, hist);
    else if(dir == 6)
        return find(r - 1, c + 1, dir, cnt + 1, hist);
    else if(dir == 7)
        return find(r - 1, c - 1, dir, cnt + 1, hist);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> h >> w;
    for(int i = 0; i < h; ++i) {
        std::cin >> board[i];
    }

    std::vector<std::pair<int, int>> ans;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            for(int dir = 0; dir < 8; ++dir) {
                ans.clear();
                if(find(i, j, dir, 0, ans)) {
                    for(int k = 0; k < ans.size(); ++k) {
                        std::cout << ans[k].first + 1 << " " << ans[k].second + 1 << std::endl;
                    }
                    return 0;
                }
            }
        }
    }
}