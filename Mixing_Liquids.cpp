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
        int a, b;
        cin >> a >> b;
        int syrup = b / 2;
        if( a>= syrup){  
            cout << syrup + (syrup * 2) << endl;
        }
        else{
            cout << a + (a * 2) << endl;
        }
    }
    return 0;
}

