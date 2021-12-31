#include <cstdio>
#include <cmath>
#include <algorithm>
int T, n, a[60], current, cnt;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        cnt = 0;
        for(int i = 0; i < n-1; i++) {
            cnt += (int)std::log2((double)std::max(a[i+1], a[i])/std::min(a[i+1], a[i]));
            current = 1;
            if((double)std::max(a[i+1], a[i])/std::min(a[i+1], a[i]) == 1) continue;
            while(current <= (double)std::max(a[i+1], a[i])/std::min(a[i+1], a[i])) {
                if(current == (double)std::max(a[i+1], a[i])/std::min(a[i+1], a[i])) {
                    cnt--;
                }
                current <<= 1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
