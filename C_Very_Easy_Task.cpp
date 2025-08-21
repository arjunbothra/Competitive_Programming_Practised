#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

bool checker(int t, int n, int x, int y){
    //print one copy first
    int time_taken = min(x, y);
    int copies = 0;
    int time_left = t - time_taken;
    if(time_left <0)
        return false;
    copies += (t / time_taken) + (time_left / y);
    return (copies >= n);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

        int n, x, y;
        cin >> n >> x >> y;
        int low = 0, high = 1e10;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if(checker(mid, n, x, y)){
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    
    return 0;
}
