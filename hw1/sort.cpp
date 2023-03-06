//Algorithm hw1
//sort
#include<iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
    int i,j,tmp;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[j]>a[j+1]) //if less than swap
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
}
void insertion_sort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(key<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j++;
        }
        a[j+1]=key;
    }
}
void quick_sort(int a[],int n)
{
    
}
void selection_sort(int a[],int n)
{
    int i,j,tmp,minn;
    for(i=0;i<n-1;i++)
    {
        minn=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[minn]&&j!=minn)
                minn=j;
        tmp=a[i];
        a[i]=a[minn];
        a[minn]=tmp;
    }
}
int main()
{
    int a[10]={5,8,1,9,2,10,4,6,3,7};
    // bubble_sort(a,10);
    // insertion_sort(a,10);
    selection_sort(a,10);
    return 0;
}


void selection_sort(int a[],int n)
    int i,j,tmp,min;
    for i=0 ~ length(A)-1
        min=i
         for j=i+1 ~ length(A)-1
            if A[j]<A[minn]
                minn=j
        if min!=j
            swap(A[j],A[min])
