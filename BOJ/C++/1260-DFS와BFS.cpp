#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

bool visited[1000];
int nodeCount, edgeCount, startNum;

std::vector<int> edges[1000];

void dfs(int num, std::vector<int> &result) {
    if(visited[num-1]) {
        return;
    }
    visited[num-1] = true;
    result.push_back(num);
    for(int i = 0; i < edges[num-1].size(); i++) {
        dfs(edges[num-1][i], result);
    }
}

void bfs(int num, std::vector<int> &result) {
    std::queue<int> queue;
    int len, n;
    queue.push(num);
    visited[num-1] = true;
    while(queue.size()) {
        len = queue.size();
        for(int i = 0; i < len; i++) {
            n = queue.front();
            queue.pop();
            result.push_back(n);
            for(int j = 0; j < edges[n-1].size(); j++) {
                if(!visited[edges[n-1][j] - 1]) {
                    queue.push(edges[n-1][j]);
                    visited[edges[n-1][j] - 1] = true;
                }
            }
        }
    }
}

int main() {
    std::cin >> nodeCount >> edgeCount >> startNum;
    int a, b;
    for(int i = 0; i < edgeCount; i++) {
        std::cin >> a >> b;
        edges[a-1].push_back(b);
        edges[b-1].push_back(a);
    }
    for(int i = 0; i < 1000; i++) {
        std::sort(edges[i].begin(), edges[i].end());
    }

    for(int i = 0; i < 1000; i++) {
        visited[i] = false;
    }
    std::vector <int> result;
    dfs(startNum, result);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';

    for(int i = 0; i < 1000; i++) {
        visited[i] = false;
    }
    result.clear();
    bfs(startNum, result);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}