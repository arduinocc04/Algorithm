#include <iostream>
#include <vector>
#include <algorithm>

int chess_board_length;
int possible[11][11];
bool possible_diag_1[25];

int max_val;

void calc(int i, int cnt) {
    if(i == 2*chess_board_length - 1) {
        max_val = std::max(max_val, cnt);
        return;
    }

    if(2*chess_board_length - i + cnt <= max_val) return;

    int place_r, place_c;
    if(i < chess_board_length) {
        for(int r = 0; r < i + 1; ++r) {
            const int c = chess_board_length - i - 1 + r;
            if(possible[r][c] && possible_diag_1[r + c]) {
                possible_diag_1[r + c] = false;
                calc(i + 1, cnt + 1);
                possible_diag_1[r + c] = true;
            }
        }
    } else {
        for(int r = i - chess_board_length + 1; r < chess_board_length; ++r) {
            const int c = chess_board_length - i - 1 + r;
            if(possible[r][c] && possible_diag_1[r + c]) {
                possible_diag_1[r + c] = false;
                calc(i + 1, cnt + 1);
                possible_diag_1[r + c] = true;
            }
        }
    }

    calc(i + 1, cnt);
    return;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> chess_board_length;
    for(int i = 0; i < chess_board_length; ++i) {
        for(int j = 0; j < chess_board_length; ++j) {
            std::cin >> possible[i][j];
        }
    }
    for(int i = 0; i < 25; ++i)
        possible_diag_1[i] = true;

    calc(0, 0);
    std::cout << max_val;
}
