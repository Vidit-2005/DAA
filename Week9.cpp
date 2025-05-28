#include<bits/stdc++.h>
using namespace std;
// Q1
void fwd(vector<vector<int>>&edges,int V)
{
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(edges[i][k]!=INT_MAX && edges[k][j]!=INT_MAX)
                {
                    edges[i][j]=min(edges[i][j],edges[i][k]+edges[k][j]);
                }
            }
        }
    }
}
void Q1()
{
    int V;
    cin >> V;
    vector<vector<int>> edges(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string val;
            cin >> val;
            if (val == "INF")
                edges[i][j] = INT_MAX;
            else
                edges[i][j] = stoi(val);
        }
    }
    fwd(edges,V);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(edges[i][j] == INT_MAX)
                cout<<"INF"<<" ";
            else    
                cout<<edges[i][j]<<" ";
        } 
        cout<<endl;
    }
}

// Q2
void knap(vector<vector<double>>&in,int n,int mx)
{
    double profit=0;
    for(int i=0;i<n;i++)
    {
        if(mx<in[i][1])
        {
            profit += (mx*in[i][0]);
            break;  
        }
        else
        {
            profit+=(in[i][2]);
            mx-=in[i][1];
        }
    }
    cout<<"Profit= "<<profit<<endl;
}
void Q2()
{
    int n;
    cin>>n;
    double t;
    vector<vector<double>>in(n);
    vector<vector<double>>temp;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        in[i].push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>t;
        in[i].push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        double frac=(double)in[i][1]/in[i][0];
        temp.push_back({frac,in[i][0],in[i][1]});
    }
    sort(temp.rbegin(),temp.rend());
    int mx;
    cin>>mx;
    knap(temp,n,mx);
}

int main()
{
    Q2();
    return 0;
}