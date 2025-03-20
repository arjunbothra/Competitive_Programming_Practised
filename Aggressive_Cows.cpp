#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int cows, int mid){
    int cnt = 1, lastcow = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]-lastcow >=mid){
            cnt++, lastcow = arr[i];
            if(cnt >= cows)
                return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        //Inputs
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int i = 0; i < arr.size(); i++){
            cin >> arr[i];
        }
        
        //Outputs
        sort(arr.begin(), arr.end());
        int low = 0, high = arr[n - 1]-arr[0];
        while(low<=high){
            int mid = (low + high) / 2;

            if(isPossible(arr, c, mid)==true)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << high << endl;
    }
    return 0;
}

