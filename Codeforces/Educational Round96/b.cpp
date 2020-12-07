#include <cstdio>
#include <algorithm>

int main() {
    int t, n, k, nums[200010], tmp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%d", &k);
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            nums[i] = tmp;
        }
        std::sort(nums, nums+n);
        for(int i = 1; i < k+1; i++) {
            nums[n-1] += nums[n-1-i];
        }
        printf("%d\n", nums[n-1]);
    }
    return 0;
}