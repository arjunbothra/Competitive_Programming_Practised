#include<bits/stdc++.h>
using namespace std;


void recursivef(int ind, vector<int> &v, vector<int> &ds, int n){
    if(ind==n){
        for(auto it: ds)
            cout << it << " ";

        if(ds.size()==0)
            cout << "{}";
        
        cout << endl;    
        return;
    }
    
    ds.push_back(v[ind]);
    recursivef(ind + 1, v, ds, n);
    ds.pop_back();
    recursivef(ind + 1, v, ds, n);
}

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

        vector<int> ds;
        recursivef(0, v, ds, n);
    }
    return 0;
}

