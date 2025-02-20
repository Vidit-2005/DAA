#include<bits/stdc++.h>
using namespace std;

void selection(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
                min=j;
        }
        if(min!=i)
            swap(arr[i], arr[min]);
    }
}

void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n,*arr,*arr2;
    cout<<"Enter the size of array: ";
    cin>>n;
    arr= new int[n];
    arr2= new int[n];
    cout<<"enter the numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr2[i]=arr[i];
    }

    selection(arr,n);
    cout<<endl<<"sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"sorted array is: ";
    insertion(arr2,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}
