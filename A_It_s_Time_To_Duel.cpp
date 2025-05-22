#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int n){
        bool z = false;
        int zero = 0;

        for (int i = 0; i < n; i++){
            if(v[i]==0){
                zero++;
                z = true;
                if (v[i + 1] == 0 && i<n-1)
                {
                    cout << "YES" << endl;
                    return ;
                }
                else
                        continue;
            }
        }
        if(z==true){
            cout << "NO" << endl;
        }
        else if (z==false)
            cout << "YES" << endl;
}

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
        
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            
        }
        solve(v, n);
        }
    return 0;
}

