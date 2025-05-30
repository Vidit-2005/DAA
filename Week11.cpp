#include<bits/stdc++.h>
using namespace std;

// Q2
int coin(vector<int>&coins,int N,int n,vector<vector<int>>&sum)
{
    if(N == 0 )
    {
        return 1;
    }
    if(n<0 || N<0)
        return 0;
    
    if(sum[N][n]!=-1) return sum[N][n];
    int l=0,r=0;
    if(N>=coins[n])
        l=coin(coins,N-coins[n],n,sum);
    r=coin(coins,N,n-1,sum);
    sum[N][n]=l+r;
    return sum[N][n];
}
void Q2()
{
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    int N;
    cin>>N;
    vector<vector<int>>sum(N+1,vector<int>(n+1,-1));
    
    cout<<coin(coins,N,n-1,sum)<<endl;
}

// Q3
bool check(vector<int>arr,int i,int s,vector<vector<int>>&dp)
{
    if(s == 0)
        return true;
    if(s<0 || i<0)
        return false;
    if(dp[s][i]!=-1) return dp[s][i];
    return dp[s][i]=(check(arr,i-1,s-arr[i],dp) || check(arr,i-1,s,dp));
}

void Q3()
{
    int n;
    cin>>n;
    int sum=0;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
       cout<<"NO";
       return;
    }
    vector<vector<int>>dp(((sum/2)+1),vector<int>(n,-1));
    if(check(arr,n-1,sum/2,dp))
        cout<<"YEs";
    else
        cout<<"NO";
}

int main()
{
    Q3();
    return 0;
}