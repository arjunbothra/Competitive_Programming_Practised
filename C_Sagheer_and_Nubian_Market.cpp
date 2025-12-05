#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer

int checker(int k, vector<int>& nums){
    int n = nums.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = nums[i] + (i + 1) * k; 

    sort(temp.begin(), temp.end());
    int cost = 0;
    for (int i = 0; i < k; i++)
        cost += temp[i];
    return cost;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        int n, budget;
        cin >> n >> budget;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int ans, cost=0;
        int l = 0, r = n;
        while(l<=r){
            int mid = (l + r) / 2;
            int val = checker(mid, v);
            if (val <= budget)
            {
                l = mid + 1;
                ans = mid;
                cost = val;
            }
            else
                r = mid - 1;
        }

        cout << ans << " " << cost << endl;

        return 0;
}

