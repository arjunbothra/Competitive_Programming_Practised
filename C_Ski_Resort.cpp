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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);

        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int ans = 0;
        int cons=0;
    
        for (int i = 0; i < n; ++i)
        {
            if(v[i]<= q) {
                cons++;
            }
            else{
                if(cons >=k) {
                    int diff = (cons - k + 1);
                    ans += ((diff) * (diff + 1)) / 2;
                }
                cons = 0;
            }
        }

        if (cons >= k) {
            int  diff = cons - k + 1;
            ans += diff * (diff + 1) / 2;
        }

        cout << ans << endl;
    }
    return 0;
}

