#include <cstdio>
#include <algorithm>

int main() {
    int n, sizes[100001], tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sizes[i] = tmp;
    }
    std::sort(sizes, sizes+n);
    int cnt = 0, *a, res;
    float tmp2;
    for(int i = 0; i < n; i++) {
        tmp2 = (float)sizes[i]*0.9;
        a = std::lower_bound(sizes, sizes + n, tmp2);
        res = a - sizes + 1;
        cnt += i - res + 1;
    }
    printf("%d", cnt);
    return 0;
}