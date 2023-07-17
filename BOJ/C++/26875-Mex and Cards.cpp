#include <cstdio>

int n, cnt[200'010], t, q, p, v, tree[800'080];

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int init(int start, int end, int node) {
    if(start == end) return tree[node] = cnt[start];
    int mid = (start + end)/2;
    return tree[node] = min(init(start, mid, node*2), init(mid + 1, end, node*2 + 1));
}

int sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 987654321;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return min(sum(start, mid, node*2, left, right), sum(mid + 1, end, node*2 + 1, left, right));
}

int update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return 987654321;
    if(start == end) {
        tree[node] += diff;
        return tree[node];
    }
    int mid = (start + end)/2;
    return tree[node] = min(update(start, mid, node*2, index, diff), update(mid + 1, end, node*2 + 1, index, diff));
}

int lowerBound(int start, int x) {
    int s = start, e = n;
    while(s < e) {
        int mid = (s + e)/2;
        if(sum(0, n, 1, start, mid) <= x) e = mid;
        else s = mid + 1;
    }
    return s;
}

long long calc() {
    long long res = 0;
    int std = 1;
    int c = sum(0, n, 1, 0, 0);
    while(c != 0) {
        int idx = lowerBound(std, c);
        // printf("::%d\n", idx);
        int i = sum(0, n, 1, idx, idx);
        res += (c - i)*idx;
        c = i;
        std = idx + 1;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        cnt[i] = t;
    }
    init(0, n, 1);
    scanf("%d", &q);
    printf("%lld\n", calc());
    while(q--) {
        scanf("%d %d", &p, &v);
        if(p == 1) {
            update(0, n, 1, v, 1);
        }
        else {
            update(0, n, 1, v, -1);
        }
        // for(int i = 1; i < 10; i++) {
        //     printf("--%d\n", sum(0, n, 1, 1, i));
        // }
        printf("%lld\n", calc());
    }
}