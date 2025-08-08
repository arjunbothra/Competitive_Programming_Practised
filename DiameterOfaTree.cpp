#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
void dfs(int curr, int parent, vector<vector<int>> &adj, vector<int> &maxDistFromLCA)
{
    //function to find the maximum depth of each children

    maxDistFromLCA[curr] = 0; //leaf node edge case

    for (auto it : adj[curr])
    {
        if (it != parent)
        {
            dfs(it, curr, adj, maxDistFromLCA);
            // cout << "Curr: " << curr << " " << it << " ";
            maxDistFromLCA[curr] = max(maxDistFromLCA[curr], 1+maxDistFromLCA[it]);
        }
    }
}

void dfs1(int curr, int parent, vector<vector<int>> &adj, vector<int> &maxDistFromLCA, vector<int> &maxDiameter){
    //function to add maximum depth of each child to finc the diameter

    maxDiameter[curr] = 0;
    vector<int> allDistances;
    for (auto it : adj[curr])
    {
        if(it != parent){
            dfs1(it, curr, adj, maxDistFromLCA, maxDiameter);
            allDistances.push_back(maxDistFromLCA[it]);
        }
    }

    if(allDistances.size() == 0){
        maxDiameter[curr] = 0;
    }
    else if(allDistances.size() ==1){
        maxDiameter[curr] = allDistances[0] + 1;
    }
    else{
        sort(allDistances.begin(), allDistances.end(), greater<>());
        maxDiameter[curr] = allDistances[0] + allDistances[1] + 2;
    }
}

void dfs3(int curr, int parent, vector<vector<int>>& adj, vector<int>& dist){
    if(parent == -1)
        dist[curr] = 0;
    else
        dist[curr] = dist[parent] + 1;
    
    for(auto it: adj[curr]){
        if(it != parent){
            dfs3(it, curr, adj, dist);
        }
    }
}

int getFarthestNode(int n, vector<int>& dist){
    int farthest = 0;
    for (int i = 0; i < n; ++i){
        if(dist[i]>dist[farthest])
            farthest = i;
    }
    return farthest;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> maxDistFromLCA(n, -1); //To store distance of max leaf node
    vector<int> maxDiameter(n, -1); //To store max diameter of each node

    // APPROACH : 1
    // dfs(0, -1, adj, maxDistFromLCA);
    // dfs1(0, -1, adj, maxDistFromLCA, maxDiameter);

    // for(auto it: maxDistFromLCA)
    //     cout << it << " ";

    // cout << endl;

    // for(auto it: maxDiameter)
    //     cout << it << " ";

    // APPROACH :  2
    //Find the farthest node 'Y' from any node then calculate the farthest node from that to find node 'Z'
    
    // int x=0;
    // vector<int> X(n, -1), Y(n, -1);
    // dfs3(x, -1, adj, X);

    // int y = getFarthestNode(n, X);
    // dfs3(y, -1, adj, Y);
    // int z = getFarthestNode(n, Y);

    // cout << Y[z] << endl;

    return 0;
}
