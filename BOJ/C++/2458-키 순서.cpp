#include <iostream>
#include <vector>

#define MAX_STUDENT_CNT 510
#define MAX_RELATIONS_CNT 124'760

std::vector<int> in_graph[MAX_STUDENT_CNT];
std::vector<int> out_graph[MAX_STUDENT_CNT];
std::vector<bool> visited(MAX_STUDENT_CNT);

int dfs(const std::vector<int> * graph, int now, int cnt);
void init_visited();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int student_cnt, relation_cnt;
    std::cin >> student_cnt >> relation_cnt;

    int student_u, student_v;
    for(int i = 0; i < relation_cnt; ++i) {
        std::cin >> student_u >> student_v;
        in_graph[student_u].push_back(student_v);
        out_graph[student_v].push_back(student_u);
    }

    int knowing_height_rank_cnt = 0;
    for(int student = 1; student <= student_cnt; ++student) {
        init_visited();
        const int smaller_cnt = dfs(out_graph, student, 0);

        init_visited();
        const int bigger_cnt = dfs(in_graph, student, 0);

        if(smaller_cnt + bigger_cnt == student_cnt - 1)
            ++knowing_height_rank_cnt;
    }

    std::cout << knowing_height_rank_cnt;
}

int dfs(const std::vector<int> * graph, int now, int cnt) {
    visited[now] = true;

    if(graph[now].size() == 0)
        return cnt;

    int s = 0;
    for(int i = 0; i < graph[now].size(); ++i) {
        if(!visited[graph[now][i]])
            s += dfs(graph, graph[now][i], 1);
    }
    return cnt + s;
}

void init_visited() {
    for(int i = 0; i < MAX_STUDENT_CNT; ++i)
        visited[i] = false;
}
