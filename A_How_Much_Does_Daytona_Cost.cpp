#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int c = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];

            if(a[i]==k)c++;
        }
        if(c>0) cout<<"YES" <<endl;   
        else cout<<"NO" <<endl;
    }
    return 0;
}