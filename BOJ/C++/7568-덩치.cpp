#include <cstdio>
#include <algorithm>

int main() {
    int n, tmp1, tmp2;
    std::pair<int, int> people[60];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        people[i] = std::make_pair(tmp1, tmp2);
    }
    int rank[60], cnt;
    for(int i = 0; i < n; i++) {
        cnt = 1;
        for(int j = 0; j < n; j++) {
            if(people[i].first < people[j].first && people[i].second < people[j].second) {
                cnt++;
            }
        }
        rank[i] = cnt;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", rank[i]);
    }
    return 0;
}