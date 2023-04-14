#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

//这tm是,c vs上是通用的，那是.cp，ctrl+space
//归并排序
void MergeSort(int* a, int n);
void _MergeSort(int* a, int begin, int end, int* tmp);