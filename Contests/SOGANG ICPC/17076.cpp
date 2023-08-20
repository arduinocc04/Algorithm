#include <cstdio>

int k, a[200'010], n, m, cnt;
bool deleted[200'010];

int main() {
    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d", &a[i]);

    n = a[0];
    m = a[1];

    for(int i = 0; i < k - 2; i++) {
        if(a[i + 2] > n) deleted[i] = true;
        else cnt++;
    }

    if(cnt % 2) {
        for(int i = 0; i < k - 2; i++) {
            if(!deleted[i + 2]) {
                deleted[i + 2] = true;
                break;
            }
        }
    }

    if(cnt /2 < m) {
        printf("-1\n");
        return;
    }
    if()

}