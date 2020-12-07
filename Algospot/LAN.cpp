//LAN
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <tuple>

int p[510], n, T, m;
std::pair<int, int> buildings[510];
std::tuple<double, int, int> edges[300000];

double getDist(std::pair<int,int> n1, std::pair<int,int> n2) {
    return sqrt(pow(n1.first - n2.first, 2) + pow(n1.second - n2.second, 2));
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 < n2) p[n2] = n1;
    else p[n1] = n2;
}

bool isInSameSet(int n1, int n2) {return find(n1) == find(n2);}

bool compare(int *a, int *b) {
    return a[2] > b[2];
}

int main() {
    scanf("%d", &T);
    int k, cnt, a, b;
    double w, s;
    while(T--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < n; i++) scanf("%d", &buildings[i].first);
        for(int i = 0; i < n; i++) scanf("%d", &buildings[i].second);
        k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edges[k] = std::make_tuple(getDist(buildings[i], buildings[j]), i, j);
                k++;
            }
        }
        std::sort(edges, edges + k);
        cnt = m;
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if(isInSameSet(a,b)) cnt--;
            else merge(a,b);
        }
        s = 0;
        for(int i = 0; i < k; i++) {
            w = std::get<0>(edges[i]);
            a = std::get<1>(edges[i]);
            b = std::get<2>(edges[i]);
            if (!isInSameSet(a,b)) {
                s += w;
                merge(a,b);
            }
        }
        printf("%.10lf\n", s);
    }
}