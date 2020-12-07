#include <iostream>
#include <cmath>
int main()
{
    int loopNum, a, b, c;
    std::cin >> loopNum;
    for(int i = 0; i <loopNum; i++)
    {
        std::cin >> a >> b;
        a %= 10;
        b = b%4 +4;
        c = (int)pow(a, b)%10;
        if(c != 0)
        {
            std::cout << c << '\n';
        }
        else
        {
            std::cout << 10 << '\n';
        }
    }
    return 0;
}