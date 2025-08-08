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
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }

        for (int i = 0; i < n; i++){
            cin >> B[i];
        }

        int size = n + 10;             
        vector<int> freqA(size, 0), freqB(size, 0);

        vector<int> cnt(size, 0);
        for (int i = 0; i < n; ++i) {
            cnt[A[i]]++;
            if (B[i] != A[i]) cnt[B[i]]++;
        }


        vector<char> forced(size, 0);
        for (int x = 0; x < size; ++x) {
            if (cnt[x] == n) forced[x] = 1;
        }
        
        int m1 = 0;
        while (forced[m1]) ++m1;
        int m2 = m1 + 1;

        int answer = forced[m2] ? m2 : m1;
        cout << answer << '\n';
    }
    return 0;
}

