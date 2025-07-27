#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int MOD = 1e9 + 7;
int dp[10000002];
int n;

//for k==0 it's 1 because-
// 1) 0 can be made by not throwing any distance
// 2) if(n-i) where i=1, 2, 3, 4, 5, 6  is 0 it means the number is <=6 and >0 and can be made by itself

int solve(int k)
{
    if (k < 0)
        return 0;

    if (k == 1 || k == 0)
        return dp[k] = 1;

    if (dp[k] != 0)
        return dp[k];

    dp[k] = (solve(k - 1) + solve(k - 2) + solve(k - 3) + solve(k - 4) + solve(k - 5) + solve(k - 6)) % MOD;

    // if (k <= 6)
    // {
    //     return dp[k] += 1;
    // }

    return dp[k];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    memset(dp, 0, sizeof(dp));
    cout << solve(n) << endl;

    return 0;
}

// Iterative Code-

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// const int MOD = 1e9 + 7;

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1;
//     for (int k = 1; k <= n; ++k) {
//         for (int i = 1; i <= 6; ++i) {
//             if (k - i >= 0)
//                 dp[k] = (dp[k] + dp[k - i]) % MOD;
//         }
//     }
//     cout << dp[n] << '\n';
//     return 0;
// }
