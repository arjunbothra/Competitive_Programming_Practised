#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mpp;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mpp[a[i]]++;
        }
        if(mpp.size()>2) puts("No");
        else{
            if(abs(mpp.begin()->second-mpp.rbegin()->second )<=1){
                puts("Yes");
            }
            else puts("No");
        }
    }
    return 0;
}