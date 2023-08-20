#include <cstdio>

int n, m, a[200'010], b[200'010];

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

bool calc(int target) {
    int sCnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= target) sCnt++;
    }
    int cCnt = 0;
    for(int i = 0; i < m; i++) {
        if(b[i] >= target) cCnt++;
    }

    return sCnt >= cCnt;
}

int lower_bound(int len) {
	int low = 0;
	int high = len; // 주의사항: len - 1로 하면 안 됨
    while (low < high) {
		int mid = (low + high) / 2;
        if (calc(mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);


    printf("%d", lower_bound(1'000'000'001));
}
