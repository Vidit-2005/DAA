#include<bits/stdc++.h>
using namespace std;

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
            cout << path[j];
            if (j != path.size() - 1) cout << " -> ";
        }
        cout << "\n\n";
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

int main()
{
    Q1();
    return 0;
}