#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

//��tm��,c vs����ͨ�õģ�����.cp��ctrl+space
//�鲢����
void MergeSort(int* a, int n);
void _MergeSort(int* a, int begin, int end, int* tmp);