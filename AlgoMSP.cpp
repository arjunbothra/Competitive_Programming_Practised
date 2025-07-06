#include<bits/stdc++.h>
using namespace std;

//Maximum Sum Path
int solve(int i, int j, vector<vector<int>>& v, vector<vector<int>> &dp){
     //base case
    if(i==0 && j==0)
        return v[i][j];
    // pruning
    if(i<0 || j<0)
        return INT_MIN;
    //cache check
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = v[i][j] + max(solve(i - 1, j, v, dp), solve(i, j - 1, v, dp));
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m));
        //input
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                    cin >> v[i][j];
            }        
        }
        //varibles
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        int ans=solve(n-1, m-1, v, dp);
        cout<< ans << endl;

     //function call
       
    }
    return 0;
}

