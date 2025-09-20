#include <iostream>
#include <string>
#include "Stack.h"

int getNumber(char symbol) {
    return symbol - '0';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isNumber(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    int start = 0;
    if (str[0] == '-') {
        if (str.size() == 1) {
            return false;
        }
        start = 1;
    }

    for (int i = start; i < str.size(); ++i) {
        if (!isDigit(str[i])) {
            return false;
        }
    }
    return true;
}

int strToInt(const std::string& str) {
    if (!isNumber(str)) {
        throw std::invalid_argument("Invalid string");
    }

    bool isNegative = (str[0] == '-');
    int start = 0;
    if (isNegative) {
        start = 1;
    }

    int number = 0;
    for (int i = start; i < str.size(); ++i) {
        int digit = getNumber(str[i]);

        if (number > (std::pow(2, sizeof(int) * 8) - 1 - digit) / 10) {
            throw std::out_of_range("Out of int range");
        }

        number = number * 10 + digit;
    }

    if (isNegative) {
        return -number;
    }
    return number;
}

int main() {
    // 1

	/*try {
		std::cout << strToInt("-200000000000000");
	}
	catch (std::invalid_argument ex) {
		std::cout << "String ins`t number";
	}
    catch (std::out_of_range ex) {
        std::cout << "Int limit Error";
    }*/

    // 2

    Stack<int> stack;
    for (int i = 0; i < 10; ++i) {
        stack.addElement(i);
    }
    stack.pop();
    stack.pop();
    stack.pop();
    stack.print();
	return 0;
}