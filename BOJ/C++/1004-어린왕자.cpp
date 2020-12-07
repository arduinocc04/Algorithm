#include <iostream>
#include <cmath>

int main(){
    int loopNum, startX, startY, endX, endY, planetCount, planetX, planetY, planetRadius, count;
    double distance, distance2;
    std::cin >> loopNum;
    for(int i = 0; i <loopNum; i++)
    {
        std::cin >> startX >> startY >> endX >> endY;
        std::cin >> planetCount;
        count = 0;
        for(int k = 0; k < planetCount; k++)
        {
            std:: cin >> planetX >> planetY >> planetRadius;
            distance = pow((startX - planetX), 2) + pow((startY - planetY), 2);
            distance2 = pow((endX - planetX), 2) + pow((endY - planetY), 2);
            planetRadius = pow(planetRadius, 2);
            count += (planetRadius > distance) ^ (planetRadius > distance2);
        }
        std::cout << count << '\n';
    }
    return 0;
}