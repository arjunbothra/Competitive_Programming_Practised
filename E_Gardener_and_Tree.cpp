#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int dfs(int curr, int parent, vector<int>& dist, vector<vector<int>>& adj){
    if(adj[curr].size()<= 1)
    {
        dist[curr]= 1;
    }
    for(auto it: adj[curr]){
        if(it != parent){
            dist[curr] = min(dfs(it, curr, dist, adj) + 1, dist[curr]);
        }
    }

    return dist[curr];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(n<=2){
            cout << 0 << endl;
            continue;
        }

        vector<int> dist(n, INT_MAX);
        dfs(0, -1, dist, adj);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if(dist[i]<=k)
                cnt++;
        }

        cout << n-cnt << endl;
    }
    
    return 0;
}


