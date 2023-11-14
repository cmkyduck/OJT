#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>
#include <vector>

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
        setResult(static_cast<double>(getNum1()) + getNum2());
    }
};

class Subtract : public Operator {
    // write
    virtual void calculate() {
        setResult(static_cast<double>(getNum1()) - getNum2());
    }
};

class Multiply : public Operator {
    // write
    virtual void calculate() {
        setResult(static_cast<double>(getNum1()) * static_cast<double>(getNum2()));
    }
};

class Divide : public Operator {
    // write
    virtual void calculate() {
        setResult(static_cast<double>(getNum1()) / getNum2());
    }
};

int main() {
    Add a;
    Subtract s;
    Multiply m;
    Divide d;

    string input_exp;
    int num1, num2;
    char sign;

    while (1) {
        cout << "������ �Է��ϼ���. (break �Է� �� ����)" << endl;
        getline(cin, input_exp);

        // write

        // break �Է� �� ����
        if (input_exp == "break") {
            break;
        }

        // #1 ���� ó�� : ù��°�� ������ �����ڿ� '+'�� �Էµ� ���
        if (input_exp[input_exp.length() - 1] == '+' || input_exp[0] == '+') {
            cerr << "����: �ùٸ��� �Է��ߴ��� Ȯ���ϼ���.\n";
            cout << "===============================" << '\n' << '\n';
            continue;
        }

        vector<string> forbid_sign = {"++", "**", "//", "-+", "*+", "/+"};

        for (const string& pattern : forbid_sign) {
            if (input_exp.find(pattern) != string::npos) {
                cerr << "����: �ùٸ� �����ڸ� �Է��ߴ��� Ȯ���ϼ���.\n";
                cout << "===============================" << '\n' << '\n';
                break;
            }
        }
        // ����ó���� Ȯ�ε����� ������� ������ ������ ����

        istringstream iss(input_exp);

        if (iss >> num1 >> sign >> num2) {

            // #2 ���� ó�� : �����ڸ� �߸� ����ؼ� �� ���
            if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
                cerr << "����: �߸��� �����ڸ� ����߽��ϴ�. �ùٸ��� �Է��ϼ���." << endl;
                cout << "===============================" << '\n' << '\n';
                continue;
            }

            // #3 ���� ó�� : ���ڿ��� ó���������� ���ڰ� �����Ѵٸ� ���� �޽����� ���
            if (iss.rdbuf() -> in_avail() > 0) {
                cerr << "����: �ùٸ� �����ڸ� �Է��ߴ��� Ȯ���ϼ���.\n";
                cout << "===============================" << '\n' << '\n';
                continue;
            }

            // #4 ���� ó�� : 0���� ������ ���
            if (sign == '/' && num2 == 0) {
                cerr << "����: 0���� ���� �� �����ϴ�.\n";
                cout << "===============================" << '\n' << '\n';
                continue;
            }

            Operator* op; // Operator Ŭ������ ������ ���� op�� ����

            // �Էµ� �����ڿ� ���� �ش��ϴ� Operator ��ü�� ����
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
            // ���õ� Operator ��ü�� �ǿ����ڸ� ����
            op -> setNumber(num1, num2);
            double result = op -> getResult();

            if (sign == '/') {
                cout << fixed << setprecision(8) << "[ ��� ] : " << result << endl;
                cout << "===============================" << '\n' << '\n';
                continue;
            }
                cout << fixed << setprecision(0) << "[ ��� ] : " << result << endl;
                cout << "===============================" << '\n' << '\n';
        // #5 ���� ó�� : �Է°��� �������� �ʰ��� ���
        } else if (num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN) {
                cerr << "����: 2147483647 ~ -2147483648 ������ ���� �Է��ϼ���.\n";
                cout << "===============================" << '\n' << '\n';
        // �Է��� �ùٸ��� ���� ��� ���� �޽��� ���
        } else {
            cerr << "����: ��ȿ���� ���� �Է� �����Դϴ�." << endl;
            cout << "===============================" << '\n' << '\n';
        }
    }
    return 0;
}