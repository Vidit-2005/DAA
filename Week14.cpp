#include <bits/stdc++.h>
using namespace std;

bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}

int getNthUgly(int n) {
    int count = 0;
    int i = 1; 
    while (true) {
        if (isUgly(i)) {
            count++;
            if (count == n)
                return i;
        }
        
        i++;
    }
}

void Q1() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << getNthUgly(n) << endl;
    }
}

// Q2
bool check(vector<bool>visited,int V)
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}
bool find1(int v,int i,vector<vector<int>>&edges)
{
    vector<bool>vis(v,false);
    queue<int>q;
    vis[i]=true;
    q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j=0;j<v;j++)
        {
            if(edges[u][j]!=0 && !vis[j])
            {
                q.push(j);
                vis[j]=true;
            }
        }
    }

    return check(vis,v);
}
void Q2()
{
    int V;
    cin>>V;
    vector<vector<int>>edges(V,vector<int>(V));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>edges[i][j];
        }
    }
    for(int i=0;i<V;i++)
    {
        if(find1(V,i,edges))
        {
            cout<<"Mother node exists!!!!: "<<i<<endl;
            return;
        }
    }
    cout<<"Mother node not Exists!!!"<<endl;
}

int main() {
    Q2();
    return 0;
}
