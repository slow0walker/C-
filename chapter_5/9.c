#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int m1, d1, y1, m2, d2, y2;

    // �����һ������
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    // ����ڶ�������
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    // �ȱȽ���ݣ����С�����ڸ���
    if (y1 < y2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    }
    else if (y1 > y2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    }
    else {
        // �����ͬ���Ƚ��·�
        if (m1 < m2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
        }
        else if (m1 > m2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
        }
        else {
            // �·�Ҳ��ͬ���Ƚ�����
            if (d1 < d2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
            }
            else if (d1 > d2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
            }
            else {
                printf("The two dates are the same.\n");
            }
        }
    }

    return 0;
}