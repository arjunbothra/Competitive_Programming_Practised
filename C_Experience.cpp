#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
class UnionFind{
    
public:
    vector<int> p, rank, exp;
    UnionFind(int n){
        p.assign(n, 0);
        exp.resize(n, 0);
        rank.assign(n, 1);
        iota(p.begin(), p.end(), 0); // iota is a function that assigns the value to each index to it's cell
    }

    int findSet(int node){
        return (p[node] == node) ? node : findSet(p[node]);
    }

    bool sameSet(int i, int j){ return findSet(i) == findSet(j);}


    int getExp(int i){  //function for exp 
        int ans = 0;
        while(p[i]!=i){
            ans += exp[i];
            i = p[i];
        }
        ans += exp[i];
        return ans;
    }

    //merge
     void unionRank(int i, int j){
        if(!(sameSet(i, j))){
            int x = findSet(i), y = findSet(j);
            if(rank[x] < rank[y]){
                p[x] = y;
                exp[x] -= exp[y];
            }
            else{
                p[y]= x;
                exp[y] -= exp[x];
                if (rank[x] == rank[y])
                    rank[x]++;
            }
        }
    }

};


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    UnionFind dsu(n);
    while (m)
    {
        string s;
        cin >> s;

        if(s[0] == 'a'){
            int u , b;
            cin >> u >> b;
            u--;
            int temp = dsu.findSet(u);
            dsu.exp[temp] += b;
        }
        else if(s[0]== 'j'){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            dsu.unionRank(u, v);
        }
        else {
            int u;
            cin >> u;
            u--;
            cout << dsu.getExp(u) << endl;
        }

        m--;
    }
    return 0;
}





