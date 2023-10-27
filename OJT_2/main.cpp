#include <iostream>
#include <iomanip>

////////////////////////////
// define GLOBAL Variable //
////////////////////////////

#define SOURCE_WIDTH 4
#define SOURCE_HEIGHT 8
#define TYPE_NUM 2 // 1 �̿��� ���ڸ� �Է��ϸ� '��' �׸� �迭�� ����

int SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT]; // source buffer

// �������� ȸ��
void rotate_left() {

	for(int i = 0, j = 0, k = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
		std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
        std::cout << SOURCET_BUF[SOURCE_WIDTH*(k+1)-1-j];
        k++;
        // ���� ���� ũ�Ⱑ SOURCE_HEIGHT�� ũ��� �������� ���� ������ �Ѿ
        if(k == SOURCE_HEIGHT) {
            std::cout << "\n";
            j++;
            k = 0;
        }
    }
}

// ���������� ȸ��
void rotate_right() {

	for(int i = SOURCE_WIDTH*SOURCE_HEIGHT, j = 0, k = SOURCE_HEIGHT - 1; i > 0; i--) {
		std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
        std::cout << SOURCET_BUF[(SOURCE_WIDTH*k)+j];
        k--;
        // ���� ���� ũ�Ⱑ SOURCE_HEIGHT�� ũ��� �������� ���� ������ �Ѿ
        if(k + 1 == 0) {
            std::cout << "\n";
            j++;
            k = SOURCE_HEIGHT - 1;
        }
    }
}

// 180�� ������
void rotate_reverse() {

	// ���� �迭�� ������ �ε������� ������� ��� SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT-1]
	for(int i = SOURCE_WIDTH*SOURCE_HEIGHT-1; i >= 0; i--) {
		std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
        std::cout << SOURCET_BUF[i];

        if(i % SOURCE_WIDTH == 0) {
		// ���� �ε����� SOURCE_WIDTH�� ����϶� ���� ������ �Ѿ
        std::cout << "\n";
        }
    }
}

int main() {

    // ��ũ�� ��� TYPE_NUM�� 1�̶�� ���� ������ �ο�
	#if TYPE_NUM == 1
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            SOURCET_BUF[i] = i+1;
        }

	// ��ũ�� ��� TYPE_NUM�� 1�� �ƴ϶�� '��' �׸� �ο�
	# else
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            if(i < SOURCE_WIDTH || (i%SOURCE_WIDTH)+1 == SOURCE_WIDTH) {
                // �迭�� ù��° ��� ���� ���� ������ ���� ���ϴ� ��� '11'�� �ο�
                SOURCET_BUF[i] = 11;
            }
            else {
                // �̿��� �迭���� '00'�� �ο�
                SOURCET_BUF[i] = 0;
            }
        }

    #endif // TYPE_NUM

    std::cout << "�⺻���" << std::endl;

    // �⺻ �迭 ���
    for(int i = 0; i < SOURCE_HEIGHT; i++) {
		// SOURCE_HEIGHT�� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < SOURCE_WIDTH; j++) {
            std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
            std::cout << SOURCET_BUF[j+SOURCE_WIDTH*i];
            // ���� ���� SOURCE_WIDTH ũ��� �������� ���� ������ �Ѿ
            if (j+1 == SOURCE_WIDTH) {
                std::cout << "\n";
            }
        }
    }

    std::cout << "\n�������� ȸ��" << std::endl;
    // �������� ȸ���� �迭 ���
    rotate_left();

    std::cout << "\n���������� ȸ��" << std::endl;
    // ���������� ȸ���� �迭 ���
    rotate_right();

    std::cout << "\n180�� ������" << std::endl;
    // 180�� ȸ���� �迭 ���
    rotate_reverse();

    return 0;

}
