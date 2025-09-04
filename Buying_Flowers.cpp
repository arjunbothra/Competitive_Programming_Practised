#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// always read question carefully and prove your answer
// what if only one left after mod 3
//  4 coins 2 flowers & 5 coins 3 flowers

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

        // if(n== 2){
        //     cout << n << endl;
        //     continue;
        // }

        if (n % 3 == 1)
        {
            int rem = n - 4;
            int total = 4 * 2;
            total += (rem / 3) * 5;
            cout << total << endl;
        }

        else
        {
            if (n % 3 == 0)
            {
                cout << 5 * (n / 3) << endl;
            }
            else if (n % 3 == 2)
            {
                cout << (5 * (n / 3)) + 4 << endl;
            }
        }
    }
    return 0;
}
