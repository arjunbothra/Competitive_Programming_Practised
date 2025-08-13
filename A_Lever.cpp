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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i){
            cin >> b[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if(a[i]> b[i]){
                cnt += a[i] - b[i];
            }
        }

        cout << cnt + 1 << endl;
    }
    return 0;
}

