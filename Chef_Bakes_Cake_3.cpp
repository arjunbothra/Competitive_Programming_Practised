#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long



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
        int mini = *min_element(v.begin(), v.end());
        int maxi = *max_element(v.begin(), v.end());
        int total = 0;
        for (int x = mini; x <= maxi; ++x){
            int cost = 30 * n * x;
            int sp = 0;
            for (int i = 0; i < n; ++i)
            {
                sp += min(x, v[i]) * 50;
            }
            total = max(total, sp - cost);
        }
        cout << total << endl;
    }
        return 0;
}
    
   


