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
        int pve=0, nve=0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]==1)
                pve++;
            else
                nve++;
        }
        int cnt = 0;
        while (nve%2 == 1 || pve < nve)
        {
            nve--;
            pve++;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

