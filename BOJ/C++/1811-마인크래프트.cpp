#include <cstdio>

int m, n, b, map[510][510], max, min;

int possible(int k) {
    int tmp = b;
    int time = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (map[i][j] > k) time += 2*(map[i][j]-k);
            else time += k-map[i][j];
            tmp -= k - map[i][j];
        }
    }
    if (tmp < 0) return -1;
    return time;
}

int main() {
    scanf("%d %d %d", &n, &m, &b);
    max = 0;
    min = 257;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] > max) max = map[i][j];
            if(map[i][j] < min) min = map[i][j];
        }
    }
    int res = (1<<31)-1, t, tmp;
    for(int i = min; i < max+1; i++) {
        tmp = possible(i);
        if(tmp != -1 && res >= tmp) {
            res = tmp;
            t = i;
        }
    }
    printf("%d %d", res, t);
}