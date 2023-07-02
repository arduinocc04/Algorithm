#include <cstdio>
#include <algorithm>

int n;
std::pair<int, int> v[200'010];
int time;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
        v[i].first *= -1;
    }
    std::sort(v, v + n);
    for(int i = 0; i < n; i++) {
        time += (-v[i].first * time + v[i].second);
        time %= 40000;
    }
    printf("%d", time);
}