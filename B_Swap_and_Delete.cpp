#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
    if z==o the replace all
    if(0>1) zeroes won't be able to get replace
    if(1>0) ones won't be able to get replace

*/

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int zeroes = 0, ones = 0;

        for (int i = 0; i < s.size(); ++i){
            if(s[i]=='0')
                zeroes++;
            if(s[i]=='1')
                ones++;
        }
        string t;

        for (int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='0' && ones>0){
                t = t+'1';
                ones--;
            }

            else if(s[i]=='1' && zeroes>0){
                t =t+ '0';
                zeroes--;
            }
            else
                break;
        }
        // cout << t << " ";
        cout << s.size() - t.size() << endl;
    }
    return 0;
}

