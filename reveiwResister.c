#define _CRT_SECURE_NO_WARNINGS
#include "���.h"
#define MAX 30
#pragma warning(disable :4996)
#define MAX_LEN 1000

void starResister(int* c, int* s, int* t);

int reviewResister(void) {

    char review[150] = "\0";
    char recommend[100] = " ";
    int clean = 0, service = 0, taste = 0, end = 0;
    int Restaurant = 0;
    int i = 0;
    int flag = 0;

    do {
        printf("                      ��Restaurant number��\n");
        printf("****************************************************************\n\n");
        for (i = 0; i < total_restaurant_count; i++) {
            printf("%d. %s  ", i, restaurant_name[i]);
        }
        printf("\n");
        printf("****************************************************************\n\n");
        printf("���� ����� �Ĵ� ��ȣ�� �����ϼ���: ");
        flag = scanf("%d", &Restaurant);
        printf("\n");

        if (flag != 1 || Restaurant > (total_restaurant_count - 1)) {
            printf("@@�߸� �����ϼ̽��ϴ�. 0~%d �ٽ� ������ �ּ���.\n\n", total_restaurant_count - 1);
            while (getchar() != '\n');
            flag = 0;
        }
    } while (flag != 1);

    printf("**%s �Ĵ� ���並 ����մϴ�**\n\n", restaurant_name[Restaurant]);
    FILE* pFile;
    pFile = fopen(file_name[Restaurant], "a");
    starResister(&clean, &service, &taste);
    while (getchar() != '\n');

    printf("ª�� �ı⸦ �����ּ���.: ");
    scanf("%[^\n]s", &review);

    while (getchar() != '\n');

    printf("��õ �޴�: ");
    scanf("%[^\n]s", &recommend);

    //printf("%s\n", review); �ѱ� ��� Ȯ�� �ڵ�
    printf("\n");

    printf("�������� �ı� �����մϴ�:) \n\n");
    fprintf(pFile, "û�ᵵ %d\n���� %d\n�� %d\n����: %s\n��õ�޴�: %s\n\n", clean, service, taste, review, recommend);
    fclose(pFile);
}

void starResister(int* c, int* s, int* t) {
    //int c1=0, c2=0, c3=0;
    int flag = 0;

    printf("������ ������ּ���! (5�� ����)\n");

    do {
        printf("û�ᵵ(0~5): ");
        flag = scanf("%d", c);
        printf("\n");
        if (flag != 1) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            flag = 0;
        }
    } while (flag != 1);

    do {
        printf("����(0~5): ");
        flag = scanf("%d", s);
        printf("\n");
        if (flag != 1) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            flag = 0;
        }
    } while (flag != 1);

    do {
        printf("��(0~5): ");
        flag = scanf("%d", t);
        printf("\n");
        if (flag != 1) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@�߸� �Է��ϼ̽��ϴ�! 0~5������ ������ �Ű��ּ���.\n\n");
            flag = 0;
        }
    } while (flag != 1);


}