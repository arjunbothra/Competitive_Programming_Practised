#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int c = 1;
    if(n==1){
         cout<< c;
         return 0;
    }
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for (int i = 1; i < n; i++){
        if(nums[i-1]!=nums[i])
            c++;
    }
    cout << c;
    return 0;
}