#include <iostream>
#include <vector>

void calc(int i);
std::vector <std::vector<int>> linked;
int visited[100];
void calc(int i) {
    if(!visited[i]) {
        visited[i] = true;
        for(int j = 0; j < linked[i].size(); j++) {
            calc(linked[i][j]-1);
        }
    }
}

int main() {
    int computerCount, connectionCount, com1Num, com2Num;
    std::cin >> computerCount >> connectionCount;
    for(int i = 0; i < computerCount; i++) {
        std::vector<int> a;
        linked.push_back(a);
    }
    for(int i = 0; i < connectionCount; i++) {
        std::cin >> com1Num >> com2Num;
        linked[com1Num-1].push_back(com2Num);
        linked[com2Num-1].push_back(com1Num);
    }

    if(connectionCount) {
        for(int i = 0; i < 100; i++) {
            visited[i] = false;
        }
        calc(0);
        visited[0] = false;
        int count = 0;
        for(int i = 0; i < computerCount; i++) {
            if(visited[i]) {
                count++;
            }
        }
        std::cout << count;
    }
    else {
        std::cout << 0;
    }
    return 0;
}