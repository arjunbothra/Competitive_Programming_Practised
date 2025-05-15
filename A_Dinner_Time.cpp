#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n, m, p, q;
        cin >> n>> m>> p>> q;
        int check = n / p;
        if (n%p==0){
            if(check*q==m)
                cout << "YES"<< endl;
            else
                cout << "NO" << endl;
        }
        else 
            cout << "YES"<< endl;
    }
    return 0;
}