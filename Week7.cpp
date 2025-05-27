#include<bits/stdc++.h>
using namespace std;

// Q1

void dis(vector<vector<int>>edges,int V,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    vector<bool>isin(V,false);
    vector<int>currw(V,INT_MAX);
    vector<int>parent(V,-1);
    currw[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        if(isin[node.second]) continue;
        isin[node.second]=true;

        for(int i=0;i<V;i++)
        {
            int weight=edges[node.second][i];
            int vertex=i;
            if(weight+currw[node.second]<currw[vertex] && weight!=0)
            {
                currw[vertex] = weight+currw[node.second];
                parent[vertex]=node.second;
                pq.push({currw[vertex],vertex});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << ": " << currw[i] << "\n";
        if (currw[i] == INT_MAX) {
            cout << "No path exists\n";
            continue;
        }
        cout << "Path: ";
        vector<int> path;
        for (int v = i; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(),path.end());
        for (int j = 0; j < path.size(); j++) {
            cout << " -> "<< path[j];
        }
        cout <<endl;
    }
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
    int src;
    cin>>src;
    dis(edges,V,src);
}

// Q2

void bell(int src,vector<vector<int>>&edges,int V)
{
    vector<int>dis(V,INT_MAX);
    vector<int>parent(V,-1);
    dis[src]=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(edges[i][j]!=0 && dis[i] != INT_MAX && dis[i]+edges[i][j] < dis[j])
            {
                dis[j]=dis[i]+edges[i][j];
                parent[j]=i;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << ": " << dis[i] << "\n";
        if (dis[i] == INT_MAX) {
            cout << "No path exists\n";
            continue;
        }
        cout << "Path: ";
        vector<int> path;
        for (int v = i; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(),path.end());
        for (int j = 0; j < path.size(); j++) {
            cout << " -> "<< path[j];
        }
        cout <<endl;
    }
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
    int src;
    cin>>src;
    bell(src,edges,V);
}

int main()
{
    Q2();
    return 0;
}