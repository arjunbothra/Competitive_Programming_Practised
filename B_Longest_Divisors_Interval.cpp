#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


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
        int limit = std::min(100, n);
        int cnt = 0, maxi=0;
        for (int i = 1; i <= limit; i++)
        {
            if(n%i == 0){
                cnt++;
                maxi = max(cnt, maxi);
            }
                
            else
            {
                cnt = 0;
            }
        }

        cout << maxi << endl;
    }
    return 0;
}

