#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

bool isPalindrome(int i, int j, vector<int>& a){
    while(i<j){
        if(a[i]!=a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int j, vector<int>&v, vector<vector<int>>&dp){
    //base case
    if(i>j)
        return 0;
    
    if (isPalindrome(i, j, v))
        return 1;
    //cache check
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i+1; k < j; k++)
    {   
        if(v[i]==v[k]) ans = min(solve(i + 1, k - 1, v, dp)+ solve(k+1, j, v, dp), ans);
        else   
        ans = min(solve(i, k-1, v, dp) + solve(k, j, v, dp), ans);
    }
    return dp[i][j] = ans;
}

int32_t main(){
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
        int ans2= solve(0, n-1, v, dp);
    
        cout<<ans2<<endl;

    }
    return 0;
}

