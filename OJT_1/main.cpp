#include <iostream>
#include <stdio.h>
#include <string.h>

// ��ũ�� ��� ���� ��ġ�� ������ ���ڿ� ���� �䱸������ ����/���� ����
#define MAX_STRING_LENGTH 20


// ���ڿ��� �ٸ� ���۷� �����ϴ� �Լ�
void my_strcpy(char* dest, const char *src) {
    // �Է� ���ڿ�(src)�� �� ���ڸ� �ٸ� ����(dest)�� ����
    while (*src != '\0') {
		*(dest++) = *(src++);
    }
    // ���簡 ������ �� ���� ���ڸ� �߰��Ͽ� ���ڿ��� ����
	*(dest) = '\0';
}

// ���ڿ��� ���̸� ����ϴ� �Լ�
int my_strlen(char *src) {

    int length = 0;
    // ���� ���ڸ� ���� ������ ���� ���� ��� ��ȯ
    while (*src) {
        src++;
        length++;
    }

    return length;
}

// ���ڿ��� ������ �Լ�
void my_strrev(char *src) {

    char *left = src;
    // ���ڿ��� ���� ���� ���ڸ� ������ ������ ���� ã��
    char *right = src + my_strlen(src) - 1;
    char temp;
    // ���ڿ��� ���ʿ��� ���������� ����
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

// ���ڿ��� ��ȯ�Ͽ� ����ϴ� �Լ�
void trans_str(const char* src) {

    std::string str(src);
    std::cout << "String ��ȯ : " << str << std::endl;

    std::string reversed_str;

    // ���ڿ��� �Ųٷ� ���ٿ��� ���� ���ڿ� ����
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed_str += str[i];
    }

    std::cout << "String ������ : " << reversed_str << std::endl;
}

int main() {

    char input_string[MAX_STRING_LENGTH+1];
    char copy_string[MAX_STRING_LENGTH+1];

    // ����ڷκ��� ���ڿ� �Է� �ޱ�
    std::cout << "���ڿ��� �Է��ϼ���." << std::endl;
    std::cin >> input_string;

    // ���ڿ� ���̰� �ִ� ���̸� �ʰ��ϴ��� Ȯ��
    if (my_strlen(input_string) > MAX_STRING_LENGTH) {
        std::cout << "\n������ �ʰ��߾��." << std::endl;

        return 0;

    } else {
    // ���ڿ� ����
    my_strcpy(copy_string, input_string);
    printf("\nchar �迭 ���� : %s\n", copy_string);

    // ���ڿ� ������
    my_strrev(input_string);
    printf("char �迭 ������: %s\n\n", input_string);

    // ���ڿ� ��ȯ �� ���
    trans_str(copy_string);

    return 0;
    }
}
