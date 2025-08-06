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
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int total = INT_MAX;
        for (int i = 0; i < n - 1; ++i){
            total = min(v[i] + (v[i+1] / 2), total);
        }

        sort(v.begin(), v.end());
        total = min(total, v[0] + v[1]);

        cout << total << endl;
    }
    return 0;
}

