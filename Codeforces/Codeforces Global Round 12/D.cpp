#include <cstdio>
int T, n, nums[300010], seg[1200030];
int init(int start, int end, int index) {
    if(start == end) return seg[index] = nums[start];
    int mid = (start + end)/2;
    int minA = init(start, mid, index*2);
    int minB = init(mid+1, end, index*2+1);
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
    }
    return 0;
}
