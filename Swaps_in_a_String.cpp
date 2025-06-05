#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int n){
     vector<int> t(n + 1);
        for (int i = n - 1; i >= 0; --i)
            t[i] = t[i + 1] + (s[i] == 'C');

            int result = 0;
            int countA = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B')
                result += max(countA, t[i + 1]);
            else if (s[i] == 'A')
                 countA++;
        }
        return result;
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
        string s;
        cin >> s;

        int ans = solve(s, n);
        cout << ans << endl;
    }
    return 0;
}

