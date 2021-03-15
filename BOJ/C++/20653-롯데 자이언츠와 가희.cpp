#include <cstdio>
#include <vector>

std::vector<std::pair<int, int>> factor; // factor, count
int n, g, l, T, i, cnt, j, tmp;
const int mod = 1e9 + 7;

int main() {
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &g, &l);
        if(l % g != 0) {
            printf("0\n");
            continue;
        }
        tmp = l/g;
        i = 2;
        while(tmp != 1) {
            cnt = 0;
            while (tmp % i == 0)
            {
                cnt++;
                tmp /= i;
            }
            if(cnt) factor.push_back(std::make_pair(i, cnt));
            i++;
        }
    }
    
}