
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, roads, g, k;
    cin >> n >> roads >> g >> k;
    vector<vector<int>> goods(g);
    // take goods input;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        goods[a - 1].push_back(i);
    }

    // adjacency list;
    vector<vector<int>> adj(n);
    for (int i = 0; i < roads; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> cost(n, vector<int>(g));
    for (int goodType = 0; goodType < g; goodType++)
    { // goods vector good-1 ,2, 3, 4, 5........
        queue<int> q;
        vector<int> dist(n, INT_MAX);  //to track distance of each node for good type
        for (auto it: goods[goodType]){
            q.push(it);
            dist[it] = 0;
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child: adj[node]){
                if(dist[child]>dist[node]+1){
                    dist[child] = dist[node]+1;
                    q.push(child);
                }
            }
        }

        for (int j = 0; j < n; ++j){
            cost[j][goodType]=dist[j];
        }
    }
    //debug
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        sort(cost[i].begin(), cost[i].end());

        for (int jj = 0; jj < k; jj++)
            sum += cost[i][jj];

        ans[i] = sum;
    }

    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

