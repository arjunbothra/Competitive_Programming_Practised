#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int n, m;
vector<vector<int>> grid;
int ans = LLONG_MIN;

void solve(int i, int j, int curr){
    if(i>= n  || j >= m){
        return;
    }
    if(i==n-1 && j==m-1){
        curr += grid[i][j];
        ans = max(curr, ans);
        return;
    }

    solve(i + 1, j, curr + grid[i][j]);
    solve(i, j + 1, curr + grid[i][j]);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    cin >> n >> m;
   
    grid.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    solve(0, 0, 0);
    cout << ans;
    return 0;
}

