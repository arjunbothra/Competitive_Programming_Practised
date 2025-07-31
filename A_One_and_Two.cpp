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

        vector<int> prefix;
        int p1 = 0;
        for (int i = 0; i < n; i++) // prefix array
        {
            if(v[i]==2) p1++;
            prefix.push_back(p1);
        }

        vector<int> suffix = {0};
        int s = 0;
        for (int i = n - 2; i >= 0; --i) //suffix array
        {
            if(v[i+1]==2)
                s++;
            suffix.push_back(s);
        }
        reverse(suffix.begin(), suffix.end());

        int k = -1;
        for (int i = 0; i < n; ++i)
        {
            if (suffix[i] == prefix[i])
            {
                k = i;
                break;
            }
        }
        
        if(k==-1)
            cout << -1 << endl;
        else cout << k+1 << endl;
    }
    return 0;
}


 // for(auto it: prefix)
        //     cout << it << " ";

        // cout << endl;
        // for (auto it : suffix)
        //     cout << it << " ";
        // cout << endl;