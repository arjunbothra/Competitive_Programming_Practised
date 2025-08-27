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
        int a, b, c;
        cin >> a >> b >> c;

        int new_a = b - (c - b);
        if(new_a >= a && new_a% a == 0 && new_a!= 0){
            cout << "YES" << endl;
            continue;
        }

        int new_b = c- (c-a) / 2;
        if (new_b>= b && (c-a)%2 == 0 && new_b%b== 0 && new_b != 0){
            cout << "YES" << endl;
            continue;
        }

        int new_c = a + 2* (b - a);
        if(new_c >= c && new_c % c== 0 && new_c!=0){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}

