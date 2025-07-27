#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

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
        int sum = 0;
        bool p = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            // cout << (sum / (i + 1)) << " ";
            if ((sum / (i + 1)) < 40)
            {

                p = false;
            }
        }
       
        if (p == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
