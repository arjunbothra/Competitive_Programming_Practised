#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int minOps(string n, string it){
    int ops = 0;
    int idx = it.size() - 1;

    for (int i = n.size() - 1; i >= 0; --i){
        if(n[i]==it[idx]){
            idx--;
            if(idx<0)
                break;
        }
        else{
            ops++;
        }
    }

    return ops;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        string n;
        cin >> n;
        
        int ans= INT_MAX;
        string nums[] = {"00", "25", "50", "75"};

        for(auto it: nums){
            ans = min(ans, minOps(n, it));
        }

        cout << ans <<endl;
    }
    return 0;
}

