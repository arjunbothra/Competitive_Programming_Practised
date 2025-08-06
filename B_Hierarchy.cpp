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
        vector<int> quali(n);
        vector <vector<pair<int, int>>> adj(n);     // { { {},{} }, {}, {} }
        for (int i = 0; i < n; ++i){                //   {    0  }, {1}, {2}
            cin >> quali[i];
        }
       
        
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int u, v, wt;
            cin >> u >> v >> wt;
            u--;
            v--;
            adj[v].push_back({wt, u});
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (adj[i].size() == 0)
                cnt++;

        if(cnt >1)
            cout << -1 << endl;
        else{
            int ans = 0;
            for (int i = 0; i < n; ++i)
            {
                if (adj[i].size())
                {
                    sort(adj[i].begin(), adj[i].end());
                    ans += adj[i][0].first;
                }
            }

            cout << ans << endl;
        }
        return 0;
}



