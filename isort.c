#include <stdio.h>

void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);
void print_arr(int* arr,int len);

void shift_element(int*arr, int i)
{
	while (i>=0)
	{
		*(arr+i+1) = *(arr+i);
		i--;
	}
}
void insertion_sort(int* arr, int len)
{
	int i,key,j;
	for (i=1;i<len;i++)
	{
		key = *(arr+i);
		j=i-1;
		while((*(arr+j)>key) && (j>=0))
		{
			*(arr+j+1) = *(arr+j);
			j--;
		}
		*(arr+j+1)=key;
	}
}
void print_arr(int* arr, int len)
{
	printf("\n");
	for(int i=0;i<len;i++)
	{
		printf("%d",*(arr+i));
		if (i!=len-1)
			printf(",");
	}
}
int main()
{
	int arr[50];
	for(int i=0; i<50;i++)
	{
		scanf("%d",(arr+i));
	}
	insertion_sort(arr,50);
	print_arr(arr,50);
}