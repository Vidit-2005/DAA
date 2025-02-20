#include<bits/stdc++.h>
using namespace std;

int binarylow(int arr[],int size,int target)
{
    int low=0,high=size,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]>=target)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int binaryhigh(int arr[],int size,int target)
{
    int low=0,high=size,mid,ans=-1;
    while(low<=high)
    {
        mid=low + (high-low)/2;
        if(arr[mid]<=target)
        {
            low=mid+1;
            ans=mid;
        }
        else
            high=mid-1;
    }
    return ans;
}

int main()
{
    int arr[]={1,3,5,5,5,5,7,7,9};
    int target=5,low,high;
    int size=sizeof(arr)/sizeof(arr[0]) -1 ;
    cout<<"Size= "<<size<<endl;
    low=binarylow(arr,size,target);
    high=binaryhigh(arr,size,target);
    cout<<"number of occurence= "<<high-low+1;
    return 0;
}
