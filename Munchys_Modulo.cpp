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
        vector<int> v(n);
        int smallest = INT_MAX, secondsml = INT_MAX;
        int index = -1, sind = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]<smallest){ //find smallest
                smallest = v[i];
                index = i;
            }
        }

        for (int i = 0; i < n; ++i){ //find second smallest
            if(i != index && v[i]<secondsml){
                sind = i;
                secondsml = v[i];
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; ++i)
        {   
            if(v[i] < (secondsml + smallest) && (i!= index || i!= sind))
                ans = max(v[i], ans);
        }

        cout << ans << endl;
    }
    return 0;
}

