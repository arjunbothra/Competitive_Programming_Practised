#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


int solve(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp, int & ans)
{
    //pruning
    if(i<0 || j<0)
        return 0;
    // base case
    // if(i==0 && j==0){
    //     if(v[i][j]==0)
    //         return 0;
    //     else
    //         return 1;
    // }
    //cache check
    if(dp[i][j]!= -1)
        return dp[i][j];

    int up = solve(i - 1, j, v, dp, ans);
    int left = solve(i, j - 1, v, dp, ans);
    int d=solve(i-1, j-1, v, dp, ans);

    if(v[i][j]==0)
        return dp[i][j] = 0;

    int val = 1+min(up,min( left, d));
    ans = max(val, ans);
    return dp[i][j] = val;
    //
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n>>m;
        vector<vector<int>> v(n, vector<int> (m));
        //inputs
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        solve(n - 1, m - 1, v, dp, ans);
        cout << ans*ans <<endl;
    }
    return 0;
}

