#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//always read question carefully and prove your answer

bool dfs(int node, vector<set<int>>& adj, vector<int>& vis){
    vis[node] = 2;

    for(auto child: adj[node]){
        if(vis[child] == 0){
           if (!dfs(child, adj, vis)) return false;
        }
        else if(vis[child]==2)
            return false;
    }
    vis[node] = 1;
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<set<int>> adj(n);
        for (int i = 0; i < k; ++i)
        {   
            vector<int> groups;
            for (int j = 0; j < n; ++j){
                int u;
                cin >> u;
                u--;
                groups.push_back(u);
                if (j > 1)
                {
                    if(adj[groups[j-1]].find(groups[j]) == adj[groups[j-1]].end())
                            adj[groups[j - 1]].insert(groups[j]);
                }
            }               
        }

        // for (int i = 0; i < n; ++i){
        //     cout << "Node" << " " << i+1 << ": ";
        //     for(auto it: adj[i]){
        //         cout << it+1 << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;


        vector<int> vis(n, 0);
        bool cycle = false;
        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, adj, vis)==false)
                {
                    cycle = true;
                    break;
                }
            }
    }

    if(cycle==true)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    }
    

        return 0;
}

