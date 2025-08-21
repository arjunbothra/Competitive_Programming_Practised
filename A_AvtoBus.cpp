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
        
        if(n<4 || n%2==1) {
            cout << -1 << endl;
            continue;
        }

        int mini = 0;
        int maxi = n / 4;

        if(n%6 == 0) {
            mini = n / 6;
        }
        else {
            mini = (n / 6) + 1;
        }


        if(mini == 0 && maxi ==0)
            cout << -1 << endl;
        else cout << mini << " " << maxi << endl;
    }
    return 0;
}

