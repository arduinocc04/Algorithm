/*
include <cstdio>

int k, n;
int digit[500'010];
int cnt[15];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf(" %c", &digit[i]);
        digit[i] -= '0';
        cnt[digit[i]]++;
    }
    int lastDigit, lastDigitCnt, tmp = 0;
    for(int i = 0; i < 10; i++) {
        tmp += cnt[i];
        if(tmp > k) {
            lastDigit = i;
            lastDigitCnt = k - (tmp - cnt[i]);
            break;
        }
    }
    int lastDigitSkippedCnt = 0;
    for(int i = 0; i < n; i++) {
        if(digit[i] < lastDigit) {
            continue;
        }
        else if(digit[i] == lastDigit) {
            if(lastDigitCnt <= lastDigitSkippedCnt) {
                printf("%d", digit[i]);
            }
            else {
                lastDigitSkippedCnt++;
            }
        }
        else {
            printf("%d", digit[i]);
        }
    }
    return 0;
}
*/

/*
First idea..
   44    
  3  3  3
  ----cut-----
 2    22 
1        
수를 사인 곡선처럼 보고, 적당한 부분에서 잘라버린다면 문제를 해결할 수 있을 것이라 생각했음.
반례
10 4
4177252841
       8  
  77      
          
     5    
4       4 
          
    2 2   
 1       1
solution: 775841
mine: 477584
*/
#include <cstdio>
#include <algorithm>
#include <vector>


int n, k, tmp, digits[500'010];
std::vector<int> nums[11];
int history[500'010];
bool next(int prev, int left) {
    if(left == 0) return true;
    if(n - (prev + 1) < left) {
        return false;
    }
    if(n - (prev + 1) == left) {
        for(int i = prev + 1; i < n; i++) history[n - k - left + (i - prev - 1)] = i;
        return true;
    }
    else {
        for(int i = 9; i >= 0; i--) {
            auto tmp = std::upper_bound(nums[i].begin(), nums[i].end(), prev);
            if(tmp == nums[i].end()) continue;
            history[n - k - left] = *tmp;
            if(next(*tmp, left - 1)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf(" %c", &tmp);
        tmp -= '0';
        nums[tmp].push_back(i);
        digits[i] = tmp;
    }
    next(-1, n - k);
    for(int i = 0; i < n - k; i++) {
        printf("%d", digits[history[i]]);
    }
}
/*
Idea
어차피 자리수는 정해져있으므로, 큰 놈을 최대한 왼쪽으로 붙여야 한다.
감소하는 수열로 최대한 채우고, 더이상 원소가 남아있지 않으면 어쩔수 없이 남은 것들로 오른쪽을 채운다.
*/