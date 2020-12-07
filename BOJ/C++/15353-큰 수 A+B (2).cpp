#include <iostream>
#include <string>

int main() {
    std::string num1, num2, result;
    std::cin >> num1 >> num2;
    bool up = false;
    int maxLen, a, b;
    char c;
    if(num1.length() > num2.length()) {
        maxLen = num1.length();
    }
    else {
        maxLen = num2.length();
    }
    for(int i = 0; i < maxLen; i++){
        if(i < num1.length()) {
            a = num1[num1.length() - i - 1] - 48;
        }
        else {
            a = 0;
        }
        if(i < num2.length()) {
            b = num2[num2.length() - i - 1] - 48;
        }
        else {
            b = 0;
        }
        //std::cout << i + 1<< ": "<< a <<' ' << b << ' ' << up <<std::endl;
        if((a+b+up)>9) {
            result.push_back((a+b+up)%10+48);
            up = true;
        }
        else {
            result.push_back(a+b+up+48);
            up = false;
        }

    }
    if(up) {
        result.push_back('1');
    }
    for(int i = 0; i < result.length()/2; i++) {
        c = result[i];
        result[i] = result[result.length() - i - 1];
        result[result.length() - i -1] = c;
    }
    std::cout << result;
    return 0;
}