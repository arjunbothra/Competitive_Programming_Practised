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
        sort(v.begin(), v.end());
        long long total = 1;
        for (int i = 0; i < n; i++)
        {
            int possible = v[i] - i;
            if(possible<=0){
                total = 0;
                break;
            }
            total = (total*possible) %998244353;
        }
        cout<< total<< endl;
    }
    return 0;
}

