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


int kruskal(int n, vector<array<int, 3>>& edges){
    UnionFind dsu(n);

    sort(edges.begin(), edges.end(), [](auto &l, auto &r)
         { return l[2] < r[2]; });
    
    int total = 0;
    for (auto edge : edges)
    {
        int u= edge[0], v= edge[1], wt=edge[2];
        if(dsu.sameSet(u, v))
            continue;
        (dsu.unionRank(u, v));{
            total += wt;
        }
    }

    return total;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<array<int, 3>> edges;
    vector<pair<int, int>> X(n), Y(n);

    for (int i= 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        X[i]= {x, i};
        Y[i] = {y, i};
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    vector<array<int, 3>> egdes;

    for (int i = 1; i < n; ++i) // form edges array;
    {
        int u = X[i - 1].second;
        int v= X[i].second;
        int d = abs(X[i].first - X[i - 1].first);
        edges.push_back({u, v, d});

        int uy = Y[i - 1].second;
        int vy= Y[i].second;
        int dy = abs(Y[i].first - Y[i - 1].first);
        edges.push_back({uy, vy, dy});
    }

    auto mst = kruskal(n, edges);
    cout << mst << endl;
    
    return 0;
}



// x sort -> x1 <= x2 <= x3  then abs(x1-x2) + abs(x2-x3) {connecting 3 points} <= abs(x3-x1) 
                                                                                // so, i won't consider the later 
                                                                                // points. Instead connect the 
                                                                                // consecutive points
// y sort -> same logic as x-coordinates





