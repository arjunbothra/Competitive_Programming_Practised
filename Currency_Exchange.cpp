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
        int ig, is, tg, ts;
        cin >> ig >> is >> tg >> ts;

        if (ig == tg && is == ts)
        {
            cout << "Yes" << endl;
            continue;
        }

        // if (ig == tg || is == ts)
        // {
        //     cout << "No" << endl;
        //     continue;
        // }

        // if (ig < tg && is < ts)
        // {
        //     cout << "No" << endl;
        //     continue;
        // }

        
        // if (tg < ig && ts < is)
        // { // both less case
        //     if ((ig - tg) == (is - tg))
        //     {
        //         cout << "No" << endl;
        //         continue;
        //     }
        // }

        int c1 = (5 * ig) + is;
        int c2 = (5 * tg) + ts;

        if(c1 >= c2 && (c1 - c2) % 6 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
