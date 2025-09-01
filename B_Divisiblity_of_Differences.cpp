#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

  
        int n, k, m;
        cin >> n >> k >> m;

        vector<int> v(n);
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mpp[v[i]%m]++;
        }

        for(auto &[mod, count]: mpp){
            if(count >= k){
                cout << "Yes" << endl;
                for (int i = 0; i<n; ++i)
                {
                    if(v[i]% m == mod && k>0){
                        k--;
                        cout << v[i] << " ";
                    }
                }
                cout << endl;
                return 0;
            }
        }

        cout << "No" << endl;
    
    return 0;
}

