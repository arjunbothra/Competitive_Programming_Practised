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
        string s;
        cin >> s;

        set<char> st;
        vector<int> sf(n), p(n);
        for (int i = n - 1; i >= 0; --i)
        {
            st.insert(s[i]);
            sf[i] = st.size();
        }

        st.clear();
        int ans = 0;
        for (int i = 0; i < n-1; ++i)
        {
            st.insert(s[i]);
            p[i] = st.size();
            ans = max(ans, sf[i+1] + p[i]);
        }

        cout << ans << endl;

    }
    return 0;
}

