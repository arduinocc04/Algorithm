#include <iostream>

const int MAX_TREE_SIZE = (1 << 21) + 10;
const int MAX_LEAFS_CNT = (1 << 20) + 10;

int dist_leafs[MAX_LEAFS_CNT];
int tree_height, tree[MAX_TREE_SIZE], delta_tree[MAX_TREE_SIZE];
int delta_dist[MAX_LEAFS_CNT];

void dfs(int node, int dist, int height, int target_height) {
    if(height == target_height) {
        dist_leafs[node - ((1 << target_height) - 1)] = dist + tree[node];
        return;
    }
    dfs(2*node + 1, dist + tree[node], height + 1, target_height);
    dfs(2*(node + 1), dist + tree[node], height + 1, target_height);
}

int divide_conquer(int node, int l, int r) {
    if(l + 1 == r) {
        return delta_tree[node] = delta_dist[l];
    }

    const int mid = (l + r)/2;
    return delta_tree[node] = std::min(divide_conquer(2*node + 1, l, mid),
                                       divide_conquer(2*(node + 1), mid, r));
}

void update(int node, int l, int r, int updated) {
    if(l + 1 == r) {
        tree[node] += delta_tree[node] - updated;
        return;
    }

    const int update_val = delta_tree[node] - updated;
    const int mid = (l + r)/2;
    tree[node] += update_val;
    update(2*node + 1, l, mid, updated + update_val);
    update(2*(node + 1), mid, r, updated + update_val);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> tree_height;
    const int tree_size = (1 << (tree_height + 1)) - 1;
    for(int i = 1; i < tree_size; ++i) {
        std::cin >> tree[i];
    }

    dfs(0, 0, 0, tree_height);
    const int leaf_cnt = (1 << tree_height);
    int max_dist = -1;
    for(int i = 0; i < leaf_cnt; ++i) {
        max_dist = std::max(max_dist, dist_leafs[i]);
    }

    for(int i = 0; i < leaf_cnt; ++i) {
        delta_dist[i] = max_dist - dist_leafs[i];
    }
    divide_conquer(0, 0, leaf_cnt);
    update(0, 0, leaf_cnt, 0);

    unsigned long long s = 0;
    for(int i = 0; i < tree_size; ++i) {
        s += tree[i];
    }
    std::cout << s;
}
