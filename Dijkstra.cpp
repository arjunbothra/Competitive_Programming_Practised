#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        vector<pair<int, int>> adj(n);

        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        // for (int i = 0; i < m; ++i){
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     int c = edges[i][2];
        // }

        // int src = 0;
        // vector<int> dist(n, INT_MAX);
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // pq.push({0, src});

        // //dijkstra main
        // while(!pq.empty()){
        //     auto [cost, node] = pq.top();
        //     pq.pop();

        //     if(cost > dist[node])
        //         continue;
            
        //     for(auto it: adj[node])
        //             int w = it.first;
        //             int child =it.second;
        //
        //             if(w+dist[node] < dist[child]){
        //                 dist[child] = w + dist[node];
        //                 pq.push({dist[child], child});
        //             }
        // }



    }
    return 0;
}

