#include<bits/stdc++.h>
using namespace std;
#define int long long

//Max Number of Paths

int solve(int i, int j, vector<vector<int>> &v, vector<vector<int>>& dp){
    //pruning
    if(i<0 || j<0)
        return 0;
    // base case
    if(v[i][j]==1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    // cache check
    if(dp[i][j]!=0)
        return dp[i][j];
    // transitions
    int ans = solve(i - 1, j, v, dp)+solve(i, j - 1, v, dp);

    return dp[i][j] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v( n, vector<int>(m));
        //inputs
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                cin >> v[i][j];
            }
        }
        //variables
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans2 = solve(n-1, m-1, v, dp);
        cout << ans2 << endl;
    }
    return 0;
}

