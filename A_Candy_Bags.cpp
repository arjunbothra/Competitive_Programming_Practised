#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> bags(n);
    int left = 1, right = n * n;
    for (int i = 0; i<n; i++){
        for (int j = 0; j < n / 2; j++){
            bags[i].push_back(left++);
            bags[i].push_back(right--);
        }
    }
    for (int i = 0; i < n; i++){
        for(int num:bags[i]){
            cout << num <<" "; 
        }
        cout << endl;
    }
        return 0;
}