#include <cstdio>
#include <deque>

int main() {
    int n, tmp;
    scanf("%d", &n);
    std::deque<int> cards;
    for(int i = 0; i < n; i++) {
        cards.push_back(i+1);
    }
    while(cards.size() != 1) {
        cards.pop_front();
        tmp = cards.front();
        cards.pop_front();
        cards.push_back(tmp);
    }
    printf("%d", cards.back());
    return 0;
}