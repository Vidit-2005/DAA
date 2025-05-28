#include<bits/stdc++.h>
using namespace std;

// Q1
void prims(vector<vector<int>>edges,int V)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    vector<int>key(V,INT_MAX);
    vector<bool>inMST(V,false);
    vector<int>parent(V,-1);
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        int u=node.second;
        if(inMST[u]) continue;
        inMST[u]=true;
        for(int v = 0; v < V; v++)
        {
            if(edges[u][v] != 0 && !inMST[v] && edges[u][v] < key[v])
            {
                key[v] = edges[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    int totalWeight = 0;
    for(int i = 0; i < V; i++) {
        if (key[i] != INT_MAX) totalWeight += key[i];
    }
    cout << "Total weight of MST: " << totalWeight << endl;
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
    prims(edges,V);
}

int main()
{
    Q1();
    return 0;
}