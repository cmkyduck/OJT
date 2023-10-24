// OJT_2 ���� ���� �Ҵ� ����.
// �ʺ�� ���̸� �Է¹��� �� �ְ�, 2���� �迭�� ���.
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

    std::cout << "�� ���� ����� ���Ͻø� 11�� �Է� ���ּ���.(�ƴҽ� �ٸ����� �Է�)" << std::endl;
    std::cin >> TYPE_NUM;
    std::cout << "�ʺ� : ";
    std::cin >> row;
    std::cout << "���� : ";
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

    std::cout << "\n���� �迭:" << std::endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(2) << std::setfill('0') << ary[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n�������� ȸ���� �迭:" << std::endl;
    int** rotate_array_left = rotate_left(ary, row, col);

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << std::setw(2) << std::setfill('0') << rotate_array_left[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n���������� ȸ���� �迭:" << std::endl;
    int** rotate_array_right = rotate_right(ary, row, col);

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << std::setw(2) << std::setfill('0') << rotate_array_right[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\n180������ ȸ���� �迭:" << std::endl;
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
