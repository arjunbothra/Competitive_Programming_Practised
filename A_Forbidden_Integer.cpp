#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        long long n, k, x;
        cin >> n >> k >> x;
        if(x!= 1){
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++){
                cout << 1 << " ";
            }
            cout << endl;
        }
        else if( k==1 || (k==2 && n%2!=0))
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << n / 2 << endl;
            if(n%2==0){
                for (int i = 0; i < n / 2; i++){
                    cout << 2 << " ";
                }
                cout << endl;
            }
            else{
                cout << 3 << " ";
                for (int i = 0; i < n / 2 - 1; i++){
                    cout << 2 << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}

