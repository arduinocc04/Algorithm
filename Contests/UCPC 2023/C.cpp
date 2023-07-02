#include <cstdio>
#include <algorithm>
#include <math.h>

int p[1010], r[1010], n, tmpI, tmpJ;
std::pair<int, int> centers[1010];
std::pair<double, std::pair<int, int>> edges[500'000];
double res;

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

double calcEdge(std::pair<int, int> c1, std::pair<int, int> c2, int r1, int r2) {
    double d = std::sqrt((c1.first - c2.first)*(c1.first - c2.first) + (c1.second - c2.second)*(c1.second - c2.second));
    if(d == 0) return 0;
    double r = abs(r1 -r2);
    double theta = std::acos(r/d);
    double res = 2*d*std::sin(theta);
    res += max(r1, r2)*(2*M_PI - 2*theta);
    res += min(r1, r2)*2*theta;
    
    return res;
}

bool calcCircle(std::pair<int, int> c1, std::pair<int, int> c2, int r1, int r2) {
    int d1 = (c1.first - c2.first)*(c1.first - c2.first) + (c1.second - c2.second)*(c1.second - c2.second);
    return d1 <= (r1 + r2)*(r1 + r2);
}

int main() {
    for(int i = 0; i < 1010; i++) {
        p[i] = i;
    }
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &centers[i].first, &centers[i].second, &r[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(calcCircle(centers[i], centers[j], r[i], r[j])) {
                merge(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) find(i);
    // for(int i = 0; i < n; i++) printf("%d ", p[i]);
    // printf("\n");

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n ;j++) {
            edges[cnt] = std::make_pair(calcEdge(centers[i], centers[j], r[i], r[j]), std::make_pair(i, j));
            cnt++;
        }
    }
    std::sort(edges, edges + cnt);

    // for(int i = 0; i < cnt; i++) {
    //     printf("w: %f, i: %d, j:%d\n", edges[i].first, edges[i].second.first, edges[i].second.second);
    // }

    for(int i = 0; i < cnt; i++) {
        tmpI = edges[i].second.first;
        tmpJ = edges[i].second.second;
        if(!sameParent(tmpI, tmpJ)) {
            res += edges[i].first;
            merge(tmpI, tmpJ);
        }
    }
    printf("%.10f", res);
}