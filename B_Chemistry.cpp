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
        string s;
        cin >> s;

        if(n==1){
             cout << "YES" << endl;
             continue;
        }

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[s[i]-'a']++;
        }

        int cnt = 0;
        for (auto it : mpp)
        {
            if(it.second % 2 != 0)
                cnt++;
            
            if(cnt>k+1)
                break;
        }

        if(cnt>k+1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    } 
    return 0;
}

