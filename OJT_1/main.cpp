#include <iostream>
#include <stdio.h>
#include <string.h>

// 매크로 상수 값을 고치는 것으로 문자열 길이 요구사항을 변경/관리 가능
#define MAX_STRING_LENGTH 20


// 문자열을 다른 버퍼로 복사하는 함수
void my_strcpy(char* dest, const char *src) {
    // 입력 문자열(src)의 각 문자를 다른 버퍼(dest)로 복사
    while (*src != '\0') {
		*(dest++) = *(src++);
    }
    // 복사가 끝났을 때 공백 문자를 추가하여 문자열을 종료
	*(dest) = '\0';
}

// 문자열의 길이를 계산하는 함수
int my_strlen(char *src) {

    int length = 0;
    // 공백 문자를 만날 때까지 문자 수를 세어서 반환
    while (*src) {
        src++;
        length++;
    }

    return length;
}

// 문자열을 뒤집는 함수
void my_strrev(char *src) {

    char *left = src;
    // 문자열의 끝에 공백 문자를 제외한 오른쪽 끝을 찾음
    char *right = src + my_strlen(src) - 1;
    char temp;
    // 문자열을 왼쪽에서 오른쪽으로 반전
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

// 문자열을 변환하여 출력하는 함수
void trans_str(const char* src) {

    std::string str(src);
    std::cout << "String 변환 : " << str << std::endl;

    std::string reversed_str;

    // 문자열을 거꾸로 덧붙여서 역순 문자열 생성
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed_str += str[i];
    }

    std::cout << "String 뒤집기 : " << reversed_str << std::endl;
}

int main() {

    char input_string[MAX_STRING_LENGTH+1];
    char copy_string[MAX_STRING_LENGTH+1];

    // 사용자로부터 문자열 입력 받기
    std::cout << "문자열을 입력하세요." << std::endl;
    std::cin >> input_string;

    // 문자열 길이가 최대 길이를 초과하는지 확인
    if (my_strlen(input_string) > MAX_STRING_LENGTH) {
        std::cout << "\n범위를 초과했어요." << std::endl;

        return 0;

    } else {
    // 문자열 복사
    my_strcpy(copy_string, input_string);
    printf("\nchar 배열 복사 : %s\n", copy_string);

    // 문자열 뒤집기
    my_strrev(input_string);
    printf("char 배열 뒤집기: %s\n\n", input_string);

    // 문자열 변환 및 출력
    trans_str(copy_string);

    return 0;
    }
}
