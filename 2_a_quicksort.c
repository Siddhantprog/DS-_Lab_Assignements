#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void quick_sort(int a[],int l,int h);
void quick_sort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,h);
	}
}
int partition(int a[],int l,int h);
int partition(int a[],int l,int h)
{
	int t,i,j,temp;
	t=a[l];
	i=l;
	j=h+1;
	do
	{
		do
			i++;
		while(a[i]<t&&i<=h);
		do
			j--;
		while(t<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);
	a[l]=a[j];
	a[j]=t;
	return(j);
}

int main()
{
	int a[100],n,i;
	printf("Enter no of elements:\n");
	scanf("%d",&n);
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
           scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	   printf("\nSorted array:\n");
	for(i=0;i<n;i++)
          printf("%d ",a[i]);
	return 0;
}
