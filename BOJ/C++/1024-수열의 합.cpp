#include <cstdio>
#include <utility>
int n, l, lo, hi, mid;

std::pair<int, bool> calc(int n, int l) {
    return std::make_pair((2*n + l - 1)*(l)/2, ((2*n + l -1)%2 && (l) % 2));
}

std::pair<int, bool> tmp;

int main() {
    scanf("%d %d", &n, &l);
    for(int target = l; target <= 100; target++) {
        lo = 0, hi = n;
        while(lo + 1 < hi) {
            mid = (lo + hi)/2;
            tmp = calc(mid, target);
            if(tmp.first >= n) hi = mid;
            else lo = mid;
        }
        if(calc(lo, target).first == n && !calc(lo, target).second) {
            for(int i = 0; i < target; i++) printf("%d ", lo+i);
            return 0;
        }
        else if(calc(hi, target).first == n && !calc(hi, target).second) {
            for(int i = 0; i < target; i++) printf("%d ", hi + i);
            return 0;
        }
    }
    printf("-1\n");
}
