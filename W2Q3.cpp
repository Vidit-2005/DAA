#include<bits/stdc++.h>
using namespace std;
int fund(vector<int>num,int k)
{
    unordered_map<int,int>mp;
    for(int i=0;i<num.size();i++)
        mp[num[i]]++;
    int count=0;
    for(int i=0;i<num.size();i++)
    {
        if(mp.find(num[i]+k)!=mp.end())
            count++;
    }
    return count;
}
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n;
        cin>>n;
        vector<int>num;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            num.push_back(temp);
        };
        int target;
        cin>>target;
        cout<<"psotion: "<<fund(num,target)<<endl;
    }
    return 0;
}
