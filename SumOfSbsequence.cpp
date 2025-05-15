#include<bits/stdc++.h>
using namespace std;

int sum = 0;
int cnt = 0;

int recursivef(int ind, vector<int> &v, vector<int> &ds, int n, int k){
    if(ind==n){
        if(sum==k){
            cnt++;
        }
        return cnt;
    }
    
    ds.push_back(v[ind]);
    sum += v[ind];
    recursivef(ind + 1, v, ds, n, k);
    ds.pop_back();
    sum -= v[ind];
    recursivef(ind + 1, v, ds, n, k);

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        vector<int> ds;
        recursivef(0, v, ds, n, k);
        cout << cnt;
    }
    return 0;
}

