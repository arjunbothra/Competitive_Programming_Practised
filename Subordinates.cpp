#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//always read question carefully and prove your answer

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& count){
    count[node] = 1;
    for(auto child: adj[node]){
        if(child != parent){
            dfs(child, node, adj, count);
            count[node] += count[child];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i){
        int u;
        cin >> u;
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }


    vector<int> count(n, 0);
    dfs(0, -1, adj, count);

    for(auto it: count)
        cout << it-1 << " ";
    return 0;
}

