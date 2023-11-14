#include "calculator.h"
#include <iostream>
#include <string>
#include <climits>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

Calculator::Calculator(){}
Calculator::~Calculator(){}

double Calculator::calculate()
{
    string input_exp = input_string.toString().toStdString();
    int num1, num2;
    char sign;

    // #1 예외 처리 : 첫번째와 마지막 입력값에 '+'가 입력된 경우
    if (input_exp[input_exp.length() - 1] == '+' || input_exp[0] == '+') {
        return getError();
    }

    // #2 예외 처리 : 잘못된 연산자들을 사용한 경우
    vector<string> forbid_sign = {"++", "**", "//", "-+", "*+", "/+"};

    for (const string& pattern : forbid_sign) {
        if (input_exp.find(pattern) != string::npos) {
            return getError();
        }
    }

    istringstream iss(input_exp);

    if (iss >> num1 >> sign >> num2) {
        // #3 예외 처리 : '+, -, *, /'를 제외한 연산자가 입력된 경우
        if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
            return getError();
        }

        // #4 예외 처리 : 0으로 나누는 경우
        if (sign == '/' && num2 == 0) {
            return getError();
        }

        // #5 예외 처리 : 문자열을 처리했을때 남은 문자열이 남아있는 경우
        if (iss.rdbuf() -> in_avail() > 0) {
            return getError();
        }

        setNumber(num1, num2);

        switch (sign) {
            case '+' :
                add();
                break;
            case '-' :
                subtract();
                break;
            case '*' :
                multiply();
                break;
            case '/' :
                divide();
                break;
        }
        return getResult();

    // #6 예외 처리 : 입력값이 정수값을 초과할 경우
    } else if (num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN) {
        return getError();

    // #7 예외 처리 : 입력이 올바르지 않는 경우
    } else {
        return getError();
    }
}

void Calculator::add() {
    setResult((double)getNum1() + getNum2());;
}

void Calculator::subtract() {
    setResult((double)getNum1() - getNum2());;
}

void Calculator::multiply() {
    setResult((double)getNum1() * getNum2());;
}

void Calculator::divide() {
    setResult((double)getNum1() / getNum2());;
}
