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
        int a, b;
        cin >> a >> b;
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;

        set<pair<int, int>> possible;

        vector<pair<int, int>> nd = {{b, a}, {-b, a}, {-b, -a}, {b, -a}, {a, -b}, {a, b}, {-a, b}, {-a, -b}};

        for (auto it: nd) // for king possible points
        {
            int nx = ki + it.first;
            int ny = kj + it.second;
            possible.insert({nx, ny});
        }

        int ans = 0;
        for (auto it: nd) // for queen possible points
        {
            int nx = qi + it.first;
            int ny = qj + it.second;
            if (possible.count({nx, ny})){
                possible.erase({nx, ny});
                ans++;
            }
                }

        cout << ans << endl;
    }
    return 0;
}
