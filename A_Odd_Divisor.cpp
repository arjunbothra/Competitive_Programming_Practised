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

        bool odd = false;
        
        if(n%2 == 0){
            while(n%2 == 0){
                n /= 2;
            }
            if(n>1)
                odd = true;
        }
        else
            odd = true;

        if (odd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

