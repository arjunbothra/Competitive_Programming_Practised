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
        int a, b;
        cin >> a >> b;

        int ans = INT_MAX;

        for (int i = 0; i < 32; ++i){
            int ops = i;
            int new_b = b + i;
            if (new_b == 1){
                continue;
            }
            int new_a = a;

            while (new_a > 0)
            {
                new_a /= new_b;
                ops++;
            }
            ans = min(ans, ops);
        }

        cout << ans << endl;
    }
    return 0;
}

