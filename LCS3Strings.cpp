#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int solve(int i, int j, int x, string & a, string&b, string&c, vector<vector<vector<int>>> &dp){
    //pruning
    if(i<0 || j<0 || x<0)
        return 0;
    //base case

    //cache check
    if(dp[i][j][x]!= -1)
        return dp[i][j][x];
    int ans = 0;
    if (a[i] == b[j] && b[j] == c[x])
    {
        ans = 1 + solve(i - 1, j - 1, x - 1, a, b, c, dp);
    }
    else {
        ans = max(solve(i, j - 1, x, a, b, c, dp), max(solve(i - 1, j, x, a, b, c, dp),
                                                           solve(i, j , x - 1, a, b, c, dp)));
    }
    //save and return
    return dp[i][j][x] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size(), m = b.size(), k = c.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        int ans = solve(n-1, m-1, k-1, a, b, c, dp);
        cout << ans << endl;
    }
    return 0;
}

