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
        int x, y, k;
        cin >> x >> y >> k;

        int total = (y * k) + k - 1;
        int ops = ( x - 2 + total) / (x - 1);
        cout << ops + k << endl;
    }
    return 0;
}

