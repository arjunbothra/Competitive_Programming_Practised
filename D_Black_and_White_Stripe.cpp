#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int maxSize = 0, j = 0;

        vector<int> pW(n + 1);

        // for (int i = 1; i < n; ++i){
        //     pW[i] = pW[i - 1] + (s[i - 1] == 'W');
        // }

        
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == 'W')
            {
                pW[i] = pW[i - 1] + 1;
            }
            else
                pW[i] = pW[i - 1];
        }

        int ans = INT_MAX;
        for (int i = k; i <= n; ++i)
        {
            ans = min(ans, pW[i] - pW[i - k]);
        }

        cout << ans << endl;
    }
    return 0;
}

