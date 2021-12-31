#include <cstdio>
int T, n, q, a[200010], segtree[800010], q1, q2, tmp;

int getGcd(int a, int b) {
    if(b == 0) return a;
    if(a == 0) return b;
    int r = a % b;
    if(r) return getGcd(b, r);
    return b;
}

int init(int node, int start, int end) {
    if(start == end) return segtree[node] = a[start];
    return segtree[node] = getGcd(init(node * 2, start, (start + end)/2), init(node*2 + 1, (start + end)/2 + 1, end));
}

int get(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];
    return getGcd(get(node*2, start, (start + end)/2, left, right), get(node*2 + 1, (start + end)/2 + 1, end, left, right));
}

void update(int node, int start, int end, int index, int val) {
    if(index < start || index > end) return;
    if(start == end) segtree[node] = val;
    else {
        if(index == start) segtree[node] = getGcd(val, get(1, 0, n-1, start+1, end));
        else if(index == end) segtree[node] = getGcd(val, get(1, 0, n-1, 0, end-1));
        else {
            tmp = getGcd(val, get(1, 0, n-1, start, index-1));
            segtree[node] = getGcd(tmp, get(1, 0, n-1, index+1, end));
        }
        update(node*2, start, (start + end)/2, index, val);
        update(node*2+1, (start + end)/2+1, end, index, val);
    }
}


int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    init(1, 0, n-1);
    while(q--) {
        scanf("%d %d", &q1, &q2);
        update(1, 0, n-1, q1-1, q2);
        printf("%d\n", get(1, 0, n-1, 0, n-1));
    }
    return 0;
}
