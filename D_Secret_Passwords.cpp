#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child, node, adj, vis);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 26);
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(auto ch: s){
            adj[i].push_back((ch-'a')+n);
            adj[(ch - 'a') + n].push_back(i);
        }
    }
    vector<int> vis(n + 26, 0);
    int cnt = 0;
    for (int i = 0; i < n + 26; i++){
        if(!vis[i] && adj[i].size()>0){
            dfs(i, -1, adj, vis);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}


