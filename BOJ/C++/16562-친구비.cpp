#include <cstdio>
#include <algorithm>

int n, m, k, a[10100], p[10010], tmp1, tmp2, res;
bool visited[10010];

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(a[n1] < a[n2]) p[n2] = n1;
    else p[n1] = n2;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        visited[i] = false;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        merge(tmp1-1, tmp2-1);
    }
    for(int i = 0; i < n; i++) find(i);
    res = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[p[i]]) {
            visited[p[i]] = true;
            res += a[p[i]];
        }
    }
    if(res <= k) printf("%d", res);
    else printf("Oh no");
}