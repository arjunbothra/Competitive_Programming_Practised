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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        int maxi=0, mini=0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            maxi += (v[i] + x - 1) / x;
            mini += v[i];
        }

        cout << (mini+x-1) / x << " " <<  maxi  <<endl;
    }
    return 0;
}

