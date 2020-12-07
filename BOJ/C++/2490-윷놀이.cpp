#include <iostream>
int main()
{
    int a, b, c, d, result;
    for(int i = 0; i<3; i++)
    {
        std::cin >> a >> b >> c >> d;
        result = a + b + c + d;
        switch(result)
        {
            case 0:
                std::cout << "D\n";
                break;
            case 1:
                std::cout << "C\n";
                break;
            case 2:
                std::cout << "B\n";
                break;
            case 3:
                std::cout << "A\n";
                break;
            case 4:
                std::cout << "E\n";
                break;
        }
    }
}