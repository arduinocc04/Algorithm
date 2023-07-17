#include <cstdio>

int n, k, a[300'010], b[300'010];

bool calc(int d) {
    long long res = 0;
    for(int i = 0; i < n; i++) {
        if(d <= a[i]) {
            res += b[i];
            if(res > k) return false;
        }
    }
    return true;
} 

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    int m, s = 1, e = 1e9 + 2;
    while(s < e) {
        m = (s + e)/2;
        if(calc(m)) e = m;
        else s = m + 1;
    }
    printf("%d", s);
    return 0;
}
