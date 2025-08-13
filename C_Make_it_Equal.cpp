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
        int k;
        cin >> n >> k;
        vector<int> s(n);
        vector<int> t(n);
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        for (int i = 0; i < n; i++){
            cin >> t[i];
        }

        if (k == 0) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            continue;
        }

        unordered_map<int, int> cnt;
        for (auto& x : s) {
            int r = x % k;
            if (r < 0) r += k;
            int nr = min(r, k - r);
            cnt[nr]++;
        }
        for (auto& x : t) {
            int r = x % k;
            if (r < 0) r += k;
            int nr = min(r, k - r);
            cnt[nr]--;
        }

        bool ok = true;
        for (auto& p : cnt) {
            if (p.second != 0) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}