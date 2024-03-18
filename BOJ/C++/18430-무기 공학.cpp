#include <iostream>
#include <algorithm>

#define MAX_ROWS 7
#define MAX_COLS 7

int ans, rows, cols, board[MAX_ROWS][MAX_COLS];
bool used[MAX_ROWS][MAX_COLS];

inline bool possible(int r, int c) {
    if(r < 0 || r >= rows) return false;
    if(c < 0 || c >= cols) return false;
    return !used[r][c];
}

void calc(int r, int c, int sum = 0) {
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, -1, 0, 1};

    if(r == rows) {
        ans = std::max(ans, sum);
        return;
    }

    for(int i = 0; i < 4; ++i) {
        const int tx1 = r + dx[i], ty1 = c + dy[i];
        const int tx2 = r + dx[(i + 1) % 4], ty2 = c + dy[(i + 1)%4];
        if(!possible(tx1, ty1))
            continue;
        if(!possible(tx2, ty2))
            continue;
        if(!possible(r, c))
            continue;

        used[r][c] = true;
        used[tx1][ty1] = true;
        used[tx2][ty2] = true;

        if(c < cols - 1)
            calc(r, c + 1, sum + 2*board[r][c] + board[tx1][ty1] + board[tx2][ty2]);
        else
            calc(r + 1, 0, sum + 2*board[r][c] + board[tx1][ty1] + board[tx2][ty2]);

        used[r][c] = false;
        used[tx1][ty1] = false;
        used[tx2][ty2] = false;
    }

    if(c < cols - 1)
        calc(r, c + 1, sum);
    else
        calc(r + 1, 0, sum);

}

int main() {
    std::cin >> rows >> cols;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            std::cin >> board[i][j];
        }
    }
    calc(0, 0, 0);

    std::cout << ans;
}
