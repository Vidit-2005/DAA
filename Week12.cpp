#include<bits/stdc++.h>
using namespace std;

// Q1 recursion
/*string check(string s1,string s2,int i,int j)
{
    if(i<0 || j<0)
        return  "";
    if(s1[i] == s2[j])
    {
        return check(s1,s2,i-1,j-1)+s1[i];
    }else{
        string a = check(s1,s2,i,j-1);
        string b = check(s1,s2,i-1,j);
        return (a.size()>b.size())?a:b;
    }
    
}*/

//Memoization
string check(string s1,string s2,int i,int j,vector<vector<string>>&dp)
{
    if(i<0 || j<0)
        return  "";
    if(dp[i][j]!="") return dp[i][j];
    if(s1[i] == s2[j])
    {
        dp[i][j]=check(s1,s2,i-1,j-1,dp)+s1[i];
    }else{
        string a = check(s1,s2,i,j-1,dp);
        string b = check(s1,s2,i-1,j,dp);
        dp[i][j]=(a.size()>b.size())?a:b;
    }
    return dp[i][j];
    
}
void Q1()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<vector<string>>dp(s1.size(),vector<string>(s2.size(),""));
    string ans=check(s1,s2,s1.length()-1,s2.length()-1,dp);
    cout<<"Longest subsequence is: "<<ans<<endl;
    cout<<"length= "<<ans.size();
}

// Q2
void knap(vector<pair<int,int>>&wv,int i,int c,vector<pair<int,int>>&p)
{
    if(c==0)
    {
        p.push_back({wv[i-1]});
    }
    if(i>wv.size()-1 || c<0)
        return;
    if(c<wv[i].first)
        knap(wv,i+1,c,p);
    knap(wv,i+1,c-wv[i].first,p);
}
void Q2()
{
    
}

// Q3
void per(string s1,set<string>&s,string s2,int i)
{
    if(s2.size() == s1.size())
    {
        s.insert(s2);
        return;
    }    
    if(i==s1.size())
        return;
    for (int j = 0; j < s1.size(); j++) {
        if (s1[j] != '*') {
            char ch = s1[j];
            s1[j] = '*';
            per(s1, s, s2 + ch, i + 1);
            s1[j] = ch;
        }
    }
}
void Q3()
{
    string s1;
    cin>>s1;
    set<string>s;
    string s2="";
    per(s1,s,s2,0);
    for(auto i:s)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    Q3();
    return 0;
}