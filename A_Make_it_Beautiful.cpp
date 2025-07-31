#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        bool all_same = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i>0){
                if(v[i] != v[i-1])
                    all_same = false;
            }
        }

        if(all_same){   
            cout << "NO" << endl;
            continue;
        }

        sort(v.begin(), v.end());

        vector<int> ans2;
        ans2.push_back(v[n - 1]);
        for (int i = 0; i<n-1; ++i)
            ans2.push_back(v[i]);

        cout << "YES" << endl;
        for (auto it : ans2)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

