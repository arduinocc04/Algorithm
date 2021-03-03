#include <cstdio>

int T, n, a[110], cnt[110];
struct tree {
    tree *left = nullptr;
    tree *right = nullptr;
};
tree* mian;
tree* make(int l, int r, int depth=0) {
    if(l+1 == r) {
        cnt[a[l]] = depth;
        return nullptr;
    }
    int maxIn = l;
    for(int i = l; i < r; i++) {
        if(a[i] > a[maxIn]) maxIn = i;
    }
    cnt[a[maxIn]] = depth;
    if(maxIn == l) {
        make(l+1, r, depth+1);
    }
    else if(maxIn == r-1) {
        make(l, maxIn, depth+1);
    }
    else {
        make(l, maxIn, depth+1);
        make(maxIn+1, r, depth+1);
    }
    /*
    tree* left;
    tree* right;
    left = make(l, maxIn, depth+1);
    right = make(maxIn-1, r, depth+1);
    */
    /*
    tree* root;
    root->left = left;
    root->right = right;
    */
    //return root;
    return nullptr;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        mian = make(0, n);
        for(int i = 0; i < n; i++) {
            printf("%d ", cnt[a[i]]);
        }
        printf("\n");
    }
    return 0;
}
