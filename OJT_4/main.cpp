#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Operator {
private:
    int num1;
    int num2;
    double result;

protected:
    void setResult(double result) { this->result = result; }
    int getNum1() { return num1; }
    int getNum2() { return num2; }
    virtual void calculate() = 0;

public:
    void setNumber(int num1, int num2) { this->num1 = num1; this->num2 = num2; }
    double getResult() { calculate(); return result; }
};

class Add : public Operator {
    // write
    virtual void calculate() {
        setResult(getNum1() + getNum2());
    }
};

class Subtract : public Operator {
    // write
    virtual void calculate() {
        setResult(getNum1() - getNum2());
    }
};

class Multiply : public Operator {
    // write
    virtual void calculate() {
        setResult(getNum1() * getNum2());
    }
};

class Divide : public Operator {
    // write
    virtual void calculate() {
        setResult(static_cast<double>(getNum1()) / getNum2());
    }
};

// 연산자가 +, -, *, /인지 판단하는 함수
bool check_sign(char sign) {
    // 입력된 연산자가 +, -, *, /인 경우 true를 반환
    return (sign == '+' || sign == '-' || sign == '*' || sign == '/');
}

// 잘못된 연산자를 입력하면 true를 반환하는 함수
bool forbid_sign(const string& str) {
    string forbid_sign[] = {"++", "**", "//", "-+", "*+", "/+"};
    // 범위 기반 for 루프로 배열의 모든 요소를 출력
    for (const string& pattern : forbid_sign) {
        if (str.find(pattern) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    Add a;
    Subtract s;
    Multiply m;
    Divide d;

    string input_exp;
    int num1, num2;
    char sign;

    while (1) {
        cout << "수식을 입력하세요. (break 입력 시 종료)" << endl;
        getline(cin, input_exp);

        // write

        // break 입력 시 종료
        if (input_exp == "break") {
            break;
        }

        // #1 예외 처리 : 첫번째와 마지막 연산자에 '+'가 입력된 경우
        if (input_exp[input_exp.length() - 1] == '+' || input_exp[0] == '+') {
            cerr << "오류: 올바르게 입력했는지 확인하세요.\n";
            cout << "===============================" << '\n' << '\n';
            continue;
        }

        // #2 예외 처리 : 연산자를 잘못 사용해서 쓴 경우
        if (forbid_sign(input_exp)) {
            cerr << "오류: 잘못된 연산자를 사용했습니다. 올바르게 입력하세요." << endl;
            cout << "===============================" << '\n' << '\n';
            continue;
        }

        istringstream iss(input_exp);

        if (iss >> num1 >> sign >> num2) {

            // #3 예외 처리 : '+, -, *, /'를 제외한 연산자가 입력된 경우
            if (!check_sign(sign) || iss.rdbuf() -> in_avail() > 0) {
                cerr << "오류: 올바른 연산자를 입력했는지 확인하세요.\n";
                cout << "===============================" << '\n' << '\n';
                continue;
            }

            // #4 예외 처리 : 0으로 나누는 경우
            if (sign == '/' && num2 == 0) {
                cerr << "오류: 0으로 나눌 수 없습니다.\n";
                cout << "===============================" << '\n' << '\n';
                continue;
            }

            Operator* op; // Operator 클래스의 포인터 변수 op를 선언

            // 입력된 연산자에 따라 해당하는 Operator 객체를 선택
            switch (sign) {
                case '+':
                    op = &a;
                    break;
                case '-':
                    op = &s;
                    break;
                case '*':
                    op = &m;
                    break;
                case '/':
                    op = &d;
                    break;
            }
            // 선택된 Operator 객체에 피연산자를 설정
            op -> setNumber(num1, num2);
            double result = op -> getResult();

            cout << "[ 결과 ] : " << result << endl;
        // 입력이 올바르지 않은 경우 오류 메시지 출력
        } else {
            cerr << "오류: 유효하지 않은 입력 형식입니다." << endl;
            cout << "===============================" << '\n' << '\n';
        }
    }
    return 0;
}
