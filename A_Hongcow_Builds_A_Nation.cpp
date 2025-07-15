#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


void dfs(int node, int& cnt, bool& flag, vector<vector<int>>& adj, vector<int>& vis, map<int, bool>& mpp){
    flag = flag || mpp[node];
    cnt++;
    vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child, cnt, flag, adj, vis, mpp);
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int n, m, k;
    cin >> n >> m >> k;
    map<int, bool> mpp;

    for (int i = 0; i < k; ++i){  //mark the gov nodes true
        int g;
        cin >> g;
        g--;
        mpp[g] = true;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans1, ans2, vis(n, 0);

    for (int i = 0; i < n; ++i){
        if(!vis[i]){
            bool flag = false;
            int cnt=0;
            dfs(i, cnt, flag, adj, vis, mpp);
            if(flag){
                ans1.push_back(cnt);
            }
            else{
                ans2.push_back(cnt);
            }
        }
    }

    int maxi= *max_element(ans1.begin(), ans1.end());

    for(auto& it: ans1){
        if(it== maxi){
            for(auto it2: ans2){
                it += it2;
            }
            break;
        }
    }

    int total = 0;
    for(auto& it: ans1){
        // cout << it << " ";
        total += (it * (it - 1)) / 2;
    }

    cout << total - m << endl;
    return 0;
}

