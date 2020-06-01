#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(char a[],int l,int m,int h);
void merge(char a[],int l,int m,int h)
{
    int i=l,j=m+1,k=l;
    int b[50];
    while(i<=m&&j<=h)
    {
        if((a[i]>='A'&&a[i]<='Z')&&(a[j]>='a'&&a[j]<='z'))
        {
            if((a[i]+32)<a[j])
            {
               a[k++]=a[i++];
            }
            else
            {
               b[k++]=a[j++];
            }
        }
        else if((a[i]>='a'&&a[i]<='b')&&(a[j]>='A'&&a[j]<='Z'))
        {
            if(a[i]<(a[j]+32))
            {
               b[k++]=a[i++];
            }
            else
            {
               b[k++]=a[j++];
            }
        }
        else if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    for(;i<=m;i++)
    {
        b[k++]=a[i];
    }
    for(;j<=h;j++)
    {
        b[k++]=a[j];
    }
    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}
void mergesort(char a[],int n);
void mergesort(char a[],int n)
{
    int t,l,h,m,i;
    for(t=2;t<=n;t=t*2)
    {
        for(i=0;i+t-1<=n;i=i+t)
        {
            l=i;
            h=i+t-1;
            m=(l+h)/2;
            merge(a,l,m,h);
        }
    }
    if(t/2<n)
    {
        merge(a,0,(t/2)-1,n-1);
    }
}
int main()
{
    char a[]="Testcase";
    int n=9;
    mergesort(a,n);
    int i,j;
    for(i=0;i<n;i++)
      printf("%c ",a[i]);
      printf("\n");
    return 0;
}
