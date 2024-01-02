#include <cstdio>
#include <algorithm>
int n, m, votes[200'010], vote, seg[800'010];

int get() {
    return seg[1];
}

void update(int st, int end, int node, int t) {
    if(st <= t && t <= end) {
        if(votes[seg[node]] < votes[t]) {
            seg[node] = t;
        }
        else if(votes[seg[node]] == votes[t]) {
            if(t < seg[node]) seg[node] = t;
        }
        if(st == end) return;
        int mid = (st + end)/2;
        update(st, mid, node*2, t);
        update(mid + 1, end, node*2 + 1, t);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &vote);
        votes[vote]++;
        update(1, n, 1, vote);
        printf("%d\n", get());
    }
}
