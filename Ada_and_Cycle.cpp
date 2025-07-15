#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n;
int bfs(int node, vector<vector<int>> &adj)
{
    vector<int> vis(n, 0);
    queue<pair<int, int>> q; //node, dist
    q.push({node, 0});
    
    while (!q.empty())
    {
        auto [curr, dist]= q.front();
        q.pop();
        
        for(auto child: adj[curr]){
            if(!vis[child]){
                if(child == node) return dist + 1;
                q.push({child, dist + 1});
                vis[child] = 1;
            }
        }
    }
    return INT_MAX;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int u;
            cin >> u;
            if (u == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; ++i){
        int ans=bfs(i, adj);
        if(ans!= INT_MAX)
            cout << ans << endl;
        else
            cout << "NO WAY" << endl;
    }
}
