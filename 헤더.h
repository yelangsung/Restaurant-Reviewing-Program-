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
int rankingprogram(void);//���� �ڵ� ���Ⱑ �ֽ�

int add(void);

char file_name[100][MAX];// ���ϸ� ����� �迭 ���� �ҷ� �� �� ��� ( ���� arirang.txt, subway.txt ���)
char restaurant_name[100][MAX]; // �Ĵ� �̸� ����� �迭
int total_restaurant_count;// �� ��ϵ� �Ĵ��� ��

