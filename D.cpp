#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &A) {
        int n = A.size();
        int m = A[0].size();
        int component_id = 0;
        vector<vector<int>> component(n, vector<int>(m, -1));
        unordered_map<int, int> value_to_component;
        unordered_set<int> all_values;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] != -1 && component[i][j] == -1) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    component[i][j] = component_id;
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        value_to_component[A[x][y]] = component_id;
                        all_values.insert(A[x][y]);
                        for (int d = 0; d < 4; ++d) {
                            int nx = x + dx[d], ny = y + dy[d];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                                A[nx][ny] != -1 && component[nx][ny] == -1) {
                                component[nx][ny] = component_id;
                                q.push({nx, ny});
                            }
                        }
                    }
                    component_id++;
                }
            }
        }

        long long total_sed_value = 0;
        for (int v : all_values) {
            int my_component = value_to_component[v];
            for (long long mul = v; mul <= 1000000; mul += v) {
                if (all_values.count(mul) && value_to_component[mul] != my_component) {
                    total_sed_value = (total_sed_value + mul) % MOD;
                }
            }
        }

        return (int)total_sed_value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    Solution sol;
    cout << sol.solve(A) << "\n";
    return 0;
}



vector<bool> check(int n){
    vector<bool> isPrime(n + 1, false);
    if(n>=0)
        isPrime[0];
    if(n>=1)
        isPrime[1];
    
        
}




