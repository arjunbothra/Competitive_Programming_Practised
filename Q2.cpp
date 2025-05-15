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
        vector<int> nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
        // int cnt = 0, i=0;

        // while (i<nums.size()){
        //     while(i<nums.size() && nums[i]==0)
        //         i++;
        //     if(i==nums.size()) break;
        //     int j = i;
        //     while(j<nums.size() && nums[j]!=0) j++;
        //     vector<int> v(100005, 0);
        //     for (int k = i; k<j; k++){
        //         if(v[nums[k]]==0){
        //             v[nums[k]]=1;
        //         cnt++;
        //         }
        //     }
        //     i=j;
        // }
        // cout << cnt << endl;

        void process(int x, vector<int>& st, int& ans) {
            while (!st.empty() && st.back() > x) {
                st.pop_back();
                ++ans;
            }
            if (x > 0 && (st.empty() || st.back() < x)) {
                st.push_back(x);
            }
        }
    
        int minOperations(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            vector<int> st;
            st.reserve(n);
    
            for (int x : nums)
                process(x, st, ans);  // call the function instead of lambda
    
            process(0, st, ans);  // final cleanup with x = 0
    
            return ans;
        }
    }
    return 0;
}