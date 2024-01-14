#include <cstdio>
#include <vector>

bool calced[110][110];
int s[110];

using Mat = std::vector<std::vector<bool>>;

Mat matmul(Mat a, Mat b) {
    Mat ans(a.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i].resize(b[0].size());
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            ans[i][j] = false;
            for(int k = 0; k < a[0].size(); k++) {
                if(a[i][k] && b[k][j]) {
                    ans[i][j] = true;
                    break;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    Mat initial(n);
    for(int i = 0; i < n; i++)
        initial[i].resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            initial[i][j] = (i == j);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        --a;
        --b;
        initial[a][b] = true;
        initial[b][a] = true;
    }
    auto x = initial;
    int it = 1;
    while(true) {
        bool flag = true;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(calced[i][j]) continue;
                //printf("%d %d\n", i, j);
                flag = false;
                if(x[i][j] == 0) continue;
                s[i] += it;
                s[j] += it;
                calced[i][j] = true;
            }
        }
        if(flag) break;
        x = matmul(x, initial);
        it++;
    }
    int minIdx = 0;
    for(int i = 0; i < n; i++)
        if(s[minIdx] > s[i])
            minIdx = i;
    printf("%d", minIdx + 1);
}
