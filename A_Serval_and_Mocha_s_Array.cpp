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

        bool flag = false;
       
        for (int i = 0; i <n; ++i){
            for (int j = i + 1; j < n; ++j){
                if(__gcd(v[i], v[j]) <=2){  // TC --gcd ->> log2 min(a, b)
                      flag = true;
                      break;
                }
            }
        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

