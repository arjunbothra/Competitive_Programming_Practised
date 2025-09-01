#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
Brute Force- O(n^2)
    add b[i] then find gcd
    a[i] + b[j].....a[n-1]


    
    a[1]-a[0]....a[n-1]-a[0] gcd= gcd (a[0], a[1].....a[n-1]);
*/

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
        int n, m;
        cin >> n >> m;
        vector<int> v(n), b(m);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        for (int i = 0; i < m; ++i){
            cin >> b[i];
        }

        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            ans = __gcd(abs(v[i]-v[0]), ans);
        }

        
        for (int i = 0; i < m; ++i){
            cout << __gcd(ans, v[0]+b[i]) << " ";
        }
    
    return 0;
}

