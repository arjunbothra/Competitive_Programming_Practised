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

        int cnt2 = 0, cnt3 = 0;
        while(n % 2==0){
            n/=2;
            cnt2++;
        }

        while(n%3==0){
            n /= 3;
            cnt3++;
        }

        if(n>1 || cnt2 > cnt3)
            cout << -1 << endl;
        else if(cnt2 <= cnt3){
            cout << (cnt3-cnt2)+cnt3 << endl;
        }

    }
    return 0;
}

