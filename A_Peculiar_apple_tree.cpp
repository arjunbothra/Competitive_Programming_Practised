#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
// always read question carefully and prove your answer

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        int p;
        cin >> p;
        adj[p].push_back(i+2);
        // adj[i+2].push_back(p);
    }

    // for (int i = 0; i < n; ++i){
    //     cout << "Curr : " << i << " ";
    //     for(auto it: adj[i])
    //         cout << it << " ";
    //     cout << endl;
    // }

    queue<int> q;
    vector<int> vis(n+1, 0);
    q.push(1);
    vis[1] = 1;
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        if(size % 2 ==1)
            level++;

        for (int i = 0; i < size; ++i)
        {
            int curr = q.front();
            q.pop();
            for (auto it : adj[curr])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    cout << level << endl;
    return 0;
}
