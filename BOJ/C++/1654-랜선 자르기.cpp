#include <cstdio>
int k, n, tmp, lans[10010];

bool calc(int i) {
    long long res = 0;
    for(int j = 0; j < k; j++) {
        res += lans[j]/i;
    }
    return res >= n;
}

int main() {
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++) {
        scanf("%d", &tmp);
        lans[i] = tmp;
    }
    unsigned int mid, res, lo = 0, hi = (1<<31) -1;
    while(lo <= hi) {
        mid = (lo + hi)/2;
        if (calc(mid)) {
            res = mid;
            lo = mid +1;
        }
        else {
            hi = mid -1;
        }
    }
    printf("%d", res);
}