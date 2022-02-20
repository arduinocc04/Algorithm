#include <cstdio>

int C, time[20], connection[10][5] = {{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};
int ans;
int start[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sizes[] = {3, 4, 4, 5, 5, 4, 3, 5, 5, 5};
int num[20];

void solve(int state[15], int now, int sum) {
    if(sum >= ans) return;
    if(now == 10) {
        for(int i = 0; i < 16; i++) {
            num[i] = time[i];
        }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < sizes[i]; j++) {
                num[connection[i][j]] += 3 * state[i];
                if(num[connection[i][j]] > 12) num[connection[i][j]] -= 12;
            }
        }
        for(int i = 0; i < 16; i++) {
            if(num[i] != 12) {
                return;
            }
        }
        ans = sum;
        return;
    }
    if(now == 9) {
        solve(state, now+1, sum);
    }
    else {
        for(int i = 0; i < 4; i++) {
            state[now+1] = i;
            solve(state, now+1, sum + i);
        }
    }
    return;

}

int main() {
    
    scanf("%d", &C);
    while(C--) {
        for(int i = 0; i < 16; i++) {
            scanf("%d", &time[i]);
        }
        ans = 9876;
        for(int i = 0; i < 4; i++) {
            start[0] = i;
            solve(start, 0, i);
        }
        if(ans != 9876) printf("%d\n", ans);
        else printf("-1\n");
    }
}