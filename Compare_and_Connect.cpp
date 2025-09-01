#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
    Claims & Possibilities

    if n==0 '<' ==0{
        >>>   ><><>=>
    } 
    if m==0 '>' == 0{
        <<<<<=<<><>
    }

*/

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;

        if( n== 0){
            string ans = ">=>";
            string f;
            m -= 2;
            for (int i = 1; i <= m; ++i){
                f.push_back('>');
                f.push_back('<');
            }
            cout << f + ans << endl;
        }
        else if(m==0){
            string ans = "<=<";
            string f;
            n -= 2;
            for (int i = 1; i <= n; ++i)
            {
                f.push_back('<');
                f.push_back('<');
            }
            cout << f + ans << endl;
        }
        else if (n!=0 && m!=0){
            string ans = "<<>";
            n -= 1;
            m -= 1;
            string f;
            for (int i = 1; i <= n; ++i){
                f.push_back('<');
                f.push_back('<');
            }
            for (int i = 1; i <= m; ++i){
                ans.push_back('<');
                ans.push_back('>');
            }

            cout << f + ans << endl;
        }
        else
            cout << "" << endl;
    }
    return 0;
}

