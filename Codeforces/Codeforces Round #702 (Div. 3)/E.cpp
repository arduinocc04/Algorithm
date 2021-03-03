#include <cstdio>
#include <algorithm>
#include <vector>

int T, n, l, r, mid, prev;
std::pair<int, int> a[200010];
unsigned long long sums[200010];
std::vector<int> ans;

bool calc(int num) {
    while(num < n-1) {
        if(sums[num] >= a[num+1].first) num++;
        else return false;
    }
    return true;
}
//T(n+nlogn+n+nlogn+n+nlogn)
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i+1;
        }
        std::sort(a, a+n);
        sums[0] = a[0].first;
        for(int i = 1; i < n; i++) {
            sums[i] = sums[i-1] + a[i].first;
        }
        l = 0, r = n;
        while(l < r) {
            mid = (l + r)/2;
            if(calc(mid)) r = mid;
            else l = mid+1;
        }
        mid = r;
        prev = mid;
        while(a[prev].first == a[mid-1].first && mid -1 >= 0) mid--;
        ans.clear();
        for(int i = mid; i < n; i++) {
            ans.push_back(a[i].second);
        }
        std::sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for(auto i:ans) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
