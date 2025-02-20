#include<bits/stdc++.h>
using namespace std;
void merges(int arr[],int l,int mid,int r)
{
    int *arr1=new int[(r-l)+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r )
    {
        if(arr[i]<arr[j])
            arr1[k++]=arr[i++];
        else
            arr1[k++]=arr[j++];
    }
    while(i<=mid)
    {
        arr1[k++]=arr[i++];
    }
    while(j<=r)
    {
            arr1[k++]=arr[j++];
    }
    for(i=l,j=0;i<=r;i++,j++)
        arr[i]=arr1[j];
}
void msort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        msort(arr,l,mid);
        msort(arr,mid+1,r);
        merges(arr,l,mid,r);
    }
    else return;
}
int main()
{
    int n,*arr;
    cout<<"Enter the size of array: ";
    cin>>n;
    arr= new int[n];
    cout<<"enter the numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    msort(arr,0,n);
    cout<<endl<<"sorted array is: ";
    int f=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            cout<<"Yes!!!!"<<endl;
            f=1;
            break;
        }
    }
    if(!(f))
        cout<<"NO!!!!"<<endl;
}

