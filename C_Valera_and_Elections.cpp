#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

   
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indeg(n, 0), vis(n, 0), road(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, t;
            u--;
            v--;
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
            indeg[u]++;
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if(indeg[i]==1)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                bool exist = false, flag= false;
                auto neighbour= it.first  ;
                auto damaged= it.second;
                if (damaged == 2 && !vis[neighbour])
                    flag = true;
                if(road[neighbour]){
                    exist = true;
                }
                if(!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }

                if(flag && !exist){
                     ans.push_back(curr);
                     road[curr] = 1;
                }
            }
        }

        cout << ans.size() << endl;
        for(auto it: ans)
            cout << it << " ";
        return 0;
}

