#define _CRT_SECURE_NO_WARNINGS
#include "헤더.h"
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
        printf("                      ★Restaurant number★\n");
        printf("****************************************************************\n\n");
        for (i = 0; i < total_restaurant_count; i++) {
            printf("%d. %s  ", i, restaurant_name[i]);
        }
        printf("\n");
        printf("****************************************************************\n\n");
        printf("리뷰 남기실 식당 번호를 선택하세요: ");
        flag = scanf("%d", &Restaurant);
        printf("\n");

        if (flag != 1 || Restaurant > (total_restaurant_count - 1)) {
            printf("@@잘못 선택하셨습니다. 0~%d 다시 선택해 주세요.\n\n", total_restaurant_count - 1);
            while (getchar() != '\n');
            flag = 0;
        }
    } while (flag != 1);

    printf("**%s 식당 리뷰를 등록합니다**\n\n", restaurant_name[Restaurant]);
    FILE* pFile;
    pFile = fopen(file_name[Restaurant], "a");
    starResister(&clean, &service, &taste);
    while (getchar() != '\n');

    printf("짧은 후기를 남겨주세요.: ");
    scanf("%[^\n]s", &review);

    while (getchar() != '\n');

    printf("추천 메뉴: ");
    scanf("%[^\n]s", &recommend);

    //printf("%s\n", review); 한글 출력 확인 코드
    printf("\n");

    printf("정성스런 후기 감사합니다:) \n\n");
    fprintf(pFile, "청결도 %d\n서비스 %d\n맛 %d\n리뷰: %s\n추천메뉴: %s\n\n", clean, service, taste, review, recommend);
    fclose(pFile);
}

void starResister(int* c, int* s, int* t) {
    //int c1=0, c2=0, c3=0;
    int flag = 0;

    printf("별점을 등록해주세요! (5점 만점)\n");

    do {
        printf("청결도(0~5): ");
        flag = scanf("%d", c);
        printf("\n");
        if (flag != 1) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            flag = 0;
        }
    } while (flag != 1);

    do {
        printf("서비스(0~5): ");
        flag = scanf("%d", s);
        printf("\n");
        if (flag != 1) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            flag = 0;
        }
    } while (flag != 1);

    do {
        printf("맛(0~5): ");
        flag = scanf("%d", t);
        printf("\n");
        if (flag != 1) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            while (getchar() != '\n');
        }
        if (*c < 0 || *c>5) {
            printf("@@잘못 입력하셨습니다! 0~5사이의 점수를 매겨주세요.\n\n");
            flag = 0;
        }
    } while (flag != 1);


}