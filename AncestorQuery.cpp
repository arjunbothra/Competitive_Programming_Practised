#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


//For trees problems never think storing the ancestors and children
void dfs(int curr, int parent, int& time, vector<vector<int>>& adj, vector<int>& inTime, vector<int>& outTime){
    time++;
    inTime[curr] = time;
    for (auto it : adj[curr])
    {
        if (it != parent)
        {
            dfs(it, curr, time, adj, inTime, outTime);
        }
    }

    time++;
    outTime[curr] = time;
}

bool query(int X, int Y, vector<int>& inTime, vector<int>& outTime){
   if(inTime[Y] < inTime[X] && outTime[Y] > outTime[X])
       return true;

   return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> inTime(n, -1), outTime(n, -1);
        int time = 0;
        dfs(0, -1, time, adj, inTime, outTime);
        // for(auto it: inTime)
        //     cout << it << " ";

        // cout << endl;
        // for(auto it: outTime)
        //     cout << it << " ";
        // cout << endl;
        
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i){
            int X, Y;
            cin >> X >> Y;
            if (query(X, Y, inTime, outTime))
            cout << "Yes" << endl;
            else
            cout << "No" << endl;
        }
            return 0;
}

