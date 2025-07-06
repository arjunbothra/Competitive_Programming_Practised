#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n, m;
int delrow[] = {0, 1, 0, -1};
int delcol[] = {1, 0, -1, 0};
char moves[] = {'R', 'D', 'L', 'U'};
queue<pair<int, int>> q;

void bfs(int dx, int dy, vector<vector<char>> & a, vector<vector<int>> & vis, vector<vector<int>> & path){
    while(!q.empty()){
        if(vis[dx][dy])
            break;

        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + delrow[i];
            int ny = y + delcol[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!= '#' && !vis[nx][ny]){
                q.push({nx, ny});
                vis[nx][ny] = 1;
                path[nx][ny] = i;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> path(n, vector<int> (m, -1));
    
    int sx = -1, sy = -1, dx=-1, dy=-1;

    //input and mark A & B
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
            if(a[i][j]=='A'){
                sx = i, sy = j;
                vis[i][j] = 1;
                q.push({i, j});
            }
            if(a[i][j]=='B'){
                dx = i, dy = j;
            }
        }
    }

    bfs(dx, dy, a, vis, path);

    if(vis[dx][dy]){
        cout << "YES" << endl;
        string s;
        while (dx != sx || dy != sy)
        {
            int k = path[dx][dy];
            s.push_back(moves[k]);
            dx -= delrow[k];
            dy -= delcol[k];
        }
        reverse(s.begin(), s.end());
        cout << s.size() << endl;
        cout << s << endl;
    }
    else
        cout << " NO" << endl;

    return 0;
}

