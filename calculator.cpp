// Copyright (c) 2022 Kent Gatera All rights reserved.
// .
// Created by: Kent Gatera
// Date: Nov 28, 2022
// Does basic math operations using operation signs and user input.

#include <iostream>

float calcNum(char sign, float num1, float num2) {
    // Defining local variables
    float sumNum;
    float diffNum;
    float prodNum;
    float quotNum;
    float modNum;
    // using a switch case to separate all the equations.
    switch (sign) {
        case '+':
            sumNum = num1 + num2;
            return sumNum;
        case '-' :
            diffNum = num1 - num2;
            return diffNum;
        case '/':
            prodNum = num1 / num2;
            return prodNum;
        case '*':
            quotNum = num1 * num2;
            return quotNum;
        case '%':
            modNum = num1 % num2;
            return modNum;
    }
}

int main() {
    // Defining variables.
    char operSign;
    float userNum1;
    float userNum2;
    float ansNum;

    // Telling the type of operation we can do.
    std::cout << "Pick an operation sign (+, -, * , %, /): ";
    std::cin >> operSign;

    // Error checking...
    if (operSign == '-' || operSign == '+' ||
        operSign == '/' || operSign == '*' || operSign == '%') {
        try {
            std::cout << "What is the first number?: ";
            std::cin >> userNum1;
            std::cout << "What is the second number?: ";
            std::cin >> userNum2;
        } catch (std::invalid_argument) {
            std::cout << "Enter valid numbers.";
        }

        // Output of every case/ operation.

        // Calling the calcNum function.
        ansNum = calcNum(operSign, userNum1, userNum2);
        if (operSign == '+') {
            std::cout << userNum1 << " + " << userNum2 << " = " << ansNum;
        } else if (operSign == '-') {
            std::cout << userNum1 << " - " << userNum2 << " = " << ansNum;
        } else if (operSign == '/') {
            std::cout << userNum1 << " / " << userNum2 << " = " << ansNum;
        } else if (operSign == '*') {
            std::cout << userNum1 << " * " << userNum2 << " = " << ansNum;
        } else if (operSign == '%') {
            std::cout << userNum1 << " % " << userNum2 << " = " << ansNum;
        // Error checking for the operation sign.
        } else {
            std::cout << "Invalid operation sign.";
        }
    }
}
