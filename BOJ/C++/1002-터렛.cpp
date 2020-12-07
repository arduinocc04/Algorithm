#include <iostream>
#include <cmath>

int main()
{
    int loopNum, x1, x2, y1, y2, r1, r2;
    double circleDistance;
    std::cin >> loopNum;
    for(int i = 0; i < loopNum; i++)
    {
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        circleDistance = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
        if(x1 == x2 && y1 == y2 && r1 == r2) 
        {
            std::cout << "-1\n";
        }
        else if(circleDistance < abs(r1 - r2) || circleDistance > r1 + r2)
        {
            std::cout << "0\n";
        }
        else if(circleDistance == abs(r1 - r2) || circleDistance == r1 + r2)
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "2\n";
        }
    }
    return 0;
}