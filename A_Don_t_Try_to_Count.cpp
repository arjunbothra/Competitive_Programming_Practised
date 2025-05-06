#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n>> m;
        string x, s;
        cin >> x >> s;

        bool found = false;
        int cnt = 0;
        int y =6;
        while (y>0){
            if(x.find(s) != string::npos){
                found = true;
                break;
            }
            else{
                cnt++;
                x += x;
            }
            y--;
        }
        if(!found)
            cout << -1 << endl;
        else
        cout << cnt << endl;
    }
    return 0;
}

