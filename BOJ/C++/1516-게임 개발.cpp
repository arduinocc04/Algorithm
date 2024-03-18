#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define MAX_BUILDING_CNT 510
#define INF 987654321

std::vector<int> building_order_graph[MAX_BUILDING_CNT];
std::vector<int> reversed_building_order_graph[MAX_BUILDING_CNT];
int build_time[MAX_BUILDING_CNT];
int constructing_time[MAX_BUILDING_CNT];
int cnt[MAX_BUILDING_CNT];

std::vector<bool> visited(MAX_BUILDING_CNT);

int calc(int now) {
    int max_time = 0;
    for(int i = 0; i < reversed_building_order_graph[now].size(); ++i) {
        if(visited[reversed_building_order_graph[now][i]])
            max_time = std::max(max_time, constructing_time[reversed_building_order_graph[now][i]]);
        else
            max_time = std::max(max_time, calc(reversed_building_order_graph[now][i]));
    }

    visited[now] = true;
    return constructing_time[now] = std::min(max_time + build_time[now], constructing_time[now]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int building_cnt;
    std::cin >> building_cnt;

    int v;
    for(int u = 1; u <= building_cnt; ++u) {
        std::cin >> build_time[u];
        do {
            std::cin >> v;
            if(v == -1)
                break;
            building_order_graph[v].push_back(u);
            reversed_building_order_graph[u].push_back(v);
        } while(true);
    }

    for(int u = 1; u <= building_cnt; ++u) {
        for(int i = 0; i < MAX_BUILDING_CNT; ++i) {
            constructing_time[i] = INF;
            visited[i] = false;
        }

        std::cout << calc(u) << "\n";
    }

    return 0;
}
