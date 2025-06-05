#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int odd = 0, even = 0;

        for (int i = 0; i < n; i++){
            if(i%2== 0)
                even += v[i];
            else
                odd += v[i];
        }
        int maxi = max(even, odd);
        cout << maxi<<endl;
    }
    return 0;
}

