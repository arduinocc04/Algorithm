#include <iostream>

bool find(int x, int y, int *count, int *xVals, int *yVals, int *memo, int k) {
    if(x > 50 || y > 50 || x < 0 || y < 0) {
        return 0;
    }
    for(int i = 0; i < k; i++) {
        if(xVals[i] == x && yVals[i] == y) {
            if(memo[i] == false) {
                *count += 1;
                //std::cout << "WOW" << std::endl;
                memo[i] = true;
                find(x-1,y, count, xVals, yVals, memo, k)+find(x+1,y, count, xVals, yVals, memo, k)+find(x, y-1, count, xVals, yVals, memo, k)+find(x, y+1, count, xVals, yVals, memo, k);
                break;
            }
        }
    }
    return 0;
}

int main() {
    int loopCount, groupCount, count;
    int memo[2550], xVals[2550], yVals[2550];
    int m, n, k, tempX, tempY, l;
    std::cin >> loopCount;
    for(int j = 0; j < loopCount; j++) {
        groupCount = 0;
        count = 0;
        std::cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            std::cin >> tempX >> tempY;
            xVals[i] = tempX;
            yVals[i] = tempY;
            memo[i] = false;
        }

        do{
            for(l = 0; l < k; l++) {
                if(memo[l] == false) {
                    break;
                }
            }
            //std::cout << "l: " << l << std::endl;
            //std::cout << xVals[l] << "|" << yVals[l] << std::endl;
            find(xVals[l], yVals[l], &count, xVals, yVals, memo, k);
            groupCount += 1;
            //std::cout << "groups: " << groupCount << std::endl;
        }while(l != k);
        std::cout << groupCount-1 << std::endl;
    }
    return 0;
}