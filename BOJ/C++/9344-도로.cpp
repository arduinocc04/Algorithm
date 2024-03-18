#include <iostream>
#include <algorithm>
#include <utility>

int n, m, gu, gv, p[10'010];
std::pair<int, std::pair<int, int>> edges[20'010];


int find(int n) {
    if(n == p[n])
        return n;
    return p[n] = find(p[n]);
}

inline void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    p[n2] = n1;
}

bool solve() {
    std::cin >> n >> m >> gu >> gv;
    for(int i = 0; i < 10'010; ++i)
        p[i] = i;

    int u, v, w;
    for(int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }

    std::sort(edges, edges + m);

    int edge_cnt = 0, i = 0;
    while(edge_cnt < n - 1) {
        std::pair<int, std::pair<int, int>> t = edges[i++];
        const int w = t.first, u = t.second.first, v = t.second.second;
        if(find(u) != find(v)) {
            merge(u, v);
            ++edge_cnt;
            if((u == gu && v == gv) || (u == gv && v == gu))
                return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int tc_cnt;
    std::cin >> tc_cnt;
    for(int i = 0; i < tc_cnt; ++i) {
        if(solve())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
