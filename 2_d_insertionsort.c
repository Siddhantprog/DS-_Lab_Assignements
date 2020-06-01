#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[100],i,j,n,temp;
    printf("Enter no of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;

        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    printf("\nSorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
