#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int clr[] = {0, 0};

void dfs(int node,int parent, vector<vector<int>> &adj, int color)
{
    clr[color]++;
    
    for (auto it : adj[node])
    {
        if (it!= parent)
        {
            dfs(it, node, adj, !color);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    int cnt1 = 0, cnt0 = 0;
    dfs(1, 1, adj, 0);

    
    cout << clr[0]*clr[1] - (n - 1) << endl;
    return 0;
}


