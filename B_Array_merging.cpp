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
        int n;
        cin >> n;
        vector<int> a(n), b(n), freqA(2*n+1), freqB(2*n+1);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i){
            cin >> b[i];
        }

        int cnt = 1;
        for (int i = 1; i < n; ++i) 
        {
            if(a[i]==a[i-1]){
                cnt++;
            }
            else{
                freqA[a[i - 1]] = max(freqA[a[i - 1]], cnt);
                cnt = 1;
            }
        }

        freqA[a[n - 1]] = max(freqA[a[n - 1]], cnt);

        cnt = 1;

        for (int i = 1; i < n; ++i)
        {
            if(b[i]==b[i-1]){
                cnt++;
            }
            else{
                freqB[b[i - 1]] = max(freqB[b[i - 1]], cnt);
                cnt = 1;
            }
        }

        freqB[b[n - 1]] = max(freqB[b[n - 1]], cnt);

        int ans = 0;

        for (int i = 0; i < freqA.size(); ++i){
            // cout << freqA[i] << " " << freqB[i] << endl;
            ans = max(ans, freqA[i] + freqB[i]);
        }

        cout << ans << endl;    
    }
        return 0;

}

