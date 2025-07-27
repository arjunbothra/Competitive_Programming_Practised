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

        int i = 0, j=n-1;
        // cout <<"Test: " <<t << endl;

        while (i <= j)
        {
            if(s[i]=='0' && s[j]=='1'){
                i++;
                j--;
                // cout << i << " " << " J: " << j << endl;
            }
            else if(s[i]=='1' && s[j]=='0'){
                i++;
                j--;
                // cout << i << " " << " J: " << j << endl;
            }
            else
                break;
        }

        if(i>j)
            cout << "0" << endl;
        else
            cout << j - i + 1 << endl;
    }
    return 0;
}

