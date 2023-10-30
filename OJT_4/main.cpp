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

// �����ڰ� +, -, *, /���� �Ǵ��ϴ� �Լ�
bool check_sign(char sign) {
    // �Էµ� �����ڰ� +, -, *, /�� ��� true�� ��ȯ
    return (sign == '+' || sign == '-' || sign == '*' || sign == '/');
}

// �߸��� �����ڸ� �Է��ϸ� true�� ��ȯ�ϴ� �Լ�
bool forbid_sign(const string& str) {
    string forbid_sign[] = {"++", "**", "//", "-+", "*+", "/+"};
    // ���� ��� for ������ �迭�� ��� ��Ҹ� ���
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

        // #2 ���� ó�� : �����ڸ� �߸� ����ؼ� �� ���
        if (forbid_sign(input_exp)) {
            cerr << "����: �߸��� �����ڸ� ����߽��ϴ�. �ùٸ��� �Է��ϼ���." << endl;
            cout << "===============================" << '\n' << '\n';
            continue;
        }

        istringstream iss(input_exp);

        if (iss >> num1 >> sign >> num2) {

            // #3 ���� ó�� : '+, -, *, /'�� ������ �����ڰ� �Էµ� ���
            if (!check_sign(sign) || iss.rdbuf() -> in_avail() > 0) {
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

            cout << "[ ��� ] : " << result << endl;
        // �Է��� �ùٸ��� ���� ��� ���� �޽��� ���
        } else {
            cerr << "����: ��ȿ���� ���� �Է� �����Դϴ�." << endl;
            cout << "===============================" << '\n' << '\n';
        }
    }
    return 0;
}
