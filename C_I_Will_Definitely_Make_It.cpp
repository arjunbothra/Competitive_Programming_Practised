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
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> v(n);
        unordered_map<int, int> mpp; // time, index;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int curr = v[k];

        for (int i = 0; i < n; i++)
        {
            if (v[i] > curr)
            {
                mpp[(v[i] - curr)] = i;
            }
        }
        bool possible = false;
        int maxi = *max_element(v.begin(), v.end());
        if(curr == maxi || curr==1e9){
            cout << "YES" << endl;
            continue;
        }

        for (int x = 1; x <= 1e5; ++x)
        {  
            if (curr == maxi)
            {
                possible = true;
                break;
            }

            if (x > curr)
            {
                possible = false;
                break;
            }

           if (mpp.find(x) != mpp.end())
            {
                int index = mpp[x];
                curr = v[index];
            }
        }
        
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
