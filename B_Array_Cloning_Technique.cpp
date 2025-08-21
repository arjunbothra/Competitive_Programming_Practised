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
        map<int, int> mpp;
        bool all_same = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mpp[v[i]]++;
            if (i > 0 && v[i] != v[i - 1])
            {
                all_same = false;
            }
        }

        if (all_same == true)
        {
            cout << 0 << endl;
            continue;
        }

        int maxi = 0;

        for (auto it : mpp)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
            }
        }
        // cout << maxi << endl;
        int cnt = 0;
        // int ans= (n+maxi -1 )/ maxi;
        while (maxi < n)
        {
            // cout << maxi << " ";
            cnt++;
            if(maxi*2 <= n){
                cnt += maxi;
                maxi *= 2;
            }
            else {
                cnt += n - maxi;
                maxi = n;
            }
        }

        cout << cnt  << endl;
    }
    return 0;
}
