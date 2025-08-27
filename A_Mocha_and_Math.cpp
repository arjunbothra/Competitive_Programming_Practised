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
        int n;
        cin >> n;
        vector<int> v(n);
        int ans;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i > 0)
            {
                ans = ans & v[i];
            }
            else
            {
                ans = v[i];
            }
        }

        cout << ans << endl;
    }
    return 0;
}
