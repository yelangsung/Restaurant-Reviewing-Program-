#include "���.h"

int main(void) {
    int menu = 0;
    int pass_flag = 0;
    int flag = 0;

    int user_pass = 0;
    int pass = 1906;
    int i = 0, count = 0;
    char buffer[MAX] = " ";

    printf("****************************************************************\n");
    printf("                        < �� �� �� �� >\n");
    printf("****************************************************************\n");

    do {
        printf("������ Ȯ���� ���� �ڵ带 �Է��ϼ���! ");
        pass_flag = scanf("%d", &user_pass);
        printf("\n");

        if (user_pass == pass) {
            flag = 1;
            printf("������ �����ϼ̽��ϴ�!!\n\n");

        }
        else {
            while (getchar() != '\n');
            printf("@@�߸��� �ڵ��Դϴ�. �ٽ� �Է��� �ּ���!\n\n\n");
        }
    } while (flag != 1);



    do {
        do {
            printf("==================== MAIN MENU =================\n");
            printf("                  1. ���� ���\n");
            printf("                  2. �Ĵ� ���� Ȯ��\n");
            printf("                  3. ���� ���� Ȯ��\n");
            printf("                  4. �Ĵ��� \n");
            printf("                  5. ����\n");
            printf("================================================\n");
            printf("���Ͻô� �޴��� �������ּ���(1-5): ");
            flag = scanf("%d", &menu);
            printf("\n");
            if (flag != 1 || menu > 5) {
                printf("@@�߸� �Է��ϼ̽��ϴ�! ���� 1-5 �� �ϳ��� �Է��ϼ���.\n\n\n\n");
                while (getchar() != '\n');
            }
        } while (flag != 1);

        //printf("�Ĵ� ��: %d��\n", total_restaurant_count);
        //for (i = 0; i < total_restaurant_count; i++) {
        //    printf("%s\n", restaurant_name[i]);
        //}

        //�Ĵ� �̸� �ҷ�����
        FILE* pr = fopen("�Ĵ縮��Ʈ.txt", "r");
        count = 0;
        total_restaurant_count = 0;
        if (pr == NULL) {
            printf("���Ͽ��� ����\n");
        }
        while (fgets(buffer, sizeof(buffer), pr) != NULL) {
            buffer[strlen(buffer) - 1] = NULL;
            strcpy(file_name[count], buffer);
            //file_name[count][strlen(file_name[count]) - 1] = NULL;
            buffer[strlen(buffer) - 1] = NULL;
            buffer[strlen(buffer) - 1] = NULL;
            buffer[strlen(buffer) - 1] = NULL;
            buffer[strlen(buffer) - 1] = NULL;
            strcpy(restaurant_name[count], buffer);

            count++;
            total_restaurant_count++;
        }
        fclose(pr);

        switch (menu) {
        case 1:
            //���� ��� ���α׷�
            reviewResister();
            break;

        case 2:
            //�˻� 
            searchRestaurant();
            break;

        case 3:
            //���� Ȯ�� ���α׷�
            //rankingProgram( );
            rankingprogram();
            break;

        case 4:
            //���ο� �Ĵ� ��� ���α׷�
            add(1);
            break;
        }


    } while (menu != 5);

    printf("���α׷��� �����մϴ�.\n");
    return 0;
}
