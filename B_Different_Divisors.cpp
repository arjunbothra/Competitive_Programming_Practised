#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int next_prime(int n){
    for (int i = n;; ++i){
        bool is_prime = true;
        for (int j = 2; j * j <= i; ++j)
        {
            if(i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime)
            return i;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int d;
        cin >> d;

        int n1 = next_prime(1 + d);
        int n2 = next_prime(n1 + d);
        int ans = min(n1 * n1 * n1, n1 * n2);
        cout << ans << endl;
    }

    return 0;
}

