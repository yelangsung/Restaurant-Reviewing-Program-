//#define MAX 30
//#define REST 5
//int total_restaurant_count
#include "헤더.h"
#define _CRT_SECURE_NO_WARNINGS
#define  limit 5
void file_open_t(double avg[][3], char name[MAX]);
void ranking_t(double avgs[][3], int rank[4][REST], double total_avg[REST]);

int rankingprogram(void) {

    int i, align = 0;
    char rate_name[3][MAX] = { "맛", "청결도", "서비스" };
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
            printf("===================== 별점 확인 ==================\n");
            printf("              별점 순위를 알려드립니다. \n");
            printf("                1. 전체 별점 순위 \n");
            printf("                2. 맛 별점 순위\n");
            printf("                3. 청결도 별점 순위\n");
            printf("                4. 서비스 별점 순위\n");
            printf("                5. 식당별 별점\n");
            printf("                6. 종료 \n");
            printf("=================================================\n\n");
            printf("원하시는 메뉴를 선택해주세요(1-6): ");
            flag = scanf("%d", &menu);
            printf("\n");
            if (flag != 1) {
                printf("잘못 입력하셨습니다! 1-6 중 하나를 입력하세요.\n\n");
                while (getchar() != '\n');
            }
        } while (flag != 1);


        switch (menu) {
        case 1:
            printf("-----------------1.전체 별점 순위-----------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d등 %20s %.2f  ", i + 1, restaurant_name[rank[3][i]], total_avg[i]);
                printf("\n");
            }
            printf("--------------------------------------------------\n\n\n\n");
            break;
        case 2://맛
            printf("-----------------2. 맛 별점 순위-----------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d등 %s %.2f  ", i + 1, restaurant_name[rank[0][i]], rate_avg[rank[0][i]][0]);
                printf("\n");
            }
            printf("-------------------------------------------------\n\n\n\n");

            break;

        case 3://위생
            printf("----------------3. 위생 별점 순위---------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d등 %s %.2f  ", i + 1, restaurant_name[rank[1][i]], rate_avg[rank[1][i]][1]);
                printf("\n");
            }
            printf("------------------------------------------------\n\n\n\n");

            break;
        case 4://서비스
            printf("---------------2. 서비스 별점 순위--------------\n");
            for (i = 0; i < limit; i++) {
                printf("%d등 %s %.2f  ", i + 1, restaurant_name[rank[2][i]], rate_avg[rank[2][i]][2]);
                printf("\n");
            }
            printf("------------------------------------------------\n\n\n\n");

            break;
        case 5://식당별
            do {

                printf("--------------5. 식당별 별점----------------\n");
                printf("식당은 총 %d 개", total_restaurant_count);
                for (i = 0; i < total_restaurant_count; i++) {
                    printf("%d. %s  ", i, restaurant_name[i]);
                }
                printf("\n");
                printf("-------------------------------------------\n");
                printf("원하는 식당을 입력하세요(0~%d): ", total_restaurant_count - 1);
                flag = scanf("%d", &restaurant);

                if ((flag != 1) || (restaurant > total_restaurant_count - 1)) {
                    printf("잘못 입력하셨습니다! 0부터 %d 중 하나를 입력하세요.\n\n", total_restaurant_count - 1);
                    printf("\n\n\n\n");

                    flag = 0;
                    while (getchar() != '\n');
                }
            } while (flag != 1);
            printf("\n");
            printf("%s 레스토랑의 별점\n", restaurant_name[restaurant]);

            printf("%s 평균 = %.2f\n", rate_name[0], rate_avg[restaurant][0]);
            printf("%s 평균 = %.2f\n", rate_name[1], rate_avg[restaurant][1]);
            printf("%s 평균 = %.2f\n\n\n\n", rate_name[2], rate_avg[restaurant][2]);

            break;

        case 6:
            printf("----------------- MAIN MENU로 돌아갑니다.-------------\n\n");
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
        printf("파일열기실패\n");

    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        p = strstr(buffer, "맛");

        if (p != NULL) {
            // printf("%c\n", buffer[3]);

            if (47 < buffer[order[0]] && buffer[order[0]] < 58) {
                rate[0][0] += buffer[order[0]] - '0';
                rate_count[0]++;

            }
        }

        p = strstr(buffer, "청결도");
        if (p != NULL) {
            //printf("있음\n");
            //printf("%c%d\n", buffer[7], strlen(buffer));
            if (47 < buffer[order[1]] && buffer[order[1]] < 58) {
                rate[0][1] += buffer[order[1]] - '0';
                rate_count[1]++;

            }
        }
        p = strstr(buffer, "서비스");
        if (p != NULL) {
            //printf("있음\n");
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
    //temp: 잠시 데이터 저장을 위한 변수
    double temp = 0;
    int temp2 = 0;
    //rank[0]: 맛순위
    //rank[1]: 청결순위
    //rank[2]: 서비스순위
    //rank[3]: 전체순위

   // printf("평균 출력\n");
    for (i = 0; i < total_restaurant_count; i++) {
        double sum = 0;
        for (j = 0; j < 3; j++) {
            dump[i][j] = avgs[i][j];
            //printf("%f  \n", avgs[i][j]);
            sum += avgs[i][j];
        }

        total_avg[i] = sum / 3;
        //printf("%d 식당의 평균 합산 = %.2f\n", i, sum);
    }

    //식당 분야별 별점 평균 정렬
    //printf("\n등수출력\n");
    for (k = 0; k < 3; k++) {
        int name[REST] = { 0 };

        for (i = 0; i < total_restaurant_count; i++) { //배열 등록된 식당 크기만큼 배열 초기화
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

    //식당 모든 분야 합산 평균 정렬
    int name[REST] = { 0, 1, 2, 3, 4 };
    for (i = 0; i < total_restaurant_count; i++) { //배열 등록된 식당 크기만큼 배열 초기화
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
        printf("총 순위 %d등 %d\n", i+1, rank[4][i]);
    }
    printf("\n");*/

}