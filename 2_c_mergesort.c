#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mergesort(int a[],int i,int j);
void mergesort(int a[],int i,int j)
{
	int m;
	if(i<j)
	{
		m=(i+j)/2;
		mergesort(a,i,m);
		mergesort(a,m+1,j);
		merge(a,i,m,m+1,j);
	}
}
void merge(int a[],int x,int y,int z,int w);
void merge(int a[],int x,int y,int z,int w)
{
	int temp[100];
	int i,j,k;
	i=x;
	j=z;
	k=0;
	while(i<=y && j<=w)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=y)
		temp[k++]=a[i++];
	while(j<=w)
		temp[k++]=a[j++];
	for(i=x,j=0;i<=w;i++,j++)
		a[i]=temp[j];
}
int main()
{
	int a[100],n,i;
	printf("Enter no of elements:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	    printf("\nSorted array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
