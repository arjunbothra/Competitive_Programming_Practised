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
        string s;
        cin >> s;

        int n = s.size();
        if (s[0] != s[n - 1]){
            if(s[0] == 'a'){
                s[n - 1] = 'a';
            }
            else
                s[n - 1] = 'b';
        }

        cout << s << endl;
    }
    return 0;
}



