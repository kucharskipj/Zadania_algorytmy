#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void selection_sort(int * arr, int arr_size)
{
int tmp, minpos;
for (int j=0; j<arr_size;j++)
{
minpos=j;
for (int i=j; i<arr_size;i++)
	{
		if (arr[minpos] > arr[i+1])
		{
			minpos = i+1;
		}	
	}
if (minpos != j)
{
tmp=arr[j];
arr[j]=arr[minpos];
arr[minpos]=tmp;
}
}
}




int prt(int *arr, int arr_size)
{
	for (int i=0; i<10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
return 0;
}

int grand(int *tab, int tab_len, int max){
time_t t;
srand((unsigned) time(&t));
for (int i=0;i<tab_len;i++)
{
tab[i]=rand() % max;
}
return 0;
}

void sort(int *arr, int arr_size, void (*sortowanie)(int*, int), int max)
{
grand(arr,arr_size,max);
prt(arr,arr_size);
sortowanie(arr,arr_size);
prt(arr,arr_size);
printf("\n");
}


int main() 
{
int max =50;
int tab_len=10;
int tab[tab_len];

sort(tab,tab_len,selection_sort,max);
return 0;
}
