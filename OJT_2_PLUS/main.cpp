// OJT_2 과제 동적 할당 버전.
// 너비와 높이를 입력받을 수 있고, 2차원 배열을 사용.
#include <iostream>
#include <iomanip>

int** rotate_left(int** arr, int row, int column) {

    int** temp = new int*[column];

    for (int i = 0; i < column; i++) {
        temp[i] = new int[row];
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            temp[i][j] = arr[j][column - 1 - i];
        }
    }

    return temp;
}

int** rotate_right(int** arr, int row, int column) {

    int** temp = new int*[column];

    for (int i = 0; i < column; i++) {
        temp[i] = new int[row];
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            temp[i][j] = arr[row - 1 - j][i];
        }
    }

    return temp;
}

int** rotate_reverse(int** arr, int row, int column) {

    int** temp = new int*[row];

    for (int i = 0; i < row; i++) {
        temp[i] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            temp[i][j] = arr[row - 1 - i][column - 1 - j];
        }
    }

    return temp;
}

int main() {

    int row;
    int col;
    int cnt = 1;
	int TYPE_NUM;

    std::cout << "ㄱ 문자 출력을 원하시면 11을 입력 해주세요.(아닐시 다른숫자 입력)" << std::endl;
    std::cin >> TYPE_NUM;
    std::cout << "너비 : ";
    std::cin >> row;
    std::cout << "높이 : ";
    std::cin >> col;

    int** ary = new int*[row];

    for (int i = 0; i < row; ++i) {
        ary[i] = new int[col];
    }

	if (TYPE_NUM == 11){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 | (j == col - 1)) {
                    ary[i][j] = 11;
                } else {
                    ary[i][j] = 0;
                }
            }
        }
	} else {
		        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ary[i][j] = cnt++;
            }
        }
	}

    std::cout << "\n원본 배열:" << std::endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(2) << std::setfill('0') << ary[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n왼쪽으로 회전한 배열:" << std::endl;
    int** rotate_array_left = rotate_left(ary, row, col);

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << std::setw(2) << std::setfill('0') << rotate_array_left[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n오른쪽으로 회전한 배열:" << std::endl;
    int** rotate_array_right = rotate_right(ary, row, col);

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << std::setw(2) << std::setfill('0') << rotate_array_right[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n180도으로 회전한 배열:" << std::endl;
    int** rotate_array_reverse = rotate_reverse(ary, row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(2) << std::setfill('0') << rotate_array_reverse[i][j] << " ";
        }
        std::cout << '\n';
    }

    for (int i = 0; i < row; i++) {
        delete[] ary[i];
    }

    delete[] ary;

    return 0;

}
