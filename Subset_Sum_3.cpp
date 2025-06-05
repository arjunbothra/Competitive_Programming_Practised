#include<bits/stdc++.h>
using namespace std;

int solve(int n, int sum, vector<int> & v){
    if(sum%3==0 && sum!=0)
        return 1;
    if(n<0) return 0;

    int pick = solve(n - 1, sum + v[n], v);
    if(pick==1)
        return 1;
    int notpick = solve(n - 1, sum, v);
    if(notpick==1)
        return 1;

    return 0;
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
        int sum = 0;
        // int sum = accumulate(v.begin(), v.end(), 0);
        // if(sum%3==0)
        //     cout << "Yes"<<endl;
        // else
        //     cout << "No"<<endl;

        // for (int i = 0; i < n; i++){
        //     for (int j = i; j < n; j++){
        //         int pick+=
        //     }
        // }
        if(solve(n-1, sum, v)==1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

