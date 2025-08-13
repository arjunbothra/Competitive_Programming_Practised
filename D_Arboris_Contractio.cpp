#include <bits/stdc++.h>


using namespace std;

#define endl "\n"
#define vec std::vector
#define pb push_back

typedef long long ll;

void dfs1(int u, int p, vec<vec<int>>& adj, vec<int>& deg, vec<int>& sz, vec<int>& leaves_down, vec<ll>& ops_down) {
    sz[u] = 1;
    leaves_down[u] = (deg[u] == 1);
    ops_down[u] = 0;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, adj, deg, sz, leaves_down, ops_down);
        sz[u] += sz[v];
        leaves_down[u] += leaves_down[v];
        if (sz[v] > 1) {
            ops_down[u] += leaves_down[v];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        vec<vec<int>> adj(n + 1);
        vec<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        bool is_star = false;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == n - 1) {
                is_star = true;
                break;
            }
        }
        if (is_star) {
            std::cout << 0 << endl;
            continue;
        }

        vec<int> sz(n + 1);
        vec<int> leaves_down(n + 1);
        vec<ll> ops_down(n + 1, 0);
        
        dfs1(1, 0, adj, deg, sz, leaves_down, ops_down);

        ll min_ops = -1;
        ll total_leaves = leaves_down[1];

        for (int i = 1; i <= n; ++i) {
            ll current_ops = ops_down[i];
            
            if (i != 1) {
                ll parent_comp_size = n - sz[i];
                if (parent_comp_size > 1) {
                    current_ops += (total_leaves - leaves_down[i]);
                }
            }
            
            if (min_ops == -1 || current_ops < min_ops) {
                min_ops = current_ops;
            }
        }

        std::cout << min_ops << endl;
    }
    
    return 0;
}