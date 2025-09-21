#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int calcXOR(int n){
    if(n%4 == 1){
        return 1;
    }
    if(n%4 == 2){
        return n + 1;
    }
    if(n%4 == 0){
        return n;
    }

    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
       int a, b;
       cin >> a >> b;

       int xora = calcXOR(a - 1);
       if(xora == b){
           cout << a << endl;
           continue;
       }
       else if((xora ^ b) != a){
           cout << a + 1 << endl;
           continue;
       }
       else cout << a + 2 << endl;
       
    }

    return 0;
}


