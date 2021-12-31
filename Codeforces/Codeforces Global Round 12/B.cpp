#include <cstdio>
#include <utility>
#include <vector>
int T, n, k, p[110];
std::pair<int, int> dots[110];
std::vector<std::pair<int, int>> edges;
std::vector<int> something[110];

int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int getDist(std::pair<int, int> a, std::pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int find(int x) {
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 < n2) p[n2] = n1;
    else p[n1] = n2;
}

bool isInSameSet(int n1, int n2) {
    return find(n1) == find(n2);
}

bool allSame() {
    int a = p[0];
    for(int i = 1; i < n; i++) if(p[i] != a) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < n; i++) scanf("%d %d", &dots[i].first, &dots[i].second);
        edges.clear();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(getDist(dots[i], dots[j]) <= k) {
                    edges.push_back(std::make_pair(i, j));
                }
            }
        }
        for(int i = 0; i < n; i++) find(i);
        int cnt = 1;
        while(!allSame()) {
            for(int i = 0; i < n; i++) something[i].clear();
            for(int i = 0; i < n; i++) something[p[i]].push_back(i);
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    
                }
            }
            cnt++;
            if(cnt > 100) {
                printf("-1\n");
                break;
            }
        }
    }
    return 0;
}
