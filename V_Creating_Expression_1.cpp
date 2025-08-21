#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int n, target;
bool ans = false;
vector<int> a;

void solve(int i, int curr){
    if(i==n){
        if(curr == target)
            ans = true;
        return;
    }

    solve(i + 1, curr + a[i]);
    solve(i + 1, curr - a[i]);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> target;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    solve(1, a[0]);
    if(ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

