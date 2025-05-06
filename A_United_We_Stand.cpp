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
        vector<int> a(n);
        cin >> n;
        map<int, int> mpp;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mpp[a[i]]++;
        }
        if(mpp.size()==1){
            cout << -1 << endl;
            return 0;
        }
        
        for (auto i: mpp){
            
        }
    }
    return 0;
}

