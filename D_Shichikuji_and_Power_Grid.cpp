#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
class UnionFind{
    vector<int> p, size;
public:
    UnionFind(int n){
        p.assign(n, 0);
        size.assign(n, 1);
        iota(p.begin(), p.end(), 0); // iota is a function that assigns the value to each index to it's cell
    }

    int findSet(int node){
        return (p[node] == node) ? node : p[node] = findSet(p[node]);
    }

    bool sameSet(int i, int j){ return findSet(i) == findSet(j);}

    void unionSize(int i, int j){
        if(!sameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(size[x]>size[y]){
                p[y]=x;
                size[x] += size[y];
            }
            else{
                p[x] = y;
                size[y] += size[x];
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<array<int, 2>> coordinates(n+1);  //coordinates of points
    for (int i = 1; i <= n; ++i){
       cin >> coordinates[i][0] >> coordinates[i][1];
    }

    vector<int> cost(n + 1), k(n+1);

    for (int i = 1; i <= n; ++i)
        cin >> cost[i];

    for (int i = 1; i <= n; ++i)
        cin >> k[i];

    vector<pair<array<int, 2>, int>> edges;

    for (int i = 1; i <= n; ++i)
        edges.push_back({{0, i}, cost[i]});

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if(i==j)
                continue;

            int c = (abs(coordinates[i][0] - coordinates[j][0]) + abs(coordinates[i][1] - coordinates[j][1]))*
                    (k[i] + k[j]);
            edges.push_back({{i, j}, c});
        }
    }

    sort(edges.begin(), edges.end(), [](auto &l, auto &r)
         { return l.second < r.second ; });

    UnionFind dsu(n + 1);
    int total = 0;
    vector<int> stations;
    vector<pair<int, int>> connections;
    for (int i = 0; i < edges.size(); ++i)
    {
        auto [uv, wt] = edges[i];
        auto [u, v] = uv;

        if(dsu.sameSet(u,v))
            continue;
        dsu.unionSize(u, v);
        total += wt;
        if(u==0)
            stations.push_back(v);
        else
            connections.push_back({u, v});
    }

    cout << total << endl;
    cout << stations.size() << endl;

    for(auto it: stations)
        cout << it << " ";
    cout << endl;

    cout << connections.size() << endl;
    for (auto it : connections)
        cout << it.first << " " << it.second << endl;

    return 0;
}
