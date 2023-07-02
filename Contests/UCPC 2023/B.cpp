#include <cstdio>
#include <algorithm>
#include <vector>

int n, k, m, c[100'010], tmp, p[100'010], tmpI, tmpJ;
std::pair<int, std::pair<int, int>> edges[300'010];
std::vector<std::pair<int, std::pair<int, int>>> mst;
std::vector<std::pair<int, int>> graph[100'010];
long long dist[100'010][100'010];

int abs(int x) {
    if(x > 0) return x;
    return -x;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a > b) return b;
    return a;
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    p[a] = b;
}

bool sameParent(int a, int b) {
    return find(a) == find(b);
}

int main() {
    for(int i = 0; i < n; i++) p[i] = i;

    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].second.first, &edges[i].second.second, &tmp);
        edges[i].first = -tmp;
    }
    std::sort(edges, edges + m);

    for(int i = 0; i < m; i++) {
        tmpI = edges[i].second.first;
        tmpJ = edges[i].second.second;
        if(!sameParent(tmpI, tmpJ)) {
            merge(tmpI, tmpJ);
            graph[tmpI].push_back(std::make_pair(tmpJ, edges[i].first));
            graph[tmpJ].push_back(std::make_pair(tmpI, edges[i].first));
        }
    }
    int prev = 1;
    for(int i = 0; i < n - 1; i++) {
        int next = (graph[prev][0].first != prev)?graph[prev][0].first:graph[prev][1].first;

    }
}