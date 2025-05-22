#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    int cnt=0;
    while(n>1){
        n = (n+1) / 2;
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int lrows = min(a, n - a + 1);
        int lcols = min(b, m - b + 1);

        int rowcontinued  = 1 + solve(lrows) + solve(m);
        int colscontinued = 1 + solve(lcols) + solve(n);
        int ans = min(rowcontinued, colscontinued);
        cout << ans << endl;
    }
    return 0;
}






