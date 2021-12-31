#include <cstdio>
#include <vector>
#include <algorithm>

int n, m, tmp;
bool flag;
std::vector<int> nums;

void calc(int prev, std::vector<int> things) {
    things.push_back(prev);
    if(things.size() == m) {
        for(int i = 0; i < m; i++) printf("%d ", nums[things[i]]);
        printf("\n");
        return;
    }
    for(int i = prev; i < nums.size(); i++) calc(i, things);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        flag = true; 
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == tmp) flag = false;
        }
        if(flag) nums.push_back(tmp);
    }
    std::sort(nums.begin(), nums.end());
    std::vector<int> ans;
    for(int i = 0; i < nums.size(); i++) calc(i, ans);
}