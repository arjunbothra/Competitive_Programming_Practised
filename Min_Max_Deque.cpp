#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
    1 3 4 5
    5 1 3 4 3


    odd and less effected
    odd and more

    we need to know which index is contributing to answer
    if p > index  && x < idx then not effected
    if p > 


*/

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n , q;
        cin >> n >> q;
        vector<int> v(n);
        vector<pair<int, int>> Q(q);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i<q; ++i){
            int a, b;
            cin >> a >> b;
            Q.push_back({a, b});
        }

        vector<int> b;
        b.push_back(v[0]);
        b.push_back(v[1]);
        int ans = min(b[0], b[1]);

        vector<int> allmins;
        for (int i = 2; i < n; ++i)
        {
            if((i+1)%2 == 1){
                if(b[0] < b[1]){
                    b[0] = v[i];
                    ans = min(b[0], b[1]);
                    allmins.push_back(ans);
                }
                else{
                    b[1] = v[i];
                    ans = min(b[0], b[1]);
                    allmins.push_back(ans);
                }
                   
            }
            else if((i+1)%2 == 0){
                if(b[1]>b[0]){
                    b[1]=v[i];
                    ans = min(b[0], b[1]);
                    cout << ans << " ";
                    allmins.push_back(ans);
                } 
                else {
                    b[0] = v[i];
                    ans = min(b[0], b[1]);
                    cout << ans << " ";
                    allmins.push_back(ans);
                }
            }

        }
        int idx = -1;
        for (int i = allmins.size() - 1; i >= 0; --i)
        {
            if(allmins[i]==ans)
                idx = i;
        }
        vector<int> ans2;

        for (auto it: Q){
            int p = it.first;
            int q = it.second;

            if(p<idx && q<ans) {
                ans2.push_back(ans);
            }
            else if(p< idx && q>ans && (it+1)%2 )
        }

            cout << endl;
        // cout << ans << endl;
    }
    return 0;
}

