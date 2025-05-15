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
        int cost = 10000;
        for (int i = 0; i < n; i++)
        {
            int R, C;
            cin >> R >> C;
            if(R>=7){
                cost = min(cost, C);
            }
        }
        if(cost!=10000)
            cout << cost << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

