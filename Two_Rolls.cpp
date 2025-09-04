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
        int n, y;
        cin >> n >> y;

        int mini = n+(y + y);
        int maxi = n+(2 * (y + 5));

        if(mini<=50 && maxi>=50){
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}

