#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int t = 1;
        int cnt = 0;
        while (t <= n)
        {
            t *= 2;
            cnt++;
        }
        //cout<< t << endl;
        if (((n) & (n - 1)) != 0  && t!=n+2)
        {
            cout << -1 << endl;
            continue;
        }
        if((n&(n-1))==0){
             cout << (int)log2(n) + 1 << endl;
        }
       else{
           cout << cnt + 1<<endl;
       }
    }
    return 0;
}