#include <cstdio>
#include <vector>
#include <algorithm>

int n, m, tmp;
bool flag;
std::vector<int> nums;
std::vector<int> delnums;

void calc(int prev, std::vector<int> things, std::vector<int> nums) {
    things.push_back(nums[prev]);
    nums.erase(nums.begin() + prev);
    if(things.size() == m) {
        for(int i = 0; i < m; i++) printf("%d ", things[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        calc(i, things, nums);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        flag = true; 
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == tmp) flag = false;
        }
        nums.push_back(tmp);
        if(flag) delnums.push_back(tmp);
    }
    std::sort(nums.begin(), nums.end());
    std::vector<int> ans;
    for(int i = 0; i < nums.size(); i++) calc(i, ans, nums);
}