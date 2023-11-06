#include <cstdio>
#include <vector>
int n, arr[55];
bool used[55];
std::vector<std::pair<int, int>> pairs;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (true) {
        int maxVal = -987654321, maxI, maxJ;
        for(int i = 0; i < n; i++) {
            if(used[i]) continue;
            for(int j = i + 1; j < n; j++) {
                if(used[j]) continue;
                int tmp = arr[i]*arr[j] - (arr[i] + arr[j]);
                if(tmp > maxVal) {
                    maxVal = tmp;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        if(maxVal <= 0) break;
        used[maxI] = used[maxJ] = true;
        pairs.push_back(std::make_pair(maxI, maxJ));
    }

    int ans = 0;
    for(int i = 0; i < pairs.size(); i++) {
        ans += arr[pairs[i].first]*arr[pairs[i].second];
    }
    for(int i = 0; i < n; i++) if(!used[i]) ans += arr[i];
    printf("%d", ans);
}
/*
Idea
그냥 그리디하게 묶으려 했는데.. 그냥 완탐 돌리는것도 괜찮을 듯.
그리디하게 묶는게 맞나?? 자신이 없다..
*/