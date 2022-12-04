// Copyright (c) 2022 Kent Gatera All rights reserved.
// .
// Created by: Kent Gatera
// Date: Nov 28, 2022
// Does basic math operations using operation signs and user input.

#include <iostream>
#include <iomanip>

float calculate(char sign, float num1, float num2) {
    // Defining local variables
    float sumNum;
    float diffNum;
    float prodNum;
    float quotNum;
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
        default:
            return 0;
    }
}

// I made a separate function for modulus since it needs to return int.
int modulusNum(char sign, int num1, int num2) {
    float modNum;
    modNum = num1 % num2;
    return modNum;
}

int main() {
    // Defining variables.
    char operSign;
    float userNum1;
    float userNum2;
    float ansNum;
    std::string userNum1Str;
    std::string userNum2Str;
    int modAns;

    // Telling the type of operation we can do.
    std::cout << "Pick an operation sign (+, -, * , %, /): ";
    std::cin >> operSign;

    // Error checking...
    if (operSign == '-' || operSign == '+' ||
        operSign == '/' || operSign == '*' || operSign == '%') {
        try {
            std::cout << "What is the first number?: ";
            std::cin >> userNum1Str;
            userNum1 = stof(userNum1Str);
            std::cout << "What is the second number?: ";
            std::cin >> userNum2Str;
            userNum2 = stof(userNum2Str);
        } catch (std::invalid_argument) {
            std::cout << "Enter a valid number.\n";
            std::cout << "Restart...\n";
            return main();
        }

        // Output of every case/ operation.

        // Calling the calcNum function.
        ansNum = calculate(operSign, userNum1, userNum2);
        if (operSign == '+') {
            std::cout << userNum1 << " + " << userNum2 << " = " << ansNum;
        } else if (operSign == '-') {
            std::cout << userNum1 << " - " << userNum2 << " = " << ansNum;
        } else if (operSign == '/') {
            std::cout << userNum1 << " / " << userNum2 << " = " << ansNum;
        } else if (operSign == '*') {
            std::cout << userNum1 << " * " << userNum2 << " = " << ansNum;
        } else if (operSign == '%') {
            modAns = modulusNum(operSign, userNum1, userNum2);
            std::cout << userNum1 << " % " << userNum2 << " = " << modAns;
        }
    } else {
            // Error checking for the operation sign.
            std::cout << "Invalid operation sign.";
    }
}
