#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


bool dfs(int r, int c, int px, int py,  char node, vector<vector<char>>& a, vector<vector<int>>& vis){
    if(vis[r][c])
        return true;

    vis[r][c] = 1;

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++){
        int newx = r + delrow[i];
        int newy = c + delcol[i];
        
        if(newx>=0 && newx<a.size() && newy>=0 && newy<a[0].size() && a[newx][newy]==node && !(newx==px && newy==py)){
            if(dfs(newx, newy, r, c,  a[newx][newy], a, vis)) return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    //input
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int> (m, 0));
    bool c = false;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!vis[i][j]){
                if(dfs(i, j, i, j, a[i][j], a, vis)){
                    c = true;
                    break;
                }
            }
        }
    }

    if(c == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

