#include <iostream>
#include <iomanip>

////////////////////////////
// define GLOBAL Variable //
////////////////////////////
#define SOURCE_WIDTH 4
#define SOURCE_HEIGHT 7
#define TYPE_NUM 2 // 1 �̿��� ���ڸ� �Է��ϸ� '��' �׸� �迭�� ����

int SOURCET_BUF[SOURCE_WIDTH*SOURCE_HEIGHT];

// �������� ȸ��
void rotate_left() {

    for(int i = 0; i < SOURCE_WIDTH; i++) {
        for(int j = 0; j < SOURCE_WIDTH*SOURCE_HEIGHT; j++) {
            if(j % SOURCE_WIDTH == SOURCE_WIDTH-1) {
                std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
                std::cout << SOURCET_BUF[j-i];
            }
        }
        std::cout << "\n";
    }
}

// ���������� ȸ��
void rotate_right() {

}

// 180�� ������
void rotate_reverse() {

}

int main() {

	if (TYPE_NUM == 1){
        // ��ũ�� ��� TYPE_NUM�� 1�̶�� ���� ������ �ο�
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            SOURCET_BUF[i] = i+1;
        }
	} else {
        // ��ũ�� ��� TYPE_NUM�� 1�� �ƴ϶�� '��' �׸� �ο�
        for(int i = 0; i < SOURCE_WIDTH*SOURCE_HEIGHT; i++) {
            if(i < SOURCE_WIDTH || (i%SOURCE_WIDTH)+1 == SOURCE_WIDTH) {
                // �迭�� ù��° ��� ���� ���� ������ ���� ���ϴ� ��� 11�� �ο�
                SOURCET_BUF[i] = 11;
            }
            else {
                // �̿��� �迭���� 00�� �ο�
                SOURCET_BUF[i] = 0;
            }
        }
	}

    std::cout << "�⺻���" << std::endl;
    // �⺻ �迭 ���
    for(int i = 0; i < SOURCE_HEIGHT; i++) {
        for (int j = 0; j < SOURCE_WIDTH; j++) {
            std::cout << std::setw(2) << std::setfill('0'); // ���ڰ� ���ڸ� ���ڶ�� ���鿡 0�� �ο�
            std::cout << SOURCET_BUF[j+SOURCE_WIDTH*i];
        }
        std::cout << "\n";
        // ù��° ���� SOURCE_WIDTH�� ũ��� �������� ���� ������ �Ѿ
        // SOURCE_HEIGHT�� ũ�⸸ŭ �ݺ�
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
