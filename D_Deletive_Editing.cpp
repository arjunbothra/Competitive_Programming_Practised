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
        string s, t;
        cin >> s >> t;

        int n=s.size(), m=t.size();
        map<char, int> mpp;
        for (int i = 0; i < m; ++i)
        {
            mpp[t[i]]++;
        }
        string ans;
        for (int i = n - 1; i >= 0; --i)
        {
            if(mpp.find(s[i]) != mpp.end()){
                ans.push_back(s[i]);
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
            }
        }
        // cout << ans << " ";
        reverse(ans.begin(), ans.end());
        if (ans == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

