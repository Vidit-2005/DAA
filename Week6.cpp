#include <bits/stdc++.h>
using namespace std;

// Q1
bool dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res,int des)
{

    visited[s] = true;

    res.push_back(s);
    if(s==des) return true;
    for(int j=0;j<adj.size();j++)
    {
        if (adj[s][j] == 1 && visited[j] == false)
            if( dfsRec(adj, visited, j, res,des)) return true;
    }
    res.pop_back();
    return false;
}

void DFS(vector<vector<int>> &adj,int src,int dis)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    if(dfsRec(adj, visited, src, res,dis))
    {
        cout<<"YES,PATH EXISTS";
        for(auto it:res)
            cout<<"->"<<it;
    }
    else    
        cout<<"No Such Path Exists";
    cout<<endl;
}

void Q1()
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
    int src,dis;
    cin>>src>>dis;
    DFS(edges,src,dis);
}

// Q2

bool isBipartite(vector<vector<int>>edges,int V)
{
    vector<int>color(V,-1);
    for(int start=0;start<V;start++)
    {
        if(color[start] == -1)
        {
            queue<int> q;
            q.push(start);
            color[start]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int neg=0;neg<V;neg++)
                {
                    if(edges[node][neg] == 1)
                    {
                        if(color[neg] == -1)
                        {
                            color[neg]=1-color[node];
                            q.push(neg);
                        }
                        else if(color[neg] == color[node])
                            return false;
                    }
                }
            }
        } 

    }
    return true;
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
    if (isBipartite(edges, V))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";   
}

// Q3
bool hasCycle(vector<vector<int>>&edges,int V)
{  
    vector<int> in(V,0);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(edges[i][j]==1)
                in[j]++;
        }
    }

    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(in[i]==0)
            q.push(i);
    }

    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        
        for(int neg=0;neg<V;neg++)
        {
            if(edges[node][neg] == 1)
            {
                in[neg]--;
                if(in[neg] == 0)
                    q.push(neg);
            }
        }
    }
    return count!=V;
}

void Q3()
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
    if (hasCycle(edges, V))
        cout << "Graph has cycle\n";
    else
        cout << "Graph Not have Cycle\n";   
}


int main()
{
    cout<<"QUESTION_1 (DFS)"<<endl;
    Q1();
    cout<<"QUESTION_2 (BFS)"<<endl;
    Q2();
    cout<<"QUESTION_3 "<<endl;
    Q3();
    return 0;
}