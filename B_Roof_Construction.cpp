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
        vector<int> a;
        n--;

        int msb = log2(n);
        int num = pow(2, msb)-1;

        while(num>=0){
            a.push_back(num);
            num--;
        }

        num = pow(2, msb);
        while(num<=n){
            a.push_back(num);
            num++;
        }

        for(auto it: a) cout << it << " ";
        cout << endl;
    }
    return 0;
}


