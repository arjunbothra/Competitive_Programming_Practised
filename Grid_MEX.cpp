#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int T;
        cin >> T;
    while (T--){
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << (i + j) % N;
            if (j + 1 == N) 
                cout << '\n';
            else 
                cout << ' ';
        }
    }
}

return 0;

    return 0;
}

