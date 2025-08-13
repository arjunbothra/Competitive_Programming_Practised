#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int dfs(int curr, int parent, vector<vector<int>>& adj, vector<int>& subTreeCheck, vector<int>& roads){
    if(roads[curr] == 1)
        subTreeCheck[curr]++;
    
    for(auto it: adj[curr]){
        if(it != parent){
            subTreeCheck[curr]+= dfs(it, curr, adj, subTreeCheck, roads);
        }
    }
    return subTreeCheck[curr];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<int> roads(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, t;
            cin >> u >> v >> t;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(t==2){
                roads[u]=1;
                roads[v] =1;
            }
        }

        vector<int> subTreeCheck(n);
        dfs(0, -1, adj, subTreeCheck, roads);
        vector<int> ans;

        for (int i = 0; i < n; ++i){
            if(subTreeCheck[i]==1){
                ans.push_back(i + 1);
            }
        }

        cout << ans.size() << endl;
        for(auto it: ans)
            cout << it << " ";
        return 0;
}



