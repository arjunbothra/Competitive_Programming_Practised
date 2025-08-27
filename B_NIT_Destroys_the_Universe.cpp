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
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i]!=0 ){
                cnt++;
                while (v[i] != 0 && i<n)
                {
                    i++;
                }
            }
            
        }
        if(cnt > 1)
            cout << 2 << endl;
        else if(cnt == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

