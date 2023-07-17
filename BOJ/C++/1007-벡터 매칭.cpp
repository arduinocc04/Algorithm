#include <cstdio>
#include <vector>
#include <cmath>

int T, n, x, y;
std::vector<std::pair<int, int>> p;
std::vector<std::pair<int, int>> a;
long long m;

long long getNorm(std::pair<int, int> a) {
    return a.first*a.first + a.second*a.second;
}

long long min(long long a, long long b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            a.push_back(std::make_pair(x, y));
        }
        if(n*(n + 1)/2 % 2 == 0) {
            printf("0\n");
            continue;
        }
        a.clear();
        p.clear();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                p.push_back(std::make_pair(a[i].first - a[j].first, a[i].second - a[j].second));
            }
        }
        m = getNorm(p[0]);
        for(int i = 1; i < p.size(); i++) {
            m = min(m, getNorm(p[i]));
        }
        printf("%f\n", std::sqrt(m));
    }
}