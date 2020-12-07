#include <cstdio>

int main() {
    int t, n, k, j, i;
    bool flag;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        flag = false;
        for(i = 0; i < 144; i++) {
            for(j = 0; j < 201; j++) {
                if(7*i + 5*j > n) break;
                for(k = 0; k < 340; k++) {
                    if(7*i + 5*j + 3*k > n) {
                        break;
                    }
                    if(7*i + 5*j + 3*k == n) {
                        flag = true;
                        goto out;
                    }
                }
            }
        }
        out:
        if(flag) printf("%d %d %d\n", k, j, i);
        else printf("-1\n");
    }
}