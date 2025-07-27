#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
//use long long here

vector<int> dijkstra(int src, int n, vector<int> &parent, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(n, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int final = n - 1;
    dist[src] = 0;
    pq.push({0, src});

    // dijkstra main
    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (node == final)
            break;

        if (cost > dist[node])
            continue;

        for (auto it : adj[node])
        {
            int w = it.second;
            int child = it.first;
            if (w + dist[node] < dist[child])
            {
                // if(child == n)
                //     cout << "logger" << endl;
                parent[child] = node;
                dist[child] = w + dist[node];
                pq.push({dist[child], child});
            }
        }
    }
    return dist;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> parent(n, -1);
    vector<int> distances = dijkstra(0, n, parent, adj);


    if(distances[n-1] == LLONG_MAX)
        cout << -1 << endl;
    else{
        int x= n-1;
        vector<int> ans;
        while (x != -1)
        {
            ans.push_back(x + 1);
            x = parent[x];
        }
        reverse(ans.begin(), ans.end());
        for(auto it: ans)
            cout << it << " ";
        
    }

    return 0;
}
