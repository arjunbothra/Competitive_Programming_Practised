#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

class Disjoint{
    vector<int> p, rank;
    public: 
        Disjoint(int n)
        {
            rank.assign(n, 0);
            p.assign(n, 0);
            iota(p.begin(), p.end(), 0);
        }

        int Findset(int node){
            return (p[node] == node) ? node : p[node] = Findset(p[node]);
        } 

        bool isSameSet(int u, int v){
            return (Findset(u) == Findset(v)) ? 1 : 0;
        } 

        void UnionRank(int u, int v){
            if(isSameSet(u, v))
                return;
            int pu= Findset(u);
            int pv = Findset(v);
            if(rank[pu] > rank[pv]){
                p[pv] = pu;
            }
            else{
                p[pu] = pv;
                if(rank[pu] == rank[pv]){
                    rank[pv]++;
                }
            }
        }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    Disjoint DU(n);
    while(m){
        string s;
        int u, v;
        cin >> s;
        cin >> u >> v;
        u--;
        v--;

        if(s[0] == 'u')
            DU.UnionRank(u, v);

        else if(s[0] == 'g'){
            if(DU.isSameSet(u, v)) cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        m--;
    }

    return 0;
}

