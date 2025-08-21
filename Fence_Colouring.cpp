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
        vector<int> hash(n+1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            hash[v[i]]++;
        }

        int majorFreq = hash[1];
        int ele = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            if(hash[i] > majorFreq){
                majorFreq = hash[i];
                ele = i;
            }
        }
        if (ele== 1)
            cout << n - majorFreq << endl;
        else 
        cout << (n - majorFreq) + 1 << endl;
    }
    return 0;
}

