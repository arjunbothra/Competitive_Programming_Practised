#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        long long n, k;
        cin >> n >> k;
        if(n%2==0 || (n-k)%2==0)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

