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
        int n, k;
        cin >> n>> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i] > k){
                if(v[i] % k == 0)
                    v[i] = k;
                else v[i] = v[i] % k;
            }
        }

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        stable_sort(ord.begin(), ord.end(), [&](int i, int j)
             { return v[i] > v[j]; });
        
        for(auto it: ord)
            cout << it + 1 << " ";
        cout << endl;
    }
    return 0;
}


