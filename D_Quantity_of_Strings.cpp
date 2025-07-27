#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int MOD = 1e9 + 7;

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


long long power(int m, int c) {
    // Any number to the power of 0 is 1
    if (c == 0) {
        return 1;
    }

    long long result = 1;
    for (int i = 0; i < c; ++i) {
        result = (result*m) % MOD;
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    UnionFind DSU(n);

    for(int i = 0; i<=n-k; ++i){
        int left = i, right = i + k - 1;
        while(left<right){
            DSU.unionRank(left, right);
            left++;
            right--;
        }
    }

    int leaders = 0;
    for (int i = 0; i < n; ++i)
    {
        if(DSU.findSet(i) == i)
            leaders++;
    }

    cout << power(m, leaders) << endl;

    return 0;
}
