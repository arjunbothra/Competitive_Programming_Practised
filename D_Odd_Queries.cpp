#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer

bool query(vector<int> &a)
{
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        vector<int> prefix(n), suffix(n);

        suffix[n - 1] = 0;
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            prefix[i] = p;
            p += v[i];
        }

        int s = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            suffix[i] = s;
            s += v[i];
        }


            while (q--)
            {
                int l, r, k;
                cin >> l >> r >> k;
                // cout << l << " " << r << endl;
                int c = ((r-l)+1) * k;
                // cout << c << endl;
                int ans = prefix[l - 1] + suffix[r - 1] + c;
        
                if (ans % 2 == 0)
                    cout << "NO" << endl;
                else
                    cout << "YES" << endl;
            }
    }
    return 0;
}
