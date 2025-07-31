#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
class UnionFind{
    vector<int> p, rank;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0); // iota is a function that assigns the value to each index to it's cell
    }

    int findSet(int node){
        return (p[node] == node) ? node : p[node] = findSet(p[node]);
    }

    bool sameSet(int i, int j){ return findSet(i) == findSet(j);}

    void unionRank(int i, int j){
        if(!(sameSet(i, j))){
            int x = findSet(i), y = findSet(j);
            if(rank[x] < rank[y]){
                p[x] = y;
            }
            else{
                p[y]= x;
                if(rank[x]==rank[y])
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

    int n, m1, m2;
    cin >> n >>  m1 >>  m2;

    if(m1 == n-1 || m2==n-1){
         cout << 0 << endl;
         return 0;
    }

    UnionFind DU1(n+1), DU2(n+1);
    for (int i = 0; i < m1; ++i)
    {
        int u, v;
        cin >> u >> v;
        DU1.unionRank(u, v);
    }

    for (int i = 0; i < m2; ++i){
        int u, v;
        cin >> u >> v;
        DU2.unionRank(u, v);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j < n+1 ; ++j){
            if(!DU1.sameSet(i, j) && !DU2.sameSet(i, j)){
                DU1.unionRank(i, j);
                DU2.unionRank(i, j);
                ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;

        return 0;
}
