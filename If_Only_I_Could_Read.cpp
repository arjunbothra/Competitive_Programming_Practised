#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
/*
idea & observations - if array is sorted then not possible

else find any even length and check if after m/2 index if there's a value smaller than it


*/

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
        bool is_sorted = true;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i > 0 && v[i] < v[i - 1])
            {
                is_sorted = false;
                idx = i;
            }
        }

        if (is_sorted)
        {
            cout << -1 << endl;
            continue;
        }

        cout << idx << " " << idx + 1 << endl;
        // vector<int> s(n);
        // s[n - 1] = v[n - 1];

        // for (int i = n - 2; i >= 0; --i)
        // {
        //     s[i] = min(s[i + 1], v[i]);
        // }

        // for (auto it : s)
        //     cout << it << " ";

        // cout << endl;

    }
    return 0;
}
