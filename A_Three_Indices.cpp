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
        vector<int> v(n);
        int idx;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }


        bool possible = false;
        for (int i = 1; i < n - 1; ++i)
        {
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                possible = true;
                idx = i;
            }
        }

            if (possible==false)
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                cout << idx << " " << idx+1 << " " << idx + 2 << endl;
            }
        
    }
    return 0;
}

