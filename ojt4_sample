#include <iostream>
#include <string>
#include <sstream>  // stringstream 라이브러리
#include <iomanip>  // fixed 라이브러리
#include <cmath>  // setprecision 라이브러리

using namespace std;

// 부모 클래스
class Operator {
private:
    int num1;
    int num2;
    double result;

protected:
    void setResult(double result) { this->result = result; }
    int getNum1() { return num1; }
    int getNum2() { return num2; }
    virtual void calculate() = 0;  // 순수 가상함수

public:
    void setNumber(int num1, int num2) { this->num1 = num1; this->num2 = num2; }
    double getResult() { calculate(); return result; }
};

// 자식 클래스 : 더하기
class Add : public Operator{
    // write
    virtual void calculate(){
        cout << getNum1() << " + " << getNum2() << " = " << getNum1() + getNum2() << '\n' << '\n';
    }
};

// 자식 클래스 : 빼기
class Subtract : public Operator{
    // write
    virtual void calculate(){
        cout << getNum1() << " - " << getNum2() << " = " << getNum1() - getNum2() << '\n' << '\n';
    }
};

// 자식 클래스 : 곱하기
class Multiply : public Operator{
    // write
    virtual void calculate(){
        cout << getNum1() << " * " << getNum2() << " = " << fixed << setprecision(0) << (double)getNum1() * (double)getNum2() << '\n' << '\n';
    }
};

// 자식 클래스 : 나누기
class Divide : public Operator{
    // write

    virtual void calculate(){
        cout << getNum1() << " / " << getNum2() << " = " << fixed << setprecision(8) << (double)getNum1() / (double)getNum2() << '\n' << '\n';
    }
};

int main()
{
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

        // stringstream : 문자열에서 필요한 정보만 추출
        stringstream stream(input_exp);
        stream >> num1;
        stream >> sign;
        stream >> num2;

        int len = input_exp.length();  // 입력받은 문자열 길이 구하기
        int sign_index = input_exp.find(sign);  // sign 인덱스
        int sign_subtract = input_exp.find('-',sign_index+2);  // 예외 상황 중 '-'제외에 활용할 '-' 인덱스

        // 1. "break" 입력 시, 프로그램 종료
        if(input_exp == "break"){
            break;
        }

        // 2. 입력한 문자열이 길이가 12 이하이면서 연산자는 +,-,*,/ 인지 판단
        if((len > 12) || (sign != '+') && (sign != '-') && (sign != '*') && (sign != '/')){
            cout << '\n' << "올바르게 입력했는지 확인하세요." << '\n';
            cout << "===============================" << '\n' << '\n';
            continue;
        }

        char ch[] = {'+', '*', '/'};  // 입력된 연산자와 비교하기 위한 연산자 배열 선언
        char sign_arr;

        // '-'를 제외한 기호들을 for문을 활용해 하나씩 추출해 3, 4번에 적용
        for(int i = 0; i < 3; i++) {

            sign_arr = ch[i];

            int sign_temp = input_exp.find(sign_arr,sign_index+1);  // num2 이후에 또 sign이 입력되면, 그 sign의 인덱스를 저장
            int first = input_exp.find_first_of(sign_arr,0);  // 입력된 연산자 중 가장 앞 쪽에 놓인 sign의 인덱스
            int last = input_exp.find_last_of(sign_arr,len-1);  // 입력된 연산자 중 가장 뒤 쪽에 놓인 sign의 인덱스

            // 3. 앞에서부터 찾은 연산자 인덱스,뒤에서부터 찾은 연산자 인덱스 비교
            if(first == last){

                // 4. '-'를 맨 앞 혹은 num2 앞에 입력했는지 판단
                if(input_exp.find('-') == 0 || input_exp.find('-') == sign_index+1) {
                    break;
                }
            }
            else{
                cout << '\n' << "계산식을 올바르게 입력했는지 확인하세요." << '\n';
                cout << "========================================" << '\n' << '\n';
                sign = {};  // sign 초기화
                break;

            }

            // 5. 입력 정수가 3개 이상인지 판단
            if(sign_temp != string::npos || sign_subtract != string::npos) {
                cout << '\n' << "서로 다른 연산자를 2개 이상 입력했는지 확인하세요.('-'제외)" << '\n';
                cout << "===========================================================" << '\n' << '\n';
                sign = {};  // sign 초기화
                break;
            }
        }

        switch(sign) {
            case '+':
                cout << '\n' << "[출력]" << '\n';
                a.setNumber(num1, num2);
                a.getResult();
                break;
            case '-':
                cout << '\n' << "[출력]" << '\n';
                s.setNumber(num1, num2);
                s.getResult();
                break;
            case '*':
                cout << '\n' << "[출력]" << '\n';
                m.setNumber(num1, num2);
                m.getResult();
                break;
            case '/':
                if(num1 != 0 && num2 != 0) {
                    cout << '\n' << "[출력]" << '\n';
                    d.setNumber(num1, num2);
                    d.getResult();
                }
                else {
                    cout << '\n' << "분자 혹은 분모에 '0'을 입력했는지 확인하세요." << '\n';
                    cout << "=============================================" << '\n' << '\n';
                }
                break;
            default :
                cout << "다시 시도하세요." << '\n' << '\n';
                break;
        }
        num1, num2 = 0;  // num1, num2 초기화
        sign = {};  // 연산기호 초기화
    }
    return 0;
}
