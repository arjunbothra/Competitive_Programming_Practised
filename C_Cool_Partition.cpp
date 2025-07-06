#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n;

bool solve(int x, int start, vector<int> &v){
    vector<bool> isUsed(n, false);
    for (int j = 0; j < start - 1; j++)
        for (int i = start; i < n; i++)
        {
            if (v[j] == v[i] && isUsed[i] == false)
            {
                isUsed[i] = true;
            }
            else
                return false;
        }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++){
            cin >> v[i];
       
        }
        int cnt = 0;
        vector<bool> isUsed(n, false);
            //check if partiton possible
            for (int k = 0; k < (n+1)/2; k++){
                //loop 1st div
                if(solve(v[k], k+1, v))
                    cnt++;
                else
                    break;
            }
            //print
            if(cnt==0)
                cout << 1 << endl;
            else
                cout << cnt << endl;
        
    }
    return 0;
}

