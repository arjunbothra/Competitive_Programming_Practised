#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
 
        if(is_sorted(nums.begin(), nums.end()) || k>1)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;
    }
 
    return 0;
}