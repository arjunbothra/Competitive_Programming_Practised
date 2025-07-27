// #include <bits/stdc++.h>
// using namespace std;

// struct Comp {
//     int colour;          // flower type
//     int sz;              // number of cells
//     vector<int> adj;     // neighbouring components
// };

// using ull = unsigned long long;

// inline ull makeKey(int a, int b)          // ordered colour-pair → 64-bit key
// {
//     if (a > b) swap(a, b);
//     return (static_cast<ull>(a) << 32) | static_cast<ull>(b);
// }

// int numberOfFlowers(int M, int N, vector<vector<int>> &A)
// {
//     const int dx[4] = {1, -1, 0, 0};
//     const int dy[4] = {0, 0, 1, -1};

//     /*------------- 1. flood-fill every single-colour component -------------*/
//     vector<vector<int>> id(M, vector<int>(N, -1));   // cell → component id
//     vector<Comp> comps;                              // data of each component
//     queue<pair<int,int>> q;

//     for (int i = 0; i < M; ++i)
//         for (int j = 0; j < N; ++j)
//             if (id[i][j] == -1) {
//                 int newId = (int)comps.size();
//                 comps.push_back({A[i][j], 0, {}});
//                 id[i][j] = newId;
//                 q.push({i, j});
//                 while (!q.empty()) {
//                     auto [x, y] = q.front(); q.pop();
//                     ++comps[newId].sz;
//                     for (int dir = 0; dir < 4; ++dir) {
//                         int nx = x + dx[dir], ny = y + dy[dir];
//                         if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
//                         if (A[nx][ny] != A[x][y]) continue;
//                         if (id[nx][ny] != -1) continue;
//                         id[nx][ny] = newId;
//                         q.push({nx, ny});
//                     }
//                 }
//             }

//     int C = (int)comps.size();

//     /*------------- 2. build adjacency between components ------------------*/
//     for (int x = 0; x < M; ++x)
//         for (int y = 0; y < N; ++y) {
//             int cur = id[x][y];
//             if (x + 1 < M) {
//                 int down = id[x+1][y];
//                 if (cur != down)
//                     comps[cur].adj.push_back(down),
//                     comps[down].adj.push_back(cur);
//             }
//             if (y + 1 < N) {
//                 int right = id[x][y+1];
//                 if (cur != right)
//                     comps[cur].adj.push_back(right),
//                     comps[right].adj.push_back(cur);
//             }
//         }

//     /* largest mono-colour area is one component */
//     int best = 0;
//     for (const auto &cp : comps) best = max(best, cp.sz);

//     /*------------- 3. BFS per unordered colour pair seen on a border ------*/
//     unordered_map<ull,int> pairIdx;              // pair key → 0..P-1
//     vector<int> lastSeen(C, -1);                 // visited? : pair index
//     int nextPair = 0;

//     for (int u = 0; u < C; ++u)
//         for (int v : comps[u].adj) {
//             int c1 = comps[u].colour, c2 = comps[v].colour;
//             if (c1 == c2) continue;

//             ull key = makeKey(c1, c2);
//             int idx;
//             auto it = pairIdx.find(key);
//             if (it == pairIdx.end()) {
//                 idx = pairIdx[key] = nextPair++;
//             } else idx = it->second;

//             if (lastSeen[u] == idx) continue;   // cluster already processed

//             queue<int> qq;
//             qq.push(u);
//             lastSeen[u] = idx;
//             long long area = 0;

//             while (!qq.empty()) {
//                 int cur = qq.front(); qq.pop();
//                 area += comps[cur].sz;
//                 for (int nxt : comps[cur].adj) {
//                     if (lastSeen[nxt] == idx) continue;
//                     int cc = comps[nxt].colour;
//                     if (cc == c1 || cc == c2) {
//                         lastSeen[nxt] = idx;
//                         qq.push(nxt);
//                     }
//                 }
//             }
//             best = max(best, (int)area);
//         }

//     return best;
// }

// /*---------------------------- driver -------------------------------------*/
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int m, n;
//     if (!(cin >> m >> n)) return 0;
//     vector<vector<int>> A(m, vector<int>(n));
//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             cin >> A[i][j];

//     cout << numberOfFlowers(m, n, A) << '\n';
//     return 0;
// }


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int numberOfFlowers(int M, int N, vector<vector<int>> A) {
    
    set<int> unique_flower_set;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            unique_flower_set.insert(A[i][j]);
        }
    }
    
    vector<int> unique_types(unique_flower_set.begin(), unique_flower_set.end());
    
    int max_flowers = 0;
    int num_unique_types = unique_types.size();

   
    if (num_unique_types == 0) {
        return 0;
    }


    function<int(int, int, int, int, vector<vector<bool>>&)> dfs = 
        [&](int r, int c, int type1, int type2, vector<vector<bool>>& visited) -> int {
        
       
        if (r < 0 || r >= M || c < 0 || c >= N || visited[r][c]) {
            return 0;
        }
        
       
        if (A[r][c] != type1 && A[r][c] != type2) {
            return 0;
        }
        
      
        visited[r][c] = true;
        int count = 1; 
        
        
        count += dfs(r + 1, c, type1, type2, visited);
        count += dfs(r - 1, c, type1, type2, visited);
        count += dfs(r, c + 1, type1, type2, visited);
        count += dfs(r, c - 1, type1, type2, visited);
        
        return count;
    };

   
    for (int i = 0; i < num_unique_types; ++i) {
        for (int j = i; j < num_unique_types; ++j) {
            int type1 = unique_types[i];
            int type2 = unique_types[j];
            
          
            vector<vector<bool>> visited(M, vector<bool>(N, false));
            
            
            for (int r = 0; r < M; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (!visited[r][c]) {
                        
                        int current_component_size = dfs(r, c, type1, type2, visited);
                      
                        if (current_component_size > max_flowers) {
                            max_flowers = current_component_size;
                        }
                    }
                }
            }
        }
    }
    
    return max_flowers;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    cout << numberOfFlowers(M, N, A);
    return 0;
}