#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

int n, nums[500010];
int main() {
    int tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        nums[i] = tmp;
    }
    std::sort(nums, nums+n);
    long long s = 0;
    for(int i = 0; i < n; i++) {
        s += nums[i];
    }
    double a = round(((double)s)/n);
    printf("%d\n", (int)a);
    printf("%d\n", nums[n/2]);
    int p[8010];
    for(int i = 0; i < 8010; i++) {
        p[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        p[nums[i]+4001]++;
    }
    std::vector <int> res;
    int maxVal = -1;
    for(int i = 0; i < 8010; i++) {
        if(maxVal < p[i]) {
            res.clear();
            res.push_back(i-4001);
            maxVal = p[i];
        }
        else if(maxVal == p[i]) {
            res.push_back(i-4001);
        }
    }
    if(res.size() != 1) {
        std::sort(res.begin(), res.end());
        printf("%d\n", res[1]);
    }
    else printf("%d\n", res[0]);
    printf("%d", nums[n-1] - nums[0]);

    return 0;
}