#include <cstdio>

int T, n, a[30010], c[3], target, cnt;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        c[0] = 0, c[1] = 0, c[2] = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) {
            c[a[i]%3]++;
        }
        target = n/3;
        cnt = 0;
        if(c[2] < target) {
            if(c[1] >= target) {
                if(c[0] >= target) {
                    cnt += c[0] - target;
                    c[1] += cnt;
                    cnt += c[1] - target;
                }
                else {
                    cnt += c[1] - target;
                    c[2] += cnt;
                    cnt += c[2] - target;
                }
            }
            else {
                cnt = c[1];
                cnt = target-c[1] + 2*(target-c[2]);
            }
        }
        else {
            if(c[1] >= target) {
                cnt += c[1] - target;
                c[2] += cnt;
                cnt += c[2] - target;
            }
            else {
                cnt += c[2] - target;
                c[0] += cnt;
                cnt += c[0] - target;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
