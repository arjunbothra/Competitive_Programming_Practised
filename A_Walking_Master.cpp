#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int a, b, c, d, cnt=0;
        cin >> a>> b >> c >> d;
        if(d<b)
            cout << -1 << endl;
        else {
            while(b!=d){
                b++;
                a++;
                cnt++;
            }
            if(a>=c){
                cnt += a - c;
                cout << cnt << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}

