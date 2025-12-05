#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int binaryExponential(int a, int b, int MOD){
    int res = 1;
    while(b>0){
        if(b&1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int x, y, z;
        cin >> x >> y >> z;

        int yy = binaryExponential(y, z, 1e9 + 6);
        int ans = binaryExponential(x, yy, 1e9 + 7);
        cout << ans << endl;
    }
    return 0;
}

