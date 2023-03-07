#include <cstdio>
#include <vector>

int n, a[10], max = -1;

int abs(int x) {
    if(x > 0) return x;
    return -x;
}

int calc(std::vector<int> picked) {
    int res = 0;
    for(int i = 0; i < n-1; i++) {
        res += abs(a[picked[i]] - a[picked[i + 1]]);
    }
    return res;
}

void find(std::vector<int> picked) {
    if(picked.size() == n) {
        int res = calc(picked);
        if(res > max) max = res;
    }
    for(int i = 0; i < n; i++) {
        bool used = false;
        for(int j = 0; j < picked.size(); j++) {
            if(picked[j] == i) {
                used = true;
                break;
            }
        }
        if(!used) {
            picked.push_back(i);
            find(picked);
            picked.pop_back();
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::vector<int> tmp;
    find(tmp);
    printf("%d", max);
}