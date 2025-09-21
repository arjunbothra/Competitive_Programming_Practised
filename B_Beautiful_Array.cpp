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
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        int mini = k * b, maxi = (k * b) + (n * (k - 1));

        if(s < mini || s > maxi){
            cout << -1 << endl;
            continue;
        }

            vector<int> ans(n);
            ans[0] = mini;
            int new_s = s - mini;
            for (int i = 0; i < n; ++i)
            {
                int a = min(k - 1, new_s);
                ans[i] += a;
                new_s -= a;
            }

            for(auto it: ans)
                cout << it << " ";
            cout << endl;
        
    }
    return 0;
}

