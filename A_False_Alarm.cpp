#include<bits/stdc++.h>
using namespace std;
#define endl '\n'




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        int first = -1, last = -1;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i]==1 && first==-1)
                first = i;
            if(v[i]==1)
                last = i;
        }

        if((last-first)+1 <= x)
            cout << "YES" << endl;
        else
            cout << "NO"<< endl;
    }
    return 0;
}

