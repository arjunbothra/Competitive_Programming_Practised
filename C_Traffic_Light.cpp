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
        char c;
        cin >> n;
        cin >> c;
        string s;
        cin >> s;

        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        string temp = s;
        temp = temp + s;

        int ans = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if(temp[i] == c){
                int last = i;
                while (i < temp.size() )
                {
                    if(temp[i] == 'g') break;
                    i++;
                }
                ans= max((i-last), ans);
            }
        }

        // cout << temp;
        cout << ans << endl;
        
    }
    return 0;
}

