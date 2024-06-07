#include <iostream>

int main()
{
    char OP;
     float firstNumber = 0, secondNumber = 0;
    float result;
    std::cout << "Enter two numbers!\n";
    std::cin >> firstNumber >> secondNumber;
    std::cout << "Enter Operation! Choose between +,-,x,/.\n";
    std::cin >> OP;
    if (OP == '+') {
        result= firstNumber + secondNumber;
    }else if (OP == '-') {
        result = firstNumber - secondNumber;
    }
    else if (OP == 'x') {
        result = firstNumber * secondNumber;
    }
    else if(OP == '/') {
        result = firstNumber / secondNumber;
    }
    std::cout << firstNumber << " " << OP << " " << secondNumber << " = " << result;
}

