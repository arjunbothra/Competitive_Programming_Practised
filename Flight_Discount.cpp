#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

vector<int> dsource(int src, int final, int n, vector<vector<pair<int, int>>> & adj){
        vector<int> dist(n, LLONG_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        dist[src] = 0;

        //dijkstra main
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node])
                continue;
            
            for(auto it: adj[node]){
                int w = it.second;
                int child =it.first;
                    if(w+dist[node] < dist[child]){
                        dist[child] = w + dist[node];
                        pq.push({dist[child], child});
                    }
            }
        }
        return dist;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        vector <vector<pair<int, int>>> adj2(n);
       
        for (int i = 0; i < m; ++i)
        {
            int u, v, w; 
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj2[v].push_back({u, w});

        }
        vector<int> srcToDestination= dsource(0, n-1, n, adj);
        vector<int> nodeToDestination = dsource(n - 1, 0, n, adj2);

        
        int ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) //check minimum answers
        {
            if(adj[i].size()==0)
                continue;
                
            for(auto it: adj[i]){
                int v = it.first;
                int w = it.second;
                w = w / 2;
                if (srcToDestination[i] != LLONG_MAX && nodeToDestination[v] != LLONG_MAX)
                ans = min(ans, srcToDestination[i] + w + nodeToDestination[v]);
            }
        }

        cout << ans << endl;
        return 0;
}
