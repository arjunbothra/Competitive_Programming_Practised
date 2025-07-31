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
        vector<int> v(n);
        int xor1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            xor1 = xor1 ^ v[i];
        }

        if(n%2 == 0){
            if(xor1 == 0 )
                cout << 0 << endl;
            else
                cout << -1 << endl;
        }
        else{
            cout << xor1 << endl;
        }
    }
    return 0;
}

