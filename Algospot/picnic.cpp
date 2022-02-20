#include <cstdio>

int C, n, m, a, b, ans;
bool isFriend[15][15];

void make(bool taken[15]) {
    int firstFree = -1;
    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) {
        ans++;
        return;
    }
    taken[firstFree] = true;
    for(int i = firstFree +1; i < n; i++) {
        if (isFriend[firstFree][i] && !taken[i]) {
            taken[i] = true;
            make(taken);
            taken[i] = false;
        }
    }
    taken[firstFree] = false;
    return;
}

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 12; j++) {
                isFriend[i][j] = false;
            }
        }
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            isFriend[a][b] = isFriend[b][a] = true;
        }
        ans = 0;
        bool t[15] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
        make(t);
        printf("%d\n", ans);
    }
    return 0;
}