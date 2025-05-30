#include<bits/stdc++.h>
using namespace std;

// Q1
bool compair(vector<int>a,vector<int>b)
{
    return a[1]<b[1];
}
void activity(vector<vector<int>>&se)
{
    int count=1;
    int end=se[0][1];
    vector<int>sel;
    sel.push_back(1);
    for(int i=1;i<se.size();i++)
    {
        if(se[i][0]>=end)
        {
            count++;
            end=se[i][1];
            sel.push_back(i+1);
        }
    }
    cout<<"No. of non-conflicts activity: "<<count<<endl<<"List of selected activities: ";
    for(int i=0;i<sel.size();i++)
        cout<<sel[i]<<" ";
    cout<<endl;
}
void Q1()
{
    int n;
    cin>>n;
    vector<vector<int>>se(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>se[i][0];
    for(int i=0;i<n;i++)
        cin>>se[i][1];
    sort(se.begin(),se.end(),compair);
    activity(se);
}

// Q2
void Q2()
{
    
}

// Q3
void Q3()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count=1;
    int ele=arr[0];
    for(int i=1;i<n;i++)
    {
        if(count==0)
            ele=arr[i];
        if(ele!=arr[i])
            count--;
        else
            count++;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
            c++;
    }
    if(c>n/2)
        cout<<"YEs";
    else
        cout<<"no";
}

int main()
{
    Q3();
    return 0;
}