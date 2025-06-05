#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> & v){
    //pruning
    if(i<0 || j<0)
        return 0;
    // base case
    if(i==0 && j==0)
        return v[i][j];
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
    }
    return 0;
}

