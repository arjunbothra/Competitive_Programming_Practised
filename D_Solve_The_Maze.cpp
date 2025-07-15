#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int delrow[] = {1, 0, -1, 0};
int delcol[] = {0, 1, 0, -1};
int n, m;

bool dfs(int r, int c, int& cnt, vector<vector<int>>& vis, vector<vector<char>>& a){
    if(a[r][c] == 'B' || a[r][c]=='#')
        return false;

    vis[r][c] = 1;
    if(a[r][c]== 'G') cnt++;

    for (int i = 0; i < 4; ++i)
    {
        int newx = r + delrow[i];
        int newy = c + delcol[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]!='#' && !vis[newx][newy]){
                if(dfs(newx, newy, cnt, vis, a) == false)
                    return false;
            }
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int good = 0;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j){
                cin >> a[i][j];
                if(a[i][j] == 'G') good++;
                // cout << a[i][j] << " ";
            }
        }
        if(good== 0)
            cout << "Yes" << endl;
        else{
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j){
                if(a[i][j] == 'B'){
                    for (int d = 0; d < 4; ++d){
                        int newx = i + delrow[d];
                        int newy = j + delcol[d];
                        if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]== '.'){
                            a[newx][newy] = '#';
                        }
                    }
                }
            }
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        int cnt = 0;
        bool flag = false;

        flag = dfs(n - 1, m - 1, cnt, vis, a);
        // cout << cnt << endl;
        if (cnt == good && flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    }
    return 0;
}

