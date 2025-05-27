#include<bits/stdc++.h>
using namespace std;

void Q1()
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
        int t;
        cin>>t;
        bool f=true;
        for(int j=0;j<k;j++)
        {
            if(arr[j]==t)
            {   
                cout<<"Present: "<<j+1<<endl;
                f=false;
                break;
            }
        }
        if(f)
            cout<<"Not Present "<<k<<endl;
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
        int t;
        cin>>t;
        int low=0,high=k-1;
        bool f=true;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid] == t)
            {
                cout<<"Element present "<<mid;
                f=false;
                break;
            }
            else if(arr[mid]<t)
                low=mid+1;
            else
                high=mid-1;
            
        }
        if(f)
            cout<<"Not Present "<<k<<endl;
    }
}

int main()
{
    Q1();
    Q2();
    return 0;
}