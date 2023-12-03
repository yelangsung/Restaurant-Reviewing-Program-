#include "헤더.h"

int main(void) {
    int menu = 0;
    int pass_flag = 0;
    int flag = 0;

    int user_pass = 0;
    int pass = 1906;
    int i = 0, count = 0;
    char buffer[MAX] = " ";

    printf("****************************************************************\n");
    printf("                        < 숙 먹 숙 먹 >\n");
    printf("****************************************************************\n");

    do {
        printf("눈송이 확인을 위한 코드를 입력하세요! ");
        pass_flag = scanf("%d", &user_pass);
        printf("\n");

        if (user_pass == pass) {
            flag = 1;
            printf("인증에 성공하셨습니다!!\n\n");

        }
        else {
            while (getchar() != '\n');
            printf("@@잘못된 코드입니다. 다시 입력해 주세요!\n\n\n");
        }
    } while (flag != 1);



    do {
        do {
            printf("==================== MAIN MENU =================\n");
            printf("                  1. 리뷰 등록\n");
            printf("                  2. 식당 리뷰 확인\n");
            printf("                  3. 별점 순위 확인\n");
            printf("                  4. 식당등록 \n");
            printf("                  5. 종료\n");
            printf("================================================\n");
            printf("원하시는 메뉴를 선택해주세요(1-5): ");
            flag = scanf("%d", &menu);
            printf("\n");
            if (flag != 1 || menu > 5) {
                printf("@@잘못 입력하셨습니다! 숫자 1-5 중 하나를 입력하세요.\n\n\n\n");
                while (getchar() != '\n');
            }
        } while (flag != 1);

        //printf("식당 총: %d개\n", total_restaurant_count);
        //for (i = 0; i < total_restaurant_count; i++) {
        //    printf("%s\n", restaurant_name[i]);
        //}

        //식당 이름 불러오기
        FILE* pr = fopen("식당리스트.txt", "r");
        count = 0;
        total_restaurant_count = 0;
        if (pr == NULL) {
            printf("파일열기 실패\n");
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
            //리뷰 등록 프로그램
            reviewResister();
            break;

        case 2:
            //검색 
            searchRestaurant();
            break;

        case 3:
            //별점 확인 프로그램
            //rankingProgram( );
            rankingprogram();
            break;

        case 4:
            //새로운 식당 등록 프로그램
            add(1);
            break;
        }


    } while (menu != 5);

    printf("프로그램을 종료합니다.\n");
    return 0;
}
