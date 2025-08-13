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
        int cnt = 0;
        int maxi = 0;
        int i = 1;
        while (i < n)
        {
            if(s[i]==s[i-1]){
                cnt++;
                maxi = max(maxi, cnt);
                i++;
            }
            else{
                 cnt = 0;
                 i++;
            }
        }

        cout << maxi + 2 << endl;
    }
    return 0;
}

