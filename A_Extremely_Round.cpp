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
        if(n<=9){
            cout << n << endl;
        }

       else {
           int ans = 0;
           while(n>10){
               ans += 9;
               n= n / 10;
           }
           ans += n;

           cout << ans <<endl; 
       }
    }
    return 0;
}

