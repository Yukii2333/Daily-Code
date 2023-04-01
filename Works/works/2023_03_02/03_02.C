#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define MAXN 20

int Delete(int A[], int L, int minA, int maxA)
{
for (int i = 0; i < L; i++)
{
    if (A[i]<maxA && A[i]>minA)
    {
        for (i; i < L; i++)
        {
            A[i] = A[i + 1];
        }
    }
}
    return 2;
}

int main()
{
    int A[MAXN], L, minA, maxA, i;

    scanf("%d", &L);
    for (i = 0; i < L; i++) scanf("%d", &A[i]);
    scanf("%d %d", &minA, &maxA);
    L = Delete(A, L, minA, maxA);
    for (i = 0; i < L; i++) printf("%d ", A[i]);
    printf("\n");
	return 0;
}