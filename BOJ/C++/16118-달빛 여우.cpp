#include <cstdio>
#include <vector>
#include <queue>

#define INF 2e10 + 2

int n, m, a, b, d;
std::vector<std::pair<int, int>> graph[4'010];
long long distFox[4'010], distWolf[4'010];
std::priority_queue<std::pair<long long, int>> pq;
std::priority_queue<std::pair<long long, std::pair<int, bool>>> pq2;
long long visited[4'010][2];

inline long long min(long long a, long long b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf("%d %d", &n, &m);
    int i, j;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back(std::make_pair(b, 2*d));
        graph[b].push_back(std::make_pair(a, 2*d));
    }
    for(i = 0; i < 4'010; i++) {
        distFox[i] = distWolf[i] = visited[i][0] = visited[i][1] = INF;
    }

    pq.push(std::make_pair(0, 1));
    distFox[1] = 0;

    for(j = 0; j < n; j++) {
        long long cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        for(i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int nextCost = graph[here][i].second;

            if(distFox[next] > distFox[here] + nextCost) {
                distFox[next] = distFox[here] + nextCost;
                pq.push(std::make_pair(-distFox[next], next));
            }
        }
    }

    pq2.push(std::make_pair(0, std::make_pair(1, false)));
    visited[1][1] = false;

    for(j = 0; j < 10*n; j++) {
        long long cost = -pq2.top().first;
        int here = pq2.top().second.first;
        int depth = pq2.top().second.second;
        pq2.pop();
    
        for(i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int nextCost = graph[here][i].second;
            if(depth) {
                nextCost <<= 1;
            }
            else {
                nextCost >>= 1;
            }
            if(visited[next][depth] > cost + nextCost) {
                visited[next][depth] = cost + nextCost;
                pq2.push(std::make_pair(-visited[next][depth], std::make_pair(next, !depth)));
            }
        }
    }

    int res = 0;
    for(i = 1; i <= n; i++) {
        if(min(visited[i][0], visited[i][1]) > distFox[i]) {
            res++;
        }
    }
    printf("%d", res);
}