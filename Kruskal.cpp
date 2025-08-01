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


vector<vector<int>> kruskal(int n, vector<vector<int>>& edges){
    UnionFind dsu(n);
    vector<vector<int>> mst;

    sort(edges.begin(), edges.end(), [](auto &l, auto &r)
         { return l[2] < r[2]; });

    for(auto edge: edges){
        int u= edge[0], v= edge[1], wt=edge[2];
        if(dsu.sameSet(u, v))
            continue;
        (dsu.unionRank(u, v));
        mst.push_back(edge);
    }

    return mst;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n, m;
        vector<vector<int>> edges(m, vector<int>(3));

        for(int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];       
        }
        auto mst = kruskal(n, edges);
    }
    return 0;
}








