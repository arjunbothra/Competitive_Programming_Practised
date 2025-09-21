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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int ans= 0;
        int maxi = v[0], mini = v[0];

        for (int i = 1; i < n; ++i){
            maxi = max(v[i], maxi);
            mini = min(v[i], mini);
            if( maxi - mini > 2*x) {
                maxi = v[i];
                mini = v[i];
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

