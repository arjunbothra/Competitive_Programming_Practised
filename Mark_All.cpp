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

        int mini = INT_MAX;
        int possible = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i>0 && i<n-1){
                if(v[i]<mini){
                    mini = v[i];
                    index = i;
                }
                possible = min((v[i] + v[i + 1]), possible);
            }
        }

        int ans = min(v[0], v[n - 1]);
        if(mini> ans)
            cout << ans << endl;

        else{
            ans = min(ans, min(v[index + 1] + mini, mini + v[index - 1]));
            int pairsum = INT_MAX;

            for (int i = 0; i < n - 1; ++i){
                pairsum = min(v[i] + v[i + 1]+ mini, pairsum);
            }
            ans = min(pairsum, ans);
            cout << ans << endl;
        }

    }
    return 0;
}

