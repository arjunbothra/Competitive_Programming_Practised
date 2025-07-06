#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//Merge Elements

int n;
int dp[501][501];
int v[501];

int rec(int l, int r){
    //base case
    if(l==r)
        return 0;

    //cache check
    if(dp[l][r]!=-1) return dp[l][r];
    //
    int total = 0;
    for (int ii = l; ii <= r; ii++) total += v[ii];

    int ans=INT_MAX, sum=0;
    for (int k = l; k < r; k++)
    {
        sum += v[k];
        ans = min(rec(l, k) + rec(k + 1, r) + ((sum % 100) * (total - sum) % 100), ans);
    }
    return dp[l][r] = ans;
}


    int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    int logger = rec(0, n - 1);
    cout << logger << endl;
    return 0;
}
