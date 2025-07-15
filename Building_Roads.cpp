#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //nodes and edges
    int n, e;
    cin >> n >> e;

    vector<int> vis(n+1, 0);
    vector<vector<int>> adj(n + 1);
    vector<int> call;
    //input
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    //call dfs for each node
    for (int i = 1; i < n + 1; ++i)
    {   
        if(!vis[i]){
            cnt++;
            dfs(i, adj, vis);
            call.push_back(i);
        }
    }
    
    cout << cnt - 1 << endl;
    
    if((cnt-1) != 0){
        int prev = 1;
        for (int i = 1; i < call.size(); i++)
        {
            cout << prev << " " << call[i] << endl;
            prev = call[i];
        }
    }

    return 0;
}

