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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 0;
        int i = 0;
        while (i < n)
        {
            int cnt = 0;
            // cout << i << " ";
            while (i < n && v[i] % 2 != 0)
            {
                cnt++;
                i++;
            }

            if (cnt >= 2)
            {
                // cout << "hello" << endl;
                ans += cnt - 1;
                cnt = 0;
            }

            int cnt2 = 0;
            while (i < n && v[i] % 2 == 0)
            {
                cnt2++;
                i++;
            }
            if (cnt2 >= 2)
            {
                ans += cnt2 - 1;
                cnt2 = 0;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}
