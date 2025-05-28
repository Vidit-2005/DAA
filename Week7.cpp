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
    for(int k=0;k<V-1;k++)
   {
       int c=0;
       for(int i=0;i<V;i++)
       {
            for(int j=0;j<V;j++)
            {
                if(edges[i][j]!=0 && dis[i] != INT_MAX && dis[i]+edges[i][j] < dis[j])
                {
                   dis[j]=dis[i]+edges[i][j];
                   parent[j]=i;
                   c++;
                }
            }
        }
        if(!c)
            break;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (edges[i][j] != 0 && dis[i] != INT_MAX && dis[i] + edges[i][j] < dis[j]) {
                cout << "Negative weight cycle detected.\n";
                return;
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
            cout << " -> "<< path[j]+1;
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

// Q3
pair<int,bool> pa(int src,int des,int k,vector<vector<int>>&edges)
{
    if (k == 0) {
        if (src == des) return {0, true};
        else return {INT_MAX, false};
    }
    
    int minWeight = INT_MAX;
    bool found = false;

    for (int v = 0; v < edges.size(); v++) {
        if (edges[src][v] != 0) {
            pair<int, bool> res = pa(v, des, k - 1, edges);
            if (res.second && res.first != INT_MAX) {
                minWeight = min(minWeight, edges[src][v] + res.first);
                found = true;
            }
        }
    }
    return {minWeight, found};
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
    int src,des;
    cin>>src>>des;
    int k;
    cin>>k;
    pair<int,bool>temp=pa(src,des,k,edges);
    if(temp.second)
    {
        cout << "Weight of shortest path from (" << src << " , " << des << ") with " << k << " edges: " << temp.first << endl;
    }
    else{
        cout<<"Path don't exist's!!!"<<endl;
    }
}

int main()
{
    Q1();
    Q2();
    Q3();
    return 0;
}