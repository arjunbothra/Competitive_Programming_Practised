#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //nodes and edges
    int n, e;
    cin >> n >> e;

    vector<int> vis(n+1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

        return 0;
}

