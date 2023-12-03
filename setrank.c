//#define MAX 30
//#define REST 5
//int total_restaurant_count
#include "���.h"
#define _CRT_SECURE_NO_WARNINGS
#define  limit 5
void file_open_t(double avg[][3], char name[MAX]);
void ranking_t(double avgs[][3], int rank[4][REST], double total_avg[REST]);

int rankingprogram(void) {

    int i, align = 0;
    char rate_name[3][MAX] = { "��", "û�ᵵ", "����" };
    double rate_avg[REST][3] = { 0, 0, 0 };
    double total_avg[REST] = { 0 };
    int rank[4][REST] = { 0 };
    int menu = 0, flag = 0, count = 0, restaurant = 0;
    char buffer[MAX];

    for (i = 0; i < total_restaurant_count; i++) {
        file_open_t(rate_avg[i], file_name[i]);

    }
    ranking_t(rate_avg, rank, total_avg);
    do {
        do {
            //printf("===============================================\n");
            printf("===================== ���� Ȯ�� ==================\n");
            printf("              ���� ������ �˷��帳�ϴ�. \n");
            printf("                1. ��ü ���� ���� \n");
            printf("                2. �� ���� ����\n");
            printf("                3. û�ᵵ ���� ����\n");
            printf("                4. ���� ���� ����\n");
            printf("                5. �Ĵ纰 ����\n");
            printf("                6. ���� \n");
            printf("=================================================\n\n");
            printf("���Ͻô� �޴��� �������ּ���(1-6): ");
            flag = scanf("%d", &menu);
            printf("\n");
            if (flag != 1) {
                printf("�߸� �Է��ϼ̽��ϴ�! 1-6 �� �ϳ��� �Է��ϼ���.\n\n");
                while (getchar() != '\n');
            }
        } while (flag != 1);


        switch (menu) {
        case 1:
            printf("-----------------1.��ü ���� ����-----------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d�� %20s %.2f  ", i + 1, restaurant_name[rank[3][i]], total_avg[i]);
                printf("\n");
            }
            printf("--------------------------------------------------\n\n\n\n");
            break;
        case 2://��
            printf("-----------------2. �� ���� ����-----------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d�� %s %.2f  ", i + 1, restaurant_name[rank[0][i]], rate_avg[rank[0][i]][0]);
                printf("\n");
            }
            printf("-------------------------------------------------\n\n\n\n");

            break;

        case 3://����
            printf("----------------3. ���� ���� ����---------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d�� %s %.2f  ", i + 1, restaurant_name[rank[1][i]], rate_avg[rank[1][i]][1]);
                printf("\n");
            }
            printf("------------------------------------------------\n\n\n\n");

            break;
        case 4://����
            printf("---------------2. ���� ���� ����--------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d�� %s %.2f  ", i + 1, restaurant_name[rank[2][i]], rate_avg[rank[2][i]][2]);
                printf("\n");
            }
            printf("------------------------------------------------\n\n\n\n");

            break;
        case 5://�Ĵ纰
            do {

                printf("--------------5. �Ĵ纰 ����----------------\n");
                printf("�Ĵ��� �� %d ��", total_restaurant_count);
                for (i = 0; i < total_restaurant_count; i++) {
                    printf("%d. %s  ", i, restaurant_name[i]);
                }
                printf("\n");
                printf("-------------------------------------------\n");
                printf("���ϴ� �Ĵ��� �Է��ϼ���(0~%d): ", total_restaurant_count - 1);
                flag = scanf("%d", &restaurant);

                if ((flag != 1) || (restaurant > total_restaurant_count - 1)) {
                    printf("�߸� �Է��ϼ̽��ϴ�! 0���� %d �� �ϳ��� �Է��ϼ���.\n\n", total_restaurant_count - 1);
                    printf("\n\n\n\n");

                    flag = 0;
                    while (getchar() != '\n');
                }
            } while (flag != 1);
            printf("\n");
            printf("%s ��������� ����\n", restaurant_name[restaurant]);

            printf("%s ��� = %.2f\n", rate_name[0], rate_avg[restaurant][0]);
            printf("%s ��� = %.2f\n", rate_name[1], rate_avg[restaurant][1]);
            printf("%s ��� = %.2f\n\n\n\n", rate_name[2], rate_avg[restaurant][2]);

            break;

        case 6:
            printf("----------------- MAIN MENU�� ���ư��ϴ�.-------------\n\n");
            break;

        }
    } while (menu != 6);

    return 0;
}

void file_open_t(double avg[3], char name[MAX]) {
    char buffer[20] = { 0 };
    int order[3] = { 3, 7, 7 };
    int rate[REST][3] = { 0 };
    double rate_count[3] = { 0, 0, 0 };
    int count = 0;

    char* p;

    FILE* fp = fopen(name, "r");

    if (fp == NULL) {
        printf("���Ͽ������\n");

    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        p = strstr(buffer, "��");

        if (p != NULL) {
            // printf("%c\n", buffer[3]);

            if (47 < buffer[order[0]] && buffer[order[0]] < 58) {
                rate[0][0] += buffer[order[0]] - '0';
                rate_count[0]++;

            }
        }

        p = strstr(buffer, "û�ᵵ");
        if (p != NULL) {
            //printf("����\n");
            //printf("%c%d\n", buffer[7], strlen(buffer));
            if (47 < buffer[order[1]] && buffer[order[1]] < 58) {
                rate[0][1] += buffer[order[1]] - '0';
                rate_count[1]++;

            }
        }
        p = strstr(buffer, "����");
        if (p != NULL) {
            //printf("����\n");
            if (47 < buffer[order[2]] && buffer[order[2]] < 58) {
                rate[0][2] += buffer[order[2]] - '0';
                rate_count[2]++;
            }
        }
    }
    avg[0] = rate[count][0] / rate_count[0];
    avg[1] = rate[count][1] / rate_count[1];
    avg[2] = rate[count][2] / rate_count[2];

    fclose(fp);

}
void ranking_t(double avgs[REST][3], int rank[4][REST], double total_avg[REST]) {
    int i, j, k = 0;
    double dump[REST][3] = { 0 };
    //temp: ��� ������ ������ ���� ����
    double temp = 0;
    int temp2 = 0;
    //rank[0]: ������
    //rank[1]: û�����
    //rank[2]: ���񽺼���
    //rank[3]: ��ü����

   // printf("��� ���\n");
    for (i = 0; i < total_restaurant_count; i++) {
        double sum = 0;
        for (j = 0; j < 3; j++) {
            dump[i][j] = avgs[i][j];
            //printf("%f  \n", avgs[i][j]);
            sum += avgs[i][j];
        }

        total_avg[i] = sum / 3;
        //printf("%d �Ĵ��� ��� �ջ� = %.2f\n", i, sum);
    }

    //�Ĵ� �оߺ� ���� ��� ����
    //printf("\n������\n");
    for (k = 0; k < 3; k++) {
        int name[REST] = { 0 };

        for (i = 0; i < total_restaurant_count; i++) { //�迭 ��ϵ� �Ĵ� ũ�⸸ŭ �迭 �ʱ�ȭ
            name[i] = i;
        }
        for (i = 0; i < REST; i++) {
            for (j = i + 1; j < REST; j++) {
                if (dump[i][k] < dump[j][k]) {
                    temp = dump[i][k];
                    dump[i][k] = dump[j][k];
                    dump[j][k] = temp;

                    temp2 = name[i];
                    name[i] = name[j];
                    name[j] = temp2;
                }
            }
            rank[k][i] = name[i];
        }
    }

    //�Ĵ� ��� �о� �ջ� ��� ����
    int name[REST] = { 0, 1, 2, 3, 4 };
    for (i = 0; i < total_restaurant_count; i++) { //�迭 ��ϵ� �Ĵ� ũ�⸸ŭ �迭 �ʱ�ȭ
        name[i] = i;
    }
    for (i = 0; i < total_restaurant_count; i++) {
        for (j = i + 1; j < total_restaurant_count; j++) {
            if (total_avg[i] < total_avg[j]) {
                temp = total_avg[i];
                total_avg[i] = total_avg[j];
                total_avg[j] = temp;

                temp2 = name[i];
                name[i] = name[j];
                name[j] = temp2;
            }
        }
        rank[3][i] = name[i];
    }
    /*for (i = 0; i < REST; i++) {
        printf("�� ���� %d�� %d\n", i+1, rank[4][i]);
    }
    printf("\n");*/

}