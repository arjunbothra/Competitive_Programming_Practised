#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000000000, -1);
int solve(int i, int n, int m)
{
    if(i==n){
        return 0;
    }
    if(i>n)
        return INT_MAX-10000;
    if(dp[n]!=-1)
        return dp[n];
    int ans = 1 + solve(i + 1, n, m);
    if (i + m <= n)
    {
        ans = min(ans, 1+solve(i + m, n, m));
    }
    return dp[n]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n>>m;
        cout << solve(0, n, m) <<"\n";
    }
    return 0;
}

