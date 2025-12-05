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
        vector<int> v(n), s(n);
        map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s[i] = i + 1;
            mpp[v[i]]++;
        }

        bool flag = true;

        for(auto it: mpp){
            if(it.second == 1){
                flag = false;
                break;
            }
        }

        if(!flag) {
            cout << -1 << endl;
        }
        else{
            int l = 0, r = 0;

            while(r<n){
                if(v[l] == v[r])
                    r++;
                else {
                    rotate(s.begin() + l, s.begin()+l+1, s.begin() + r);
                    l = r;
                }
            } 
            rotate(s.begin() + l, s.begin()+l+1, s.begin() + r);

            for(auto &it: s)
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}

