#include <bits/stdc++.h>
using namespace std;

struct Project {
    int id, start, end, profit;
    bool operator<(const Project& other) const {
        return end < other.end;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        int s, e, p;
        cin >> s >> e >> p;
        projects[i] = {i, s, e, p};
    }

    int m;
    cin >> m;
    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // Step 1: Topological sort
    queue<int> q;
    vector<int> topo_order;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }

    // Step 2: Sort projects by end time
    vector<Project> sorted_projects = projects;
    sort(sorted_projects.begin(), sorted_projects.end());

    // Map original id to index in sorted_projects
    unordered_map<int, int> id_to_sorted_index;
    for (int i = 0; i < n; ++i) {
        id_to_sorted_index[sorted_projects[i].id] = i;
    }

    // Step 3: DP
    vector<long long> dp(n, 0);  // dp[i] = max profit ending at project i
    long long max_profit = 0;

    for (int orig_id : topo_order) {
        int i = id_to_sorted_index[orig_id];
        Project& curr = sorted_projects[i];

        // Binary search for last non-overlapping project
        int l = 0, r = i - 1, prev = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (sorted_projects[mid].end <= curr.start) {
                prev = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        long long best_prev_profit = (prev != -1) ? dp[prev] : 0;

        // All dependencies of this project must also be in the same chain
        bool valid = true;
        for (int dep : adj[curr.id]) {
            if (id_to_sorted_index.count(dep) == 0) {
                valid = false;
                break;
            }
        }

        // Check if all dependencies finish before this one starts
        for (int dep : adj[curr.id]) {
            int dep_idx = id_to_sorted_index[dep];
            if (sorted_projects[dep_idx].end > curr.start) {
                valid = false;
                break;
            }
        }

        if (valid) {
            dp[i] = best_prev_profit + curr.profit;
            max_profit = max(max_profit, dp[i]);
        } else {
            dp[i] = best_prev_profit;  // can't include current project
        }
    }

    cout << max_profit << endl;
    return 0;
}
