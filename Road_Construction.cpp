#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
class UnionFind
{

public:
    vector<int> p, size;
    UnionFind(int n)
    {
        p.assign(n, 0);
        size.assign(n, 1);
        iota(p.begin(), p.end(), 0); // iota is a function that assigns the value to each index to it's cell
    }

    int findSet(int node)
    {
        return (p[node] == node) ? node : p[node] = findSet(p[node]);
    }

    bool sameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSize(int i, int j, int &sz)
    {
        if (!sameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (size[x] > size[y])
            {
                p[y] = x;
                size[x] += size[y];
                sz = max(size[x], sz);
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
                sz = max(size[y], sz);
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    UnionFind du(n);
    int components = n;
    vector<pair<int, int>> ans;
    int sz = -1;
    while (m)
    {
        // cout << components << " ";
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(!(du.sameSet(u, v)))
            components--;
        du.unionSize(u, v, sz);
        // components = components - min(du.size[u] , du.size[v]);
        
        ans.push_back({components, sz});
        m--;
    }

    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
