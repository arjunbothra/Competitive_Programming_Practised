#include<bits/stdc++.h>
using namespace std;

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
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++){
            if(i<n-1 && v[i]==v[i+1])
                continue;
            int rem = n - (i + 1), cost = v[i] + rem;

            ans = min(ans, cost);
        }

        cout << ans<< endl;
    }
    return 0;
}

