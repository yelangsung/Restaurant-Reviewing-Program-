#include "헤더.h"


int add(void) {
    int flag = 0;
    int i = 0, count = 0;
    char name[M] = { 0 };
    char check;
    //char file_name[100][MAX];
    char buffer[MAX] = { 0 };

    do {

        printf("====================식당 등록=================\n");
        printf("(등록 취소는 #을 입력해주세요.)\n");
        printf("등록을 원하시는 식당 이름을 입력해 주세요: ");
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
            printf("등록이 취소되었습니다.\n");
            printf("----------------MAIN MENU로 돌아갑니다.----------\n\n\n\n");
            break;
        }

        printf("입력하신 식당 이름이 맞습니까?(Y/N): ");
        scanf("%c", &check);
        printf("\n");
        while (getchar() != '\n');
        flag = 1;

    } while (flag == 0);

    if (flag == 1) {
        FILE* p = fopen("식당리스트.txt", "a");
        if (p == NULL) {
            printf("파일열기 실패\n");
        }
        fprintf(p, "%s.txt\n", name);
        fclose(p);

        printf("식당 등록이 완료되었습니다!\n");
    }
    return 0;
}

