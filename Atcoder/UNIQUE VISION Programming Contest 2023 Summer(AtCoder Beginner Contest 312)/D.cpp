#include <iostream>
#include <string>
#include <vector>

std::string s;
std::vector<int> end1;
std::vector<int> end2;

int p[3'010];
int cnt[] = {0, 0, 0}; // ( ? )
int res = 0;
int l;

void calc(int lLeft, int rLeft, int prevlCnt, int i) {
    if(lLeft == 0) {
        res++;
        res %= 998244353;
        return;
    }
    if(i >= l) return;
    if(s[i] == '(') {
        calc(lLeft - 1, rLeft, prevlCnt + 1, i + 1);
        return;
    }
    else if(s[i] == ')') {
        if(prevlCnt > 0) {
            calc(lLeft, rLeft - 1, prevlCnt - 1, i + 1);
        }
        return;
    }
    if(lLeft > 0) calc(lLeft - 1, rLeft, prevlCnt + 1, i + 1);
    if(rLeft > 0 && prevlCnt > 0) calc(lLeft, rLeft - 1, prevlCnt - 1, i + 1);
}

int main() {
    std::cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') cnt[0]++;
        else if(s[i] == '?') cnt[1]++;
        else cnt[2]++;
        p[i] = cnt[1];
        l++;
    }
    // printf("Hi");

    end1.push_back(-1);
    int cnt1 = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') cnt1++;
        else if((s[i] == '?' || s[i] == ')') && cnt1 > 0) cnt1--;

        if(cnt1 == 0) {
            end1.push_back(i);
        }
    }
    if(cnt1 != 0) {
        printf("0");
        return 0;
    }
    end1.push_back(l - 1);
    // printf("Hi");

    end2.push_back(l);
    cnt1 = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == ')') cnt1++;
        else if((s[i] == '?' || s[i] == '(') && cnt1 > 0) cnt1--;

        if(cnt1 == 0) end2.push_back(i);
    }
    if(cnt1 != 0) {
        printf("0");
        return 0;
    }
    end2.push_back(0);
    // int possibleSet = cnt[1] - cnt[0] - cnt[2];
    // printf("Hi");
    // if(possibleSet % 2){
    //     printf("0");
    //     return 0;
    // }
    // printf("%d\n", possibleSet/2);
    calc(l/2, l/2, 0, 0);
    printf("%d\n", res);

    return 0;
}
