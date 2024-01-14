#include <cstdio>
#include <algorithm>
#include <vector>

int n, m, k, u, v, w, x, p[1'010];
std::vector<int> power_plants;
std::vector<std::pair<int, std::pair<int, int>>> edges;

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    p[n1] = n2;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &x);
        power_plants.push_back(x);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(std::make_pair(w, std::make_pair(u, v)));
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < k; i++) p[power_plants[i]] = 0;
    std::sort(edges.begin(), edges.end());
    int ans = 0;
    for(int i = 0; i < m; i++) {
        w = edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;
        if(find(u) != find(v)) {
            merge(u, v);
            ans += w;
        }
    }
    printf("%d", ans);
}
