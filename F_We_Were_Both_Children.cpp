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
        map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x<= n)
                mpp[x]++;
        }

        vector<int> v(n+1);
        for (auto it : mpp)
        {
            int j = it.first;
            int cnt = it.second;
           
            for (int k = j; k <= n; k += j)  //O(n)
            {
                v[k] += cnt;
            }
        }
        int ans = *max_element(v.begin(), v.end());
        cout << ans << endl;
    }
    return 0;
}

