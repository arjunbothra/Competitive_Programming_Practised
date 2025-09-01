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
        int n, m;
        cin >> n >> m;


        if(n==m){
            cout << 0 << " " << 0 << endl;
        }
        // else if(n == ans || m == ans){
        //     cout << ans << " " << 0 << endl;
        // }
        else{
            if(m>n)
                swap(n, m);
            int ans = n - m;
            cout << ans << " " << min(n%ans, ans - (n % ans)) << endl;
        }
    }
    return 0;
}

