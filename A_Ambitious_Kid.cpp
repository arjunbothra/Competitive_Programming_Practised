#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    
        int n;
        cin >> n;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            if (a == 0){
                ans = 0;
                break;
            }
            ans = min(ans, abs(a));
        }
        cout << ans << endl;
    
    
    return 0;
}

