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
        string n;
        cin >> n;
        int s = n.size() / 2;

        int cnt0 = 0, cnt1 = 0;

        for (int i = 0; i < n.size(); ++i){
            if(n[i]=='0') cnt0++;
            if(n[i]=='1')
                cnt1++;
        }

        int pairs = min(cnt1, cnt0);

        if(pairs %2 == 0)
            cout << "NET" << endl;
        else
            cout << "DA" << endl;
    }
    return 0;
}

