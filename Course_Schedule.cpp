#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n>> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (int i = 0; i <m ; ++i)
    {
        int u, v;
        cin >> u >>  v;
        u--;
        v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    // vector<int> vis(n);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < n; ++i){
        if(indeg[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }

    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto it: adj[node]){
            int child = it;
            indeg[child]--;
            if (indeg[child]==0){
                q.push(child);
                ans.push_back(child);
            }
        }
    }

    if(ans.size()== n){
        for (auto it: ans)
            cout << it+1 << " ";
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

