#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n = 5;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        double sum=accumulate(v.begin(),v.end(), 0);
        double avg = sum / 5.0;
        int bribe = 0;
        int j = 0;
        while (avg < 7)
        {
            v[j]=10;
            bribe++;
            sum=accumulate(v.begin(),v.end(), 0);
            avg = sum / 5.0;
            j++;
        }
        cout << bribe*100 << endl;
    
    }
        return 0;
}

