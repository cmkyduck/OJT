#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QVariant>

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double result READ getResult WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(QVariant input_string READ getInput_string WRITE setInput_string NOTIFY input_stringChanged)

private:
    int num1;
    int num2;
    double result;
    double error = 1;
    QVariant input_string;

protected:
    void setResult(double result) { this->result = result; emit resultChanged(); }
    int getNum1() { return num1; }
    int getNum2() { return num2; }

public:
    Calculator();
    ~Calculator();

    void setNumber(int num1, int num2) { this->num1 = num1; this->num2 = num2; }
    double getResult() { return result; }
    double getError() { return error; }

    // qml 에서 text 가져오기 위한 함수
    void setInput_string(QVariant input_string) { this->input_string = input_string; emit input_stringChanged(); }
    QVariant getInput_string() { return input_string; }

    void add();
    void subtract();
    void multiply();
    void divide();
    Q_INVOKABLE double calculate();

    signals:
        void input_stringChanged();
        void resultChanged();
};

#endif // CALCULATOR_H
