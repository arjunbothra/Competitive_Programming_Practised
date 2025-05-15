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
        int mindiff = INT_MAX, lastind=-1, currind=-1;
        bool checker = true;
        //inputs
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i>=1 && v[i]<v[i-1])
                checker = false;
            if(i>=1 && v[i]>=v[i-1] && v[i]-v[i-1]<mindiff){
                mindiff = v[i] - v[i - 1];
                lastind = i - 1;
                currind = i;
            }
        }
        int ans = -1;
        if (checker == false)
            cout << 0 << endl;
        else{
            if(mindiff%2==0){
                int mid = (v[lastind] + v[currind]) / 2;
                ans = mid - v[lastind] + 1;
                cout << ans << endl;
            }
            else {
                int mid = (v[lastind] + v[currind]) / 2;
                ans = v[currind] - mid;
                cout << ans<< endl;
            }
        }
    }
    return 0;
}

