#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        //inputs
        int n, x;
        cin >> n >> x;
        int prev = 0,ans = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            ans = max(a - prev, ans);
            prev = a;
        }
        ans=max(ans, (x-prev)*2);
        cout<<ans<<endl;
    }   
     return 0;
}