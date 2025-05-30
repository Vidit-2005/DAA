#include<bits/stdc++.h>
using namespace std;
// Q1
void Q1()
{
    int n;
    cin>>n;
    vector<char>s(n);
    map<char,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        mp[s[i]]++;
    }
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
    
}

// Q2
bool check(map<int,int>mp)
{
    for(auto it:mp)
    {
        if(it.second > 1)
           return false;
    }
    return true;
}
void Q2()
{
    int x,n,k;
    cin>>x;
    while(x--)
    {
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        
        bool f=true;
        
        for(int l=0;l<=n-k;l++)
        {
            map<int ,int>mp;
            for(int k1=l;k1<l+k;k1++)
                mp[arr[k1]]++;
            f=check(mp);
            if(f)
            {
                cout<<"Duplicate not present in window: "<<k<<endl;
                f=true;
                break;
            }
        }
        
        if(!f)
            cout<<"Duplicate present in window: "<<k<<endl;
    }
}

// Q3
bool findEqualProductPairs(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, pair<int, int>> productMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];

            if (productMap.find(prod) != productMap.end()) {
                
                auto p = productMap[prod];
                int x=p.first;
                int y=p.second;
                if (x != i && x != j && y != i && y != j) {
                    cout << "Found pairs: (" << arr[i] << ", " << arr[j] << ") and ("
                         << arr[x] << ", " << arr[y] << ")" << endl;
                    return true;
                }
            } else {
                productMap[prod] = {i, j};
            }
        }
    }

    cout << "No such pairs found." << endl;
    return false;
}
void Q3()
{
    vector<int> arr = {2, 3, 4, 6, 1};
    findEqualProductPairs(arr);

}

int main()
{
    Q3();
    return 0;
}