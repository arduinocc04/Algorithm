#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#define MAX_PLANET_CNT 100'010

int planet_cnt, p[MAX_PLANET_CNT];
std::pair<int, int> xs[MAX_PLANET_CNT], ys[MAX_PLANET_CNT], zs[MAX_PLANET_CNT];
std::vector<std::pair<int, std::pair<int, int>>> edges;

int find(int n) {
    if(n == p[n])
        return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    p[n2] = n1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> planet_cnt;

    int x, y, z;
    for(int i = 0; i < planet_cnt; ++i) {
        p[i] = i;
        std::cin >> x >> y >> z;
        xs[i] = {x, i};
        ys[i] = {y, i};
        zs[i] = {z, i};
    }

    std::sort(xs, xs + planet_cnt);
    std::sort(ys, ys + planet_cnt);
    std::sort(zs, zs + planet_cnt);

    for(int i = 1; i < planet_cnt; ++i) {
        edges.push_back({xs[i].first - xs[i - 1].first, {xs[i - 1].second, xs[i].second}});
        edges.push_back({ys[i].first - ys[i - 1].first, {ys[i - 1].second, ys[i].second}});
        edges.push_back({zs[i].first - zs[i - 1].first, {zs[i - 1].second, zs[i].second}});
    }

    std::sort(edges.begin(), edges.end());
    int edge_cnt = 0, i = 0, s = 0;
    while(edge_cnt < planet_cnt - 1) {
        std::pair<int, std::pair<int, int>> t = edges[i++];
        const int w = t.first;
        const int u = t.second.first, v = t.second.second;
        if(find(u) != find(v)) {
            merge(u, v);
            ++edge_cnt;
            s += w;
        }
    }

    std::cout << s;

    return 0;
}
