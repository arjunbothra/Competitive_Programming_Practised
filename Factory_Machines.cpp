#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
bool checker(int t, vector<int>& a, int p){
    int total = 0;
    for (int i = 0; i < a.size(); ++i){
        if(total>= p)
            return true;
        total += t / a[i]; // products made in t seconds given by each machine
    }
    return total >= p;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int low = 1, high = 1e18;
        int ans = -1;
        while (low <= high)
        {
            int mid= (low+high) >>1;

            if(checker(mid, a, p)){
                high=mid-1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
        return 0;
}

