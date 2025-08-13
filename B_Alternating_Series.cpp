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
        for (int i = 0; i < n; i+= 2){
            v[i] = -1;
        }

        // if(n >= 3){  //n>3
        //     v[1] = 3;
        //     int i = 3;
        //     while (i < n)
        //     {
        //         v[i] = 2;
        //         i += 2;
        //     }
        // }
        // else if(n<=2){
        //     v[1] = 2;
        // }

        if(n%2 == 0){
            v[n - 1] = 2;
            for (int i = 1; i < n - 1; i+=2){
                v[i] = 3;
            }
        }
        else {
            for (int i = 1; i < n; i+= 2){
                v[i] = 3;
            }
        }

        for(auto it : v)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

