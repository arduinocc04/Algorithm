#include <cstdio>
#include <algorithm>

int n, c, houses[200010], lo, hi, mid;
using namespace std;
bool possible(int d) {
    int cnt = 0;
    int last = -123423;
    for(int i = 0; i < n; i++) {
        if(last + d <= houses[i]) {
            cnt++;
            last = houses[i];
        }
    }
    return (cnt >= c);
}

int main() {
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++) scanf("%d", &houses[i]);
    sort(houses, houses+n);
    lo = 1;
    hi = houses[n-1] - houses[0];
    int tmp;
    while(lo <= hi) {
        mid = (lo + hi)/2;
        if(possible(mid)) {
            tmp = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    printf("%d", tmp);
}