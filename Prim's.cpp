#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

vector<vector<int>> primsAlgo(int n, vector<vector<pair<int, int>>> &adj){
    vector<vector<int>> mst;
    vector<int> vis(n);
    vector<int> min_cost(n, INT_MAX);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    
    min_cost[0] = 0;
    pq.push({0, 0, -1});

    while(!pq.empty()){
        auto [cost, u, p] = pq.top();
        pq.pop();

        if(vis[u])
            continue;
        vis[u]= 1;
        if(p!= - 1)
            mst.push_back({u, p, cost});

        for (auto it : adj[u])
        {
            auto [child, eW] = it;
            if(!vis[child] && eW <  min_cost[child]){
                pq.push({eW, child, u});
                min_cost[child] = eW;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n);

        auto mst = primsAlgo(n, adj);
    }
    return 0;
}

