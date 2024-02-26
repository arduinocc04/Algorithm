#include <cstdio>
#include <vector>

int edge_cnt, vertex_cnt, p[510];
std::vector<bool> is_tree(510);
std::vector<bool> counted(510);

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    p[n2] = n1;
}

bool solve_impl(int tc) {
    scanf("%d %d", &vertex_cnt, &edge_cnt);
    if(vertex_cnt == 0)
        return false;

    for(int i = 1; i <= vertex_cnt; ++i) {
        p[i] = i;
        is_tree[i] = true;
        counted[i] = false;
    }

    int u, v;
    for(int i = 0; i < edge_cnt; ++i) {
        scanf("%d %d", &u, &v);

        const int parent_u = find(u), parent_v = find(v);
        if(parent_u == parent_v) {
            is_tree[parent_u] = false;
            is_tree[parent_v] = false;
        }
        if(!is_tree[parent_u] || !is_tree[parent_v])
            is_tree[parent_u] = is_tree[parent_v] = false;
        merge(u, v);
    }

    for(int i = 1; i <= vertex_cnt; ++i)
        find(i);

    int tree_cnt = 0;
    for(int i = 1; i <= vertex_cnt; ++i) {
        if(is_tree[p[i]] && !counted[p[i]]) ++tree_cnt;
        counted[p[i]] = true;
    }

    printf("Case %d: ", tc);
    switch (tree_cnt) {
    case 0:
        printf("No trees.\n");
        break;
    case 1:
        printf("There is one tree.\n");
        break;
    default:
        printf("A forest of %d trees.\n", tree_cnt);
        break;
    }

    return true;
}

int main() {
    int tc = 1;
    while(solve_impl(tc++));
}