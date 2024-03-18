#include <iostream>

#define MAX_USER_CNT 1'000'010

int p[MAX_USER_CNT];

int find(int n) {
    if(p[n] == n)
        return n;
    else
        return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    p[n1] = n2;
}

void solve(int test_case) {
    int user_cnt, relation_cnt, user_a, user_b;
    std::cin >> user_cnt >> relation_cnt;
    for(int i = 0; i <= user_cnt; ++i)
        p[i] = i;

    for(int i = 0; i < relation_cnt; ++i) {
        std::cin >> user_a >> user_b;
        merge(user_a, user_b);
    }

    int query_cnt;
    std::cin >> query_cnt;
    std::cout << "Scenario " << test_case << ":\n";
    for(int i = 0; i < query_cnt; ++i) {
        std::cin >> user_a >> user_b;
        std::cout << static_cast<int>(find(user_a) == find(user_b)) << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int test_case_cnt;
    std::cin >> test_case_cnt;
    for(int i = 1; i <= test_case_cnt; ++i) {
        solve(i);
        std::cout << "\n";
    }
}
