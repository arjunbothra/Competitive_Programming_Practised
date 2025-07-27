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
        cin >> n >> k;
        vector<int> v(n);
        int fz = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(fz== -1 && v[i]==0){
                fz = i;
            }
        }

        if(fz== -1){
            cout << 0 << endl;
            continue;
        }

        int j = 0;
        int cnt = 0, final=0;

        for (int i = 0; i < n; ++i){
            // cout << "Iteration: " << i << " ";
            
            if(v[i]==0)
                cnt+= 1;
            
            if (v[i] == 1){
                cnt = 0;  
            }
            // cout << cnt;
            if (cnt == k)
            {
                cnt = 0;
                final += 1;
                i++;
            }
        }

            cout  << final << endl;
    }
    return 0;
}

