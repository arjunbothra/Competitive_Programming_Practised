#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

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

        int ops = INT_MAX, even = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a % k == 0)
            {
                ops = 0;
            }
            if (a % 2 == 0)
                even++;
            ops = min(ops, k - (a % k));
        }

        if (k == 4)
        {
            if (even >= 2)
                ops = min(ops, 0);
            else if (even == 1)
                ops = min(ops, 1);
            else if (even == 0)
                ops = min(ops, 2);
        }
        cout << ops << endl;
    }
    return 0;
}
