#include <cstdio>
#include <vector>
#include <deque>
int n;
std::vector<std::pair<int, int>> ans;

int move(int from, int to) {
    ans.push_back(std::make_pair(from, to));
    return 0;
}

int mv(int cnt, int from, int to) {
    if(cnt == 1) return move(from, to);
    return mv(cnt - 1, from, 1^2^3^from^to) + mv(1, from, to) + mv(cnt-1, 1^2^3^from^to, to);
}

int main() {
    scanf("%d", &n);
    mv(n, 1, 3);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}