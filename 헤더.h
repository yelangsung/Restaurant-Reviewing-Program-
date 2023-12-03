#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define REST 100
#define M 30

int searchRestaurant(void);
int reviewResister(void);

int rankingPrograme(void);
int rankingprogram(void);//수정 코드 여기가 최신

int add(void);

char file_name[100][MAX];// 파일명 저장된 배열 파일 불러 올 때 사용 ( 예시 arirang.txt, subway.txt 등등)
char restaurant_name[100][MAX]; // 식당 이름 저장된 배열
int total_restaurant_count;// 총 등록된 식당의 수

