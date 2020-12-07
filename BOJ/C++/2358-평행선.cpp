#include <cstdio>
#include <algorithm>
int n, tmp1, tmp2, xs[100010], ys[100010];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        xs[i] = tmp1;
        ys[i] = tmp2;
    }
    std::sort(xs, xs+n);
    std::sort(ys, ys + n);
    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        if(xs[i] == xs[i+1]) {
            cnt++;
            tmp1 = i;
            while(i < n && xs[tmp1] == xs[i]) i++;
            i--;
        }
    }
    for(int i = 0; i < n-1; i++) {
        if(ys[i] == ys[i+1]) {
            cnt++;
            tmp1 = i;
            while(i < n && ys[tmp1] == ys[i]) i++;
            i--;
        }
    }
    printf("%d", cnt);
}