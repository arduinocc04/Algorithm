#include <cstdio>
#include <algorithm>
#include <vector>
struct line{
    int u;
    int v;
    int d;
};
std::vector<line> graph;
int n, m, u, v, d, cnt, w, p[1010];
char univ[1010];
line tmp;
bool cmp(line a, line b) {
    return a.d < b.d;
}
int find(int n) {
    if (p[n] == n) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 < n2) p[n2] = n1;
    else p[n1] = n2;
    return;
}

bool isInSameSet(int n1, int n2) {
    return find(n1) == find(n2);
}

int main() {
    scanf("%d %d", &n, &m);
    //printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++) {
        scanf(" %c ", &univ[i]);
        //printf("%c", univ[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &d);
        //printf("%d %d %d\n", u, v, d);
        u--, v--;
        if (univ[u] != univ[v]) {
            tmp.u = u;
            tmp.v = v;
            tmp.d = d;
            graph.push_back(tmp);
        }
    }
    //for(int i = 0; i < n; i++) printf("univ[%d]: %c", i,univ[i]);
    std::sort(graph.begin(), graph.end(), cmp);
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < graph.size(); i++) {
        if(!isInSameSet(graph[i].u, graph[i].v)) {
            merge(graph[i].u, graph[i].v);
            w += graph[i].d;
            cnt++;
        }
    }
    if(cnt < n-1) printf("-1\n");
    else printf("%d\n", w);
    return 0;
}