#include <cstdio>

int T, n, k, cnt;
bool possible[1010];

void calc(int notToMake) {
    if(notToMake <= 1) return;
    for(int i = 1; i <= n; i++) {
        if(notToMake - i >= 0 && possible[i] && k != 2*i) possible[(k == i)?k:k - i] = false;
    }
    for(int i = 1; i <= n; i++) {
        if(notToMake - i >= 0) {
            calc(i);
        }
    }
    return;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) possible[i] = true;
        calc(k);
        cnt = 0;
        for(int i = 1; i <= n; i++) if(possible[i]) cnt++;
        printf("%d\n", cnt);
        for(int i = 1; i <= n; i++) if(possible[i]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
