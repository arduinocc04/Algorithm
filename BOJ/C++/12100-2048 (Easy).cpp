#include <iostream>

int n, board[21][21];

void print_board() {
    std::cout << "=========" << std::endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "=========" << std::endl;
}

void rotate_cw() {
    const int shell_cnt = (n/2) + n % 2;
    if(n == 1)
        return;

    int t[21];
    for(int i = 0; i < shell_cnt; ++i) {
        for(int j = i; j < n - i; ++j) {
            t[j] = board[i][j];
        }

        for(int j = i; j < n - i; ++j) {
            board[i][j] = board[n - j - 1][i];
        }
        for(int j = i; j < n - i; ++j) {
            board[j][i] = board[n - i - 1][j];
        }
        for(int j = i; j < n - i; ++j) {
            board[n - i - 1][j] = board[n - j - 1][n - i - 1];
        }
        for(int j = i; j < n - i; ++j) {
            board[j][n - i - 1] = t[j];
        }
    }
}

void push_to_right() {
    for(int r = 0; r < n; ++r) {
        bool last_can_merged = true;
        for(int c = n - 1; c >= 0; --c) {
            if(board[r][c] == 0)
                continue;

            int right_cnt = 1;
            while(c + right_cnt < n - 1 && board[r][c + right_cnt] == 0)
                ++right_cnt;

            if(c + right_cnt == n) {
                if(right_cnt == 1) continue;
                board[r][n - 1] = board[r][c];
                board[r][c] = 0;
                last_can_merged = true;
            }
            else if(board[r][c + right_cnt] == 0) {
                board[r][c + right_cnt] = board[r][c];
                board[r][c] = 0;
                last_can_merged = true;
            }
            else {
                const int t = board[r][c];
                board[r][c] = 0;

                if(last_can_merged && t == board[r][c + right_cnt]) {
                    last_can_merged = false;
                    board[r][c + right_cnt] *= 2;
                }
                else {
                    last_can_merged = true;
                    board[r][c + right_cnt - 1] = t;
                }
            }
        } /*
        for(int c = n - 1; c >= 0; --c) {
            if(board[r][c]) {
                int right_cnt = 0;
                while(c + right_cnt < n - 1 && board[r][c + right_cnt + 1] == 0)
                    ++right_cnt;
                if(right_cnt > 0) {
                    board[r][c + right_cnt] = board[r][c];
                    board[r][c] = 0;
                }
            }
        }
        */
    }
}

int dfs(int depth) {
    // print_board();
    if(depth == 5) {
        int max_val = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                max_val = std::max(max_val, board[i][j]);
            }
        }
        return max_val;
    }

    int prev_board[21][21];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            prev_board[i][j] = board[i][j];
        }
    }

    int ans = -1;
    for(int i = 0; i < 4; ++i) {
        for(int k = 0; k < i; ++k) {
            rotate_cw();
        }
        push_to_right();
        ans = std::max(ans, dfs(depth + 1));
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; ++j) {
                board[k][j] = prev_board[k][j];
            }
        }
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }
    /*
    rotate_cw();
    print_board();
    rotate_cw();
    print_board();
    rotate_cw();
    print_board();
    push_to_right();
    print_board();
    */

    std::cout << dfs(0);
}
