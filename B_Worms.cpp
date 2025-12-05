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
            cin >> v[i];
        }


        vector<int> pre(n+1, 0);
        pre[0] = 0;
        for (int i = 1; i < n + 1; ++i){
            pre[i] = pre[i - 1] + v[i - 1];
        }
        
        
        int m;
        cin >> m;
        vector<int> ans(m);
        for (int i = 0; i < m; ++i){
            int j_worm;
            cin >> j_worm;
            ans[i] = lower_bound(pre.begin(), pre.end(), j_worm) - pre.begin();
        }

        for(auto ut: ans)
            cout << ut << endl;
        return 0;
}

