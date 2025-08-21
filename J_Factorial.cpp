#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int solve(int a){
    if(a == 1)
        return 1;
    return a * solve(a - 1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    auto ans = solve(n);
    cout << ans << endl;
    return 0;
}

