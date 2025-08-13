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
        int n, k;
        cin >> n>> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        if(n==1) {
            cout << 0 << endl;
            continue;
        }
        sort(v.begin(), v.end());

        int maxi = 0, cnt = 0;
        int i = 1;
        while (i < n)
        {
            if(v[i] - v[i-1] <=k) {
                cnt++;
                maxi = max(cnt, maxi);
                i++;
                // cout << i << " ";
            }
            else {
                cnt = 0;
                i++;
            }
        }

        // cout << maxi << endl;
        cout << n - (maxi + 1) << endl;
        // cout << endl;
    }
    return 0;
}

