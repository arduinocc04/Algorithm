#include <cstdio>
#include <vector>
int n, p[300010], tmp1, tmp2;

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 < n2) p[n2] = n1;
    else p[n1] = n2;
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n-2; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        tmp1--, tmp2--;
        merge(tmp1, tmp2);
    }
    for(int i = 0; i < n; i++) find(i);
    std::vector<int> res;
    for(int i = 0; i < n; i++) if(i == p[i]) res.push_back(i);
    printf("%d %d", res[0]+1, res[1]+1);
}