#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component){
    vis[node] = 1;
    component.push_back(node);
    for (auto child : adj[node])
    {
        if(!vis[child]){
            dfs(child,adj, vis, component);
        }
    }  
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; 
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int size;
        cin>> size;
        vector<int> group(size);
        // cout << "Size: " << size << endl;
        for (int j = 0; j < size; ++j)
        {
            cin >> group[j];
            group[j]--;
            if (j != 0)
            {
                adj[group[j]].push_back(group[j - 1]);
                adj[group[j - 1]].push_back(group[j]);
                // cout << group[j] << " " << group[j - 1] << endl;
            }
        }
    }

    vector<int> ans(n);
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i){
        vector<int> component;
        if (!vis[i])
        {
            dfs(i, adj, vis, component);
        }
        for(auto it: component){
            ans[it] = component.size();
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    
        cout << endl;

        return 0;
}

