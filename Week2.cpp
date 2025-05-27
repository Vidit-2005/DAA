#include<bits/stdc++.h>
using namespace std;

void Q1(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int j=0;j<k;j++)
        {
            cin>>arr[j];
        }
        int t;
        cin>>t;
        int low=0,high=k-1;
        bool f=true;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid] >= t)
            {
                f=false;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        int l=low;
        low=0,high=k-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid] <= t)
            {
                f=false;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        if(f)
            cout<<"Element not presenmt"<<endl;
        else
            cout<<"Number of copies= "<<high-l+1<<endl;
    }
}

void Q2()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int j=0;j<k;j++)
        {
            cin>>arr[j];
        }
        
    }
}

void Q3()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int j=0;j<k;j++)
        {
            cin>>arr[j];
        }
        int diff;
        cin>>diff;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
            mp[arr[i]]++;
        int count=0;
        for(auto it:mp)
        {
            if(mp.find((it.first + diff))!=mp.end())
                count++;
        }
        cout<<"Number of pair: "<<count<<endl;
    }
}

int main()
{
    Q1();
    Q2();
    Q3();
    return 0;
}