#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0, c = 0;
        for (int i = 0; i < n-1; i++)
        {
            cin >> a[i];
            sum += a[i];
            if(a[i] > 0) c++;
            if(a[i] < 0) c--;
        }
        if(c<0) cout<< sum*(-1) << endl;
        else cout<< sum*(-1) << endl;
    }
    return 0;
}