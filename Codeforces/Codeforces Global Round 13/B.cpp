#include <cstdio>

int T, n, u, v, a[110], cnt, cnt2, cnt3, cnt4, cost, minCost;
bool flag;
int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &u, &v);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        minCost = 987654321;
        for(int i = 0; i < n; i++) {
            cost = 987654321, cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
            if(i != 0 && i != n-1) {
                while(a[i-1] == a[i] + cnt && a[i+1] == a[i] + cnt) cnt++;
                while(a[i-1] == a[i] - cnt2 && a[i+1] == a[i] - cnt2) cnt2++;
                if(a[i] - cnt2 == 0) cost = cnt2*v + u;
                else cost = cnt2*v + min(v, u);

                if(a[i] + cnt == 1e6+1) cost = min(cnt*v + u, cost);
                else cost = min(cost, cnt2*v + min(v, u));
            }
            else if(i == 0) {
                while(a[i+1] == a[i] + cnt) cnt++;
                while(a[i+1] == a[i] - cnt2) cnt2++;
                if(a[i] - cnt2 == 0) cost = cnt2*v + u;
                else cost = cnt2*v + min(v, u);

                if(a[i] + cnt == 1e6+1) cost = min(cost, cnt*v + u);
                else cost = min(cost, cnt2*v + min(v, u));
            }
            else {
                while(a[i-1] == a[i] + cnt) cnt++;
                while(a[i-1] == a[i] - cnt2) cnt2++;
                if(a[i] - cnt2 == 0) cost = cnt2*v + u;
                else cost = cnt2*v + min(v, u);

                if(a[i] + cnt == 1e6+1) cost = min(cost, cnt*v + u);
                else cost = min(cost, cnt2*v + min(v, u));
            }
            minCost = min(cost, minCost);
        }
        printf("%d\n", minCost);
    }
    return 0;
}
