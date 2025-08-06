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
        int  n, k, s;
        cin >> n >> k >> s;
        int min_sum = (k * (k + 1)) / 2;
        int max_sum = ((n *(n+1)) / 2 ) - (((n - k) * ((n - k) + 1)) / 2);

        if(s<= max_sum && s>=min_sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

