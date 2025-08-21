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
        vector<int> v(n);
        bool is_decreasing = true;
        int ones = 0;


        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]== 1)
                ones++;
            if (i > 0 && v[i] > v[i - 1])
                is_decreasing = false;
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        // if(ones > 1){
        //     cout << -1 << endl;
        //     continue;
        // }

        bool possible = true;
        int ops = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            while(v[i] >= v[i+1] && v[i] > 0){
                v[i] /= 2;
                ops++;
            }
            if(v[i] == v[i+1]){
                possible = false;
                break;
            }
        }

        if(!possible)
            cout << -1 << endl;
        else
            cout << ops << endl;
    }
    return 0;
}

