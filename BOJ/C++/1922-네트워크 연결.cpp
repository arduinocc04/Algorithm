#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

int n, m, p[1010];
std::vector<std::tuple<int, int, int>> costs;

bool compare(std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
    return std::get<2>(a) < std::get<2>(b);
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}
void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 < n2) p[n2] = n1;
    else p[n1] = n2;
}
bool isInSameSet(int n1, int n2) {
    return find(n1) == find(n2);
}

int main() {
    int tmp1, tmp2, tmp3;
    scanf("%d %d", &n, &m);
    costs.resize(m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        costs[i] = (std::make_tuple(tmp1-1, tmp2-1, tmp3));
    }
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
    std::sort(costs.begin(), costs.end(), compare);
    int cnt = 0, i = 0, cost = 0;
    while (cnt < n-1) {
        if(!isInSameSet(std::get<0>(costs[i]), std::get<1>(costs[i]))) {
            cnt++;
            cost += std::get<2>(costs[i]);
            merge(std::get<0>(costs[i]), std::get<1>(costs[i]));
        }
        i++;
    }
    printf("%d", cost);
}