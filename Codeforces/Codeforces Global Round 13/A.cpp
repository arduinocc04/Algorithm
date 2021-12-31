#include <cstdio>
#include <utility>
int n, q, t, x, oneCnt, zeroCnt, tmp;
bool a[100010];
int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(tmp == 1) a[i] = true;
        else a[i] = false;

        if(tmp == 1) oneCnt++;
        else zeroCnt++;
    }
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &t, &x);
        if(t == 1) {
            if(a[x - 1]) {
                zeroCnt++;
                oneCnt--;
                a[x-1] = false;
            }
            else {
                oneCnt++;
                zeroCnt--;
                a[x-1] = true;
            }
        }
        else {
            if(x <= oneCnt) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
