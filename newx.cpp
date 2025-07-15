#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

struct Edge {
    int to, w, idx;
};

int N, M;
vector<vector<Edge>> adj;
vector<tuple<int,int,int>> edges;

// --- Find minimum cycle via edge‐removal + Dijkstra ---
ll find_min_cycle() {
    ll best = INF;
    vector<ll> dist(N);
    for (int rem = 0; rem < M; ++rem) {
        auto [u0, v0, w0] = edges[rem];
        // Dijkstra from u0 to v0 skipping edge rem
        fill(dist.begin(), dist.end(), INF);
        dist[u0] = 0;
        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<>> pq;
        pq.push({0, u0});
        while (!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            if (u == v0) break;
            for (auto &e : adj[u]) {
                if (e.idx == rem) continue;
                ll nd = d + e.w;
                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }
        if (dist[v0] < INF) {
            best = min(best, dist[v0] + w0);
        }
    }
    return best == INF ? -1 : best;
}

// --- Find maximum cycle via edge‐removal + DFS backtracking longest path u→v ---
ll dfs_longest(int u, int dest, vector<char> &vis, int skipEdge, ll curSum) {
    if (u == dest) {
        return curSum;
    }
    ll ans = -INF;
    for (auto &e : adj[u]) {
        if (e.idx == skipEdge) continue;
        if (!vis[e.to]) {
            vis[e.to] = 1;
            ll got = dfs_longest(e.to, dest, vis, skipEdge, curSum + e.w);
            if (got > ans) ans = got;
            vis[e.to] = 0;
        }
    }
    return ans;
}

ll find_max_cycle() {
    ll best = -INF;
    vector<char> vis(N);
    for (int rem = 0; rem < M; ++rem) {
        auto [u0, v0, w0] = edges[rem];
        // longest simple path from u0→v0 skipping edge rem
        fill(vis.begin(), vis.end(), 0);
        vis[u0] = 1;
        ll longest_uv = dfs_longest(u0, v0, vis, rem, 0);
        if (longest_uv > -INF/2) {
            best = max(best, longest_uv + w0);
        }
    }
    return best < 0 ? (best == -INF ? -1 : best) : best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});
    edges.resize(M);

    for(int i = 0; i < M; i++){
        char a,b;
        int w;
        cin >> a >> b >> w;
        int u = a - 'a';
        int v = b - 'a';
        edges[i] = {u,v,w};
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
    }

    ll mn = find_min_cycle();
    ll mx = find_max_cycle();

    cout << mn << "\n" << mx << "\n";
    return 0;
}
