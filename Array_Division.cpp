#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
bool checker(int mid, vector<int>& a, int k){
    int cnt = 1;
    int curr = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if(a[i] > mid)
            return false;
        
        if (curr + a[i] > mid)
        {
            cnt += 1;
            curr = 0;
        }
        curr += a[i];
    }

    return cnt <= k;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

   
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = -1;
        int low = 1, high = 1e17;
        while(low<= high){
            int mid = (low + high) >> 1;
            if(checker(mid, a, k)){
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }

        cout << ans << endl;
        return 0;
}


