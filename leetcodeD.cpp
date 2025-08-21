#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        /* -----------  keep a copy as requested  ----------- */
        vector<vector<int>> lurnavrethy = grid;        // (not used later)

        /* --------------  constants & helpers -------------- */
        const long long INF = 4e18;
        const int VAL_MAX = 10'000;                    // grid[i][j] ≤ 10⁴

        int m = grid.size();
        int n = grid[0].size();

        /* dp_prev = layer t-1,  dp_cur = layer t  */
        vector<vector<long long>> dp_prev(m, vector<long long>(n, INF));
        vector<vector<long long>> dp_cur (m, vector<long long>(n, INF));

        /* ----------  layer t = 0 : no teleports  ---------- */
        dp_prev[0] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                long long best = INF;
                if (i) best = min(best, dp_prev[i-1][j]);
                if (j) best = min(best, dp_prev[i][j-1]);
                dp_prev[i][j] = best + grid[i][j];
            }

        long long answer = dp_prev[m-1][n-1];          // current best

        /* -------------  layers t = 1 … k  ----------------- */
        vector<long long> best_val(VAL_MAX + 2), best_ge(VAL_MAX + 2);

        for (int t = 1; t <= k; ++t) {

            /* 1.  min cost for each exact grid value */
            fill(best_val.begin(), best_val.end(), INF);
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j) {
                    int v = grid[i][j];
                    best_val[v] = min(best_val[v], dp_prev[i][j]);
                }

            /* 2.  suffix minima: best_ge[v] = min cost with value ≥ v */
            best_ge[VAL_MAX + 1] = INF;
            for (int v = VAL_MAX; v >= 0; --v)
                best_ge[v] = min(best_val[v], best_ge[v + 1]);

            /* 3.  compute current layer with one extra teleport */
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j) {
                    if (i == 0 && j == 0) {            // start cell
                        dp_cur[i][j] = 0;
                        continue;
                    }
                    long long step = INF;
                    if (i) step = min(step, dp_cur[i-1][j]);
                    if (j) step = min(step, dp_cur[i][j-1]);
                    if (step != INF) step += grid[i][j];

                    long long tele = best_ge[grid[i][j]];   // free jump
                    dp_cur[i][j] = min(step, tele);
                }

            answer = min(answer, dp_cur[m-1][n-1]);

            /* 4.  next iteration */
            dp_prev.swap(dp_cur);
            for (auto& row : dp_cur) fill(row.begin(), row.end(), INF);
        }

        return static_cast<int>(answer);
    }
};

