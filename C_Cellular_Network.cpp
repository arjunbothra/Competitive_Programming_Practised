#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
bool checker(int r, vector<int>& cities, vector<int>& towers){
    int i = 0, j = 0;
    int n = cities.size(), m = towers.size();
    while (i < n && j<m){
        if(abs(cities[i]-towers[j]) <= r)
            i++;
        else
            j++ ;
    }
    if(i==n)
        return true;
    return false;
} // O(n+m);

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

        int n, m;
        cin >> n>> m;

        vector<int> cities(n), towers(m);
        for (int i = 0; i < n; i++)  
            cin >> cities[i];
        
        for (int i = 0; i < m; ++i){
            cin >> towers[i];
        }

        int l = 0, r = 2e9;
        int ans=-1;
        while (l <= r)
        {
            int mid= l+(r-l)/2;

            if(checker(mid, cities, towers)){
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }

        cout << ans << endl;

        return 0;
}

