#include "���.h"


int add(void) {
    int flag = 0;
    int i = 0, count = 0;
    char name[M] = { 0 };
    char check;
    //char file_name[100][MAX];
    char buffer[MAX] = { 0 };

    do {

        printf("====================�Ĵ� ���=================\n");
        printf("(��� ��Ҵ� #�� �Է����ּ���.)\n");
        printf("����� ���Ͻô� �Ĵ� �̸��� �Է��� �ּ���: ");
        scanf("%s", name);
        printf("\n\n");
        while (getchar() != '\n');
        //for (i = 0; i < strlen(name); i++) {
        //    if ( name[i] == 35 ) {
        //        flag = 2;
        //        break;
        //    }
        //}
        if (name[0] == 35) {
            printf("����� ��ҵǾ����ϴ�.\n");
            printf("----------------MAIN MENU�� ���ư��ϴ�.----------\n\n\n\n");
            break;
        }

        printf("�Է��Ͻ� �Ĵ� �̸��� �½��ϱ�?(Y/N): ");
        scanf("%c", &check);
        printf("\n");
        while (getchar() != '\n');
        flag = 1;

    } while (flag == 0);

    if (flag == 1) {
        FILE* p = fopen("�Ĵ縮��Ʈ.txt", "a");
        if (p == NULL) {
            printf("���Ͽ��� ����\n");
        }
        fprintf(p, "%s.txt\n", name);
        fclose(p);

        printf("�Ĵ� ����� �Ϸ�Ǿ����ϴ�!\n");
    }
    return 0;
}

