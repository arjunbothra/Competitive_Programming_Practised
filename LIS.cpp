#include<bits/stdc++.h>
using namespace std;


int solve(int level, vector<int>& v, vector<vector<int>>& dp){
    //pruning

    //base case
    if(level<0)
        return 0;
    //cache check
    if (dp[level][level] != -1)
        return dp[level][level];

    int ans = 1;
    //possibilities
    for (int i = 0; i < level; i++){
        //check condition
        if(v[i]<v[level])
            ans = max(ans, 1 + solve(i, v, dp));
    }
    return dp[level][level]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
       
        for (int i = 0; i < n; i++){
            int best = 1;
            best = max(best, solve(i, v, dp));
            cout << best << " ";
        }

        // cout << solve(n-1, v, dp)<<  endl;
        cout << endl;
    }
    return 0;
}

