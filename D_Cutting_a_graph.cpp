#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
class UnionFind
{
    vector<int> p, rank;

public:
    UnionFind(int n)
    {
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0); // iota is a function that assigns the value to each index to it's cell
    }

    int findSet(int node)
    {
        return (p[node] == node) ? node : p[node] = findSet(p[node]);
    }

    bool sameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionRank(int i, int j)
    {
        if (!(sameSet(i, j)))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] < rank[y])
            {
                p[x] = y;
            }
            else
            {
                p[y] = x;
                if (rank[x] == rank[y])
                    rank[x]++;
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    UnionFind dsu(n + 1); // object create

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
    }

    vector<pair<string, pair<int, int>>> queries;

    for (int i = 0; i < k; ++i)
    {
        string s;
        int u, v;
        cin >> s;
        cin >> u >> v;
        queries.push_back({s, {u, v}});
    }

    // for(auto it : queries)
    //     cout << it.first << " " << it.second.first << " " << it.second.second;

    int size = queries.size();
    vector<string> ans;
    for (int i = size - 1; i >= 0; --i)
    {
        auto [query, innerpair] = queries[i];
        auto [x, y] = innerpair;
        // cout << query << endl;

        if (query == "ask")
        {
            if (dsu.findSet(x) == dsu.findSet(y))
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
        else
        {
            dsu.unionRank(x, y);
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << endl;

    return 0;
}
