#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

bool dfs(int curr, int parent, vector<vector<int>>& adj, vector<int>& color, int mainNode){
    bool ans = true;

    if(parent!= mainNode && color[curr] != color[parent])
        return false;
    for (auto it : adj[curr])
    {
        if(it!= parent)
        ans = ans & dfs(it, curr, adj, color, mainNode);
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> color(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i){
        cin >> color[i];
    }

        for (auto it : edges)
        {
            int u = it.first;
            int v = it.second;
            if (color[u]!= color[v])
            {
                bool flag1 = true, flag2 = true, ans = true;

                for (auto i : adj[u])
                { // check for 'u' if all subtree nodes have the same color
                        if(i != v){
                            if(color[i] != color[u]) flag1 = false;  
                            ans =ans& dfs(i, u, adj, color, u);
                        }
                }
                if(!ans){
                    cout << "NO" << endl;
                    return 0;
                }

                for(auto i: adj[v]){
                    if(i!= u){
                        if(color[i] != color[v])
                            flag2 = false;

                        ans = ans & dfs(i, v, adj, color, v);
                    }
                }
                if(!ans){
                    cout << "NO" << endl;
                    return 0;
                }
                if(!flag1 && !flag2){
                    cout << "NO" << endl;
                }
                if(flag1){
                    cout << "YES" <<endl;
                    cout << v + 1 << endl;
                    return 0;
                }
                else {
                    cout << "YES" << endl;
                    cout << u + 1 << endl;
                    return 0;
                }
            }
        }

        cout << "YES" << endl;
        cout << 1 << endl;

        return 0;
}

