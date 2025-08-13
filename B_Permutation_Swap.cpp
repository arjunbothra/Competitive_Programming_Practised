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
        vector<int> v(n+1);
        for (int i = 1; i < n+1; i++){
            cin >> v[i];
        }

        int mini = 0;
        for (int i = 1; i < n + 1; ++i)
        {
            mini = __gcd(abs(v[i]-i), mini);
        }

            cout << mini << endl;
    }
    return 0;
}

