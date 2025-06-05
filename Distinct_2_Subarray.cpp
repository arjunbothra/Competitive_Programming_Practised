#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int n){
    if(v.size()==1)
        return -1;
    int i = 0, j = 1, cnt = 1, ans = INT_MAX;
    while (j < v.size())
    {
        if (v[j] != v[i])
        {
            cnt++;
            if (cnt >= 2)
            {
                int size = j - i + 1;
                ans = min(ans, size);
            }
            i = j;
        }
        i++;
        j++;
    }
    return ans;
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
        int ans2 = solve(v, n);
        if(ans2==INT_MAX)
            cout << -1 << endl;
        
        else
            cout << ans2 << endl;
    }
    return 0;
}


