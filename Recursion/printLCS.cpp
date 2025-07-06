#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
    for (int i = 1; i<n+1; i++){
        for (int j = 1; j < m + 1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        solve(n, m, s1, s2, dp);
        int i = n, j = m;
        string s;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                s.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]> dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}


