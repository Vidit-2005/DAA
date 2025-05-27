#include<bits/stdc++.h>
using namespace std;
int input(vector<int>&arr)
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        arr.push_back(m);
    }
    return n;
}

void print(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(vector<int>&nums,int low,int high)
{
    if(low>=high)
    return;
    int mid=low+(high-low)/2;
    merge(nums,low,mid);
    merge(nums,mid+1,high);
    vector<int>temp(high-low+1);
    int i=0,right=mid+1,left=low;
    while(left<=mid && right<=high)
    {
        if(nums[left]<=nums[right])
        temp[i++]=nums[left++];
        else
        temp[i++]=nums[right++];
    }
    while(left<=mid)
    {   
        temp[i]=nums[left];
        i++;
        left++;
    }
    while(right<=high)
    {
        temp[i]=nums[right];
        right++;
        i++;
    }
    for(int j=low,k=0;k<temp.size();k++,j++)
    nums[j]=temp[k];
}

void Q1()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        vector<int>arr;
        int n=input(arr);
        merge(arr,0,n-1);
        bool f=true;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1] == arr[i])
            {
                cout<<"YES"<<endl;
                f=false;
                break;
            }
        }
        if(f)
        cout<<"No"<<endl;
    }
}

void Q2()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        vector<int>arr;
        int n=input(arr);
        for(int j=0;j<n-1;j++)
        {
            
        }
        cout<<"Sorted array: ";
        print(arr);
    }
}

// Q3



void Q3()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        vector<int>arr;
        int n=input(arr);
        for(int j=0;j<n;j++)
        {

        }
        cout<<"Sorted array: ";
        print(arr);
    }
}

int main()
{
    Q1();
    Q2();
    Q3();
    return 0;
}