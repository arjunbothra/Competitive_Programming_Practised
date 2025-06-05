#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

int solve(int n, int sum, vector<int> &v, vector<int> a, vector<vector<int>> &dp)
{
    if(sum==0){
        ans.push_back(a);
        return 1;
    }
        
    if(n==0 )
        return 0;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    int notTake = solve(n - 1, sum, v, a, dp);
    int Take=0;
    if (v[n-1]<=sum){
        a.push_back(v[n - 1]);
        Take = solve(n - 1, sum - v[n - 1], v, a, dp);
    }
    return dp[n][sum] = Take || notTake;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, target;
        cin >> n >> target;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> a;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        solve(n, target, v, a, dp);

        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

