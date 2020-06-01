#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bubblesort(int a[],int n);
void bubblesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[100],n,i;
	printf("Enter no of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
	bubblesort(a,n);
	    printf("\nSorted array: \n");
    for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
