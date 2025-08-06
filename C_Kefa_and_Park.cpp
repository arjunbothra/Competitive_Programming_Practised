#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int n, m;

void dfs(int curr, int parent,  int cnt, int& possible, vector<int>& a, vector<vector<int>>& adj){
    if(a[curr]==1)
        cnt++;
    else
        cnt = 0;
    
    if (cnt > m)
        return;

    if(adj[curr].size()<=1 && curr!= 0)
        possible++;
    
    for (auto it : adj[curr])
    {
        if(it != parent)
        dfs(it, curr, cnt, possible, a, adj);
    }

    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

        
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
           
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int cnt = 0, possible=0;
        dfs(0, -1, cnt, possible, a, adj);

        cout << possible << endl;
        return 0;
}

