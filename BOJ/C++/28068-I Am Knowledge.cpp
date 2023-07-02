#include <cstdio>
#include <algorithm>
#include <vector>
int n, a[100'010], b[100'010];
std::vector<std::pair<long long, long long>> tmp;
long long _s;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            _s += b[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == 0 || b[i] - a[i] < 0) continue;
        tmp.push_back(std::make_pair(a[i], -(b[i] - a[i])));
    }
    std::sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); i++) {
        if(_s >= tmp[i].first) {
            _s -= tmp[i].second;
        }
        else {
            printf("0");
            return 0;
        }
    }
    tmp.clear();
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) continue;
        if(b[i] - a[i] >= 0) continue;
        tmp.push_back(std::make_pair(-(b[i] - a[i]), -(b[i] - a[i])));
    }
    for(int i = 0; i < tmp.size(); i++) {
        if(_s >= tmp[i].first) {
            _s -= tmp[i].second;
        }
        else {
            printf("0");
            return 0;
        }
    }
    printf("1");
}