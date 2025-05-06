#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='.' && s[i+1]=='.' && i+1<n && s[i+2]=='.' && i+2<n){
                cnt = 2;
                break;
            }
            else if(s[i]=='.'){
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}