#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n) ;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = n - a[i]+1;
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

