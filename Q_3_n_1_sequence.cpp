#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
void solve(int n, vector<int>& ans){
    if(n == 1){
        ans.push_back(1);
        return;
    }

    if(n%2 ==1){
        ans.push_back((3 * n) + 1);
        solve((3 * n) + 1, ans);
    }

    else{
        ans.push_back( n/2);
        solve(n / 2, ans);
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> ans;
    solve(n, ans);

    cout << ans.size();
    return 0;
}

