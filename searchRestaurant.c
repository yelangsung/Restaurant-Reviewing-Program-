#define _CRT_SECURE_NO_WARNINGS
#include "���.h"
#define MAX 30
#pragma warning(disable :4996)
#define MAX_LEN 1000

int searchRestaurant(void)
{
    char review[150];
    int Restaurant_count;
    int Restaurant;
    char str[MAX_LEN];
    int i, flag = 0;

    do {
        printf("                      ��Restaurant number��\n");
        printf("****************************************************************\n\n");
        for (i = 0; i < total_restaurant_count; i++) {
            printf("%d. %s  ", i, restaurant_name[i]);
        }
        printf("\n");
        printf("****************************************************************\n\n");
        printf("�˻��ϰ� ���� �Ĵ� ��ȣ�� �����ϼ��� ");
        flag = scanf("%d", &Restaurant);
        printf("\n");

        if (flag != 1 || Restaurant > (total_restaurant_count - 1)) {
            printf("@@�߸� �����ϼ̽��ϴ�. 0~%d �ٽ� ������ �ּ���.\n\n", total_restaurant_count - 1);
            while (getchar() != '\n');
            flag = 0;
        }
    } while (flag != 1);

    printf("**%s �Ĵ��� �ı�**\n\n", restaurant_name[Restaurant]);
    FILE* fs = fopen(file_name[Restaurant], "r");
    while (fgets(str, sizeof(str), fs) != NULL)
    {
        printf("%s", str);
    }
    fclose(fs);
    printf("\n\n\n");



}