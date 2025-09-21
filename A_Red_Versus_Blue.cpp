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
        int n, a, b;
        cin >> n >> a >> b;
        // cout << n << a << b;

        int maxi = a / (b + 1), q= a % (b+1);
        
        for (int i = 0; i < q; ++i)
            cout << string(maxi + 1, 'R') << 'B';
        for (int i = q; i<b; ++i)
            cout << string(maxi, 'R') << 'B';
        cout << string(maxi, 'R');

        cout << endl;
    }
    return 0;
}

