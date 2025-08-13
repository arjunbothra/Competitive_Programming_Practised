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
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        for (int i = 0; i < n-1; ++i){
                v[i] += 1;
        }

        for (int i = 1; i < n; ++i){
            if(v[i]%v[i-1] == 0){
                v[i] += 1;
            }
        }

            for (int i = 0; i < n; ++i)
            {
                cout << v[i]<< " ";
            }
        cout << endl;
    }
    return 0;
}


