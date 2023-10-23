#include <iostream>
#include <iomanip>

////////////////////////////
// define GLOBAL Variable //
////////////////////////////
#define SOURCE_WIDTH 4
#define SOURCE_HEIGHT 7
#define TYPE_NUM 2 // 1 이외의 숫자를 입력하면 'ㄱ' 그림 배열로 변경

int SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT];

// 왼쪽으로 회전
void rotate_left() {

    for(int i = 0; i < SOURCE_WIDTH; i++) {
        for(int j = 0; j < SOURCE_WIDTH*SOURCE_HEIGHT; j++) {
            if(j % SOURCE_WIDTH == SOURCE_WIDTH-1) {
                std::cout << std::setw(2) << std::setfill('0'); // 숫자가 한자리 숫자라면 공백에 0을 부여
                std::cout << SOURCET_BUF[j-i];
            }
        }
        std::cout << "\n";
    }
}

// 오른쪽으로 회전
void rotate_right() {

}

// 180도 뒤집기
void rotate_reverse() {

}

int main() {

	if (TYPE_NUM == 1){
        // 매크로 상수 TYPE_NUM이 1이라면 숫자 데이터 부여
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            SOURCET_BUF[i] = i+1;
        }
	} else {
        // 매크로 상수 TYPE_NUM이 1이 아니라면 'ㄱ' 그림 부여
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            if(i < SOURCE_WIDTH || (i%SOURCE_WIDTH)+1 == SOURCE_WIDTH) {
                // 배열의 첫번째 행과 현재 행의 마지막 열에 속하는 경우 11을 부여
                SOURCET_BUF[i] = 11;
            }
            else {
                // 이외의 배열에는 00을 부여
                SOURCET_BUF[i] = 0;
            }
        }
	}

    std::cout << "기본출력" << std::endl;
    // 기본 배열 출력
    for(int i = 0; i < SOURCE_HEIGHT; i++) {
        for (int j = 0; j < SOURCE_WIDTH; j++) {
            std::cout << std::setw(2) << std::setfill('0'); // 숫자가 한자리 숫자라면 공백에 0을 부여
            std::cout << SOURCET_BUF[j+SOURCE_WIDTH*i];
        }
        std::cout << "\n";
        // 첫번째 행이 SOURCE_WIDTH의 크기와 같아지면 다음 행으로 넘어감
        // SOURCE_HEIGHT의 크기만큼 반복
    }

    std::cout << "\n왼쪽으로 회전" << std::endl;
    // 왼쪽으로 회전된 배열 출력
    rotate_left();

    std::cout << "\n오른쪽으로 회전" << std::endl;
    // 오른쪽으로 회전된 배열 출력
    rotate_right();

    std::cout << "\n180도 뒤집기" << std::endl;
    // 180도 회전된 배열 출력
    rotate_reverse();

    return 0;

}
