#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


// int dfs(int curr, int parent, int size, bool flag, vector<vector<int>>& adj){
//     if(flag == false)
//         return;
//     int cnt = 0;
//     int size = 1;
//     for (auto it : adj[curr])
//     {
//         if(it != parent){
//             if(dfs(it, curr, size, flag, adj) == 1) cnt++;
//         }
//     }
//     if(cnt <3)
//         flag = false;

//     return size;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
        int n;
        cin >> n;
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++){
            int u;
            cin >> u;
            u--;
            adj[u].push_back(i);

        }

        bool flag = true;

        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i){
            if(flag == false)
                break;
            if (adj[i].size() != 0 && !vis[i])
            {
                int cnt = 0;
                for (auto it : adj[i])
                {
                    if(adj[it].size()==0){
                        cnt ++ ;
                        vis[it] = 1;
                    }
                }
                if (cnt < 3){
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

            return 0;
}

