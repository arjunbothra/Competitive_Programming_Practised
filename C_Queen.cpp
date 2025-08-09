#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//always read question carefully and prove your answer

vector<int> ans;
void dfs(int curr, vector<vector<int>> &adj, vector<int> &c)
{
    bool flag = true;
    for (auto child : adj[curr])
    {
        if(c[child]!= 1) flag = false;
        dfs(child, adj, c);
    }

    if(flag== true && c[curr] == 1)
        ans.push_back(curr);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> c(n, 0);
    int root = -1;
    for (int i = 0; i < n; ++i)
    {
        int p, r;
        cin >> p >> r;
        if(p!= -1){
            p--;
            adj[p].push_back(i);
            c[i] = r;
        }
        else
            root = i;
    }

    // for (int it = 0; it < n; ++it)
    // {
    //     cout << "Curr " << it+1 << ": ";
    //     for (auto i : adj[it])
    //     {
    //         cout << i+1 << " ";
    //     }
    //     cout << endl;
    // }

    // for (auto it: c)
    //     cout << it << endl;

    dfs(root, adj, c);
    if(ans.size()!= 0){
        sort(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it+1 << " ";
    }
    

    else
        cout << -1 << endl;
    return 0;
}

