#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
    1 3 4 5
    5 1 3 4 3
*/

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n , q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        vector<int> b;
        b.push_back(v[0]);
        b.push_back(v[1]);
    
        for (int i = 2; i < n; ++i)
        {
            if((i+1)%2 == 1){
                if(b[0] < b[1]){
                    b[0] = v[i];
                }
                else
                    b[1] = v[i];
            }
            else if((i+1)%2 == 0){
                if(b[1]>b[0]) b[1]=v[i];
                else 
                    b[0] = v[i];
            }

        }
        int ans = min(b[0], b[1]);
        cout << ans << endl;
    }
    return 0;
}

