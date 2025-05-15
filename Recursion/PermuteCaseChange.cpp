#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

void solve(int i, vector<string> &v, string op, int n){
    if(i==n){
        ans.push_back({op});
        return;
    }
    if(v[i])



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
        vector<string> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        int i = 0;
        string op="";
        solve(i, v, op, n);
    }
    return 0;
}

 