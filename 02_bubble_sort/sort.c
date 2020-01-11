#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void bubble_sort_1(int * arr, int arr_size)
{
int tmp;
for (int j=0; j<arr_size;j++)
{
for (int i=0; i<arr_size;i++)
	{
		if (arr[i] > arr[i+1])
		{
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
		}	
	}
}
}

void bubble_sort_2(int * arr, int arr_size)
{
int tmp;
int sorted_ele=0;
for (int j=0; j<arr_size;j++)
{
for (int i=0; i<arr_size-sorted_ele;i++)
	{
		if (arr[i] > arr[i+1])
		{
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
		}
	}
	sorted_ele++;
}
}

void bubble_sort_3(int * arr, int arr_size)
{
int tmp;
int sorted_ele=0;
bool sorted=false;
while(!sorted)
{
sorted=true;
for (int i=0; i<arr_size-sorted_ele;i++)
	{
		if (arr[i] > arr[i+1])
		{
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
			sorted=false;
		}	
	}
	sorted_ele++;
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

sort(tab,tab_len,bubble_sort_1,max);
sort(tab,tab_len,bubble_sort_2,max);
sort(tab,tab_len,bubble_sort_3,max);
return 0;
}
