#include<bits/stdc++.h>
using namespace std;


//author: godkill
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m, k;
        cin >> n >> m >>k;
        string win = "Bob";
        
        
            for (int i = 1; i <= k; i++){
                if(n>=i){
                    int newN = n - i;
                    if(newN<=k && m<=k){
                        win="Alice";
                        // cout << win << endl;
                        break;
                    }
                }
                if(m>=i){
                   int newM = m - i;
                   if(newM<=k && n<=k){
                       win = "Alice";
                    //    cout << win << endl;
                       break;
                   }
                }
        }
        cout << win << endl;
    }
    return 0;
}