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
        vector<int> a(n),b(n) ;
        int maxi = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]==0){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 0;
            }
        }
        cout << maxi<<endl;
    }
    return 0;
}

