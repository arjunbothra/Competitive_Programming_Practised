#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, p;
        cin >> n >> p;
        vector<int> limit(n), cost(n);
        for (int i = 0; i < n; i++){
            cin >> limit[i];
        }
        for (int i = 0; i < n; ++i){
            cin >> cost[i];
        }
        vector<pair<int, int>> ab;
        for (int i = 0; i < n; ++i)
        {
            int c = min(cost[i], p);
            ab.push_back({c, limit[i]});
        }

        sort(ab.begin(), ab.end());
        int left = n - 1, total=p;
        for (auto it : ab)
        {
            int inf = min(left, it.second);
            total += it.first * inf;
            left -= inf;
        }

        cout << total << endl;
    }
    return 0;
}

