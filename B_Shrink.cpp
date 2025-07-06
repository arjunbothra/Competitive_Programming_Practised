#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> ans;
        
        //insert odd nums
        for (int i = 1; i <= n; i+=2){
            ans.push_back(i);
        }

        //insert even nums
        int limit;
        if (n % 2 == 1)
            limit = n - 1;
        else
            limit = n;
        for (int i =limit; i > 0; i -= 2)
        {
            ans.push_back(i);
        }

        for(auto i: ans)
            cout << i << " ";

        cout << endl;
    }
    return 0;
}

