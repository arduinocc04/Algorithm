#include <cstdio>

int n, tmp1, tmp2, tmp;
char board[55][55];
int calcRows[55][4];
int calcCols[55][4];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int calcRow(int i) {
    int prev = board[i][0];
    int cnt = 0;
    int _max = 0;
    for(int j = 1; j < n; j++) {
        if(prev == board[i][j]) {
            cnt++;
        }
        else {
            _max = max(_max, cnt);
        }
        prev = board[i][j];
    }
    _max = max(_max, cnt);
    return _max;
}
int calcRow(int i) {
    int prev = board[0][i];
    int cnt = 0;
    int _max = 0;
    for(int j = 1; j < n; j++) {
        if(prev == board[j][i]) {
            cnt++;
        }
        else {
            _max = max(_max, cnt);
        }
        prev = board[j][i];
    }
    _max = max(_max, cnt);
    return _max;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= i; k++) {
                for(int l = 0; n*k + l < n*i + j; l++) {
                    if(board[i][j] == board[k][l]) continue;
                    tmp = board[i][j];
                    board[i][j] = board[k][l];
                    board[k][l] = tmp;
                    tmp1 = calcRow()
                }
            }
        }
    }
}