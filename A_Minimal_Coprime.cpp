#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;;
    while(t--){
        int l, r;
        cin >> l >> r;
        if(l==1 && r==1) cout << 1 << endl;
        else cout << r - l << endl;
    }
    return 0;
}