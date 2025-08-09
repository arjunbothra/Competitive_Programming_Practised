#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


//always read question carefully and prove your answer

// void dfs(int curr, int parent, vector<int>& dist, vector<vector<int>>& adj){
//     if(adj[curr].size()<= 1)
//     {
//         dist[curr]= 1;
//     }

//     for(auto it: adj[curr]){
//         if(it != parent){
//             dfs(it, curr, dist, adj);
//             dist[curr] = min(dist[it] + 1, dist[curr]);
//         }
//     }
// }

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
        vector<int> indeg(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }

        if(n<=2){
            cout << 0 << endl;
            continue;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if(indeg[i] <= 1)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty() && k--){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                int node = q.front();
                q.pop();
                cnt++;
                for (auto it : adj[node]){
                    indeg[it]--;
                    if(indeg[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        cout << n-cnt << endl;
    }
    
    return 0;
}


