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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        // int product = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            // product*=v[i];
        }

        vector<int> prefix;
        vector<int> suffix = {1};
        int p = 1;
        for (int i = 0; i < n; i++)
        {

            p = v[i] * p;
            // int s = product / p;
            // cout << "P: " << p << " S: "<< s << endl;
            prefix.push_back(p);
            // suffix.push_back(s);
        }

        int s = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            s *= v[i+1];
            suffix.push_back(s);
        }

        reverse(suffix.begin(), suffix.end());

        int k = -1;
        for (int i = 0; i < n; ++i)
        {
            if (suffix[i] == prefix[i])
                {
                    k = i;
                    break;
                }

            // cout << " Prefix: " << prefix[i];
            // cout << " Suffix: " << suffix[i];
            // cout << endl;
        }
        // cout << endl;
        if(k==-1)
            cout << -1 << endl;
        else cout << k + 1 << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//always read question carefully and prove your answer

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child, node, adj, vis);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    return 0;
}

