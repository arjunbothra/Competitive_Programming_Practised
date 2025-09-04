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
    
        int ans = 1;
        for (int i = 2; i * i <= n; ++i){
            if(n%i==0){
                ans = n/i;  //this gives the largest factor of n, as i is going to be the smallest
                break;
            }
        }

            cout << ans << " " << n-ans << endl;
    }
    return 0;
}

