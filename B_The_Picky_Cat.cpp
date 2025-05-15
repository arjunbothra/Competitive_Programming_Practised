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
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        //required median
        int req = abs(v[0]);
        int smlr = 0, grtr = 0;
        for (int i = 0; i<n; i++){
            if(abs(v[i])>req)
                grtr++;
            else if (abs(v[i])<req)
                smlr++;
        }
        int c = (n + 1) / 2;
        // required index
        int ind = c - 1;
        if(smlr<=ind || grtr>=ind)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}