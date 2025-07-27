#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool peak = false;
        if (adj[i].size() == 0)
            peak = true;

        else
        {
            for (auto it : adj[i])
            {
                if (adj[i] <= adj[it])
                    peak = true;
            }
        }
        if (peak)
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
