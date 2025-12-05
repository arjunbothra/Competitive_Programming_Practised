#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            int u;
            cin >> u;
            v[i] = abs(u);
        }

        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = v[i];
            auto it = upper_bound(v.begin(), v.end(), 2 * x);
            it--;
            ans += it - v.begin() - i;
        }

        cout << ans << endl;
        return 0;
}

