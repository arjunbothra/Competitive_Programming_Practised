#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int n, cap;
vector<int> val, wt;
int ans = 0;


void solve(int i, int currVal, int currWt){
    if(i==n){
        ans = max(ans, currVal);
        return;
    }
    
    if(currWt + wt[i] <= cap){
        solve(i + 1, currVal + val[i], currWt+wt[i]);
    }

    solve(i + 1, currVal, currWt);
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> cap;
    val.resize(n);
    wt.resize(n);

    for (int i = 0; i < n; ++i){
        cin >> wt[i];
        cin >> val[i];
    }

    solve(0, 0, 0);
    cout << ans;

    return 0;
}

