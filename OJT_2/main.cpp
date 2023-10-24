#include <iostream>
#include <iomanip>

////////////////////////////
// define GLOBAL Variable //
////////////////////////////

#define SOURCE_WIDTH 4
#define SOURCE_HEIGHT 8
#define TYPE_NUM 1 // 1 �̿��� ���ڸ� �Է��ϸ� '��' �׸� �迭�� ����

int SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT];

// �������� ȸ��
void rotate_left() {

    for(int i = 0; i < SOURCE_WIDTH; i++) {
		// ���� �迭�� ù��° �ε������� ������� ��� SOURCET_BUF[0]
        for(int j = 0; j < SOURCE_WIDTH*SOURCE_HEIGHT; j++) {
			// �������� ȸ���� ù��° ���� �ε����� SOURCE_WIDTH�� ũ��� ���������� �������� SOURCE_WIDTH-1
            if(j % SOURCE_WIDTH == SOURCE_WIDTH-1) {
                std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
                std::cout << SOURCET_BUF[j-i];
                // ���� �ε����� SOURCE_WIDTH*SOURCE_HEIGHT-SOURCE_WIDTH�� ũ�⺸�� ũ�ų� ���� ��� ���� ������ �Ѿ
                if(j-i >= SOURCE_WIDTH*SOURCE_HEIGHT-SOURCE_WIDTH){
                    std::cout << "\n";
                }
            }
        }
    }
}

// ���������� ȸ��
void rotate_right() {

	for(int i = 0; i < SOURCE_WIDTH; i++) {
		// ���� �迭�� ������ �ε������� ������� ��� SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT-1]
        for(int j = SOURCE_WIDTH*SOURCE_HEIGHT - 1 ; j >= 0; j--) {
        	// ���������� ȸ���� ù��° ���� �ε����� SOURCE_WIDTH�� ���
            if(j % SOURCE_WIDTH == 0) {
				std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
                std::cout << SOURCET_BUF[j+i];
                // ���� �ε����� SOURCE_WIDTH�� ũ�⺸�� ���� ��� ���� ������ �Ѿ
				if(j+i < SOURCE_WIDTH) {
					std::cout << "\n";
                }
            }
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
	if (TYPE_NUM == 1){
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            SOURCET_BUF[i] = i+1;
        }
	}
	// ��ũ�� ��� TYPE_NUM�� 1�� �ƴ϶�� '��' �׸� �ο�
	else {
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
	}

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
