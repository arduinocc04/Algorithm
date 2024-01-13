#include <cstdio>
#include <vector>

int n, q, c, zasdf;
char par;
std::vector<std::pair<int, int>> trajectory;
int main() {
    scanf("%d %d", &n, &q);
    for(int i = n; i > 0; i--) {
        trajectory.push_back(std::make_pair(i, 0));
    }
    while(q--) {
        scanf("%d ", &c);
        if(c == 1) {
            scanf("%c", &par);
            auto last = trajectory[trajectory.size() - 1];
            if(par == 'U') {
                trajectory.push_back(std::make_pair(last.first, last.second + 1));
            }
            else if(par == 'R') {
                trajectory.push_back(std::make_pair(last.first + 1, last.second));
            }
            else if(par == 'L') {
                trajectory.push_back(std::make_pair(last.first - 1, last.second));
            }
            else {
                trajectory.push_back(std::make_pair(last.first, last.second - 1));
            }
        }
        else {
            scanf("%d", &zasdf);
            auto tmp = trajectory[trajectory.size() - zasdf];
            printf("%d %d\n", tmp.first, tmp.second);
        }
    }
    return 0;
}
