#include<bits/stdc++.h>
using namespace std;
// LIS O(N logN) solution;

void printing(int i, vector<int>& ans){
    cout << "Till " << i << ": ";
    for (int j = 0; j < ans.size(); j++){
        cout << ans[j] << " ";
    }
    cout << endl;
}

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
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> ans;
        vector<int> insertedat(n);
        vector<int> prints;
        //fin LIS length & storing the inserted index
        for (int i = 0; i < n; i++)
        {
            if(ans.empty() || v[i]> ans.back()) {
                ans.push_back(v[i]);
                insertedat[i]=ans.size();
            }
            else {
                // printing(i, ans);
                auto it = lower_bound(ans.begin(), ans.end(), v[i]);
                *it = v[i];
                insertedat[i] = it - ans.begin()+1;
            }
        }
        //printing inserted at index
        for (int i = 0; i < insertedat.size(); i++){
            cout << insertedat[i] << " ";
        }
        cout << endl;
        cout << "Printed inserted at" << endl;

        int currlen = ans.size();
        //storing the valid LIS in ptints array to print
        for (int i = n - 1; i >= 0; i--)
        {
            if(insertedat[i]==currlen){
                currlen--;
                // cout<< v[i]<< " ";
                prints.push_back(v[i]);
            }
        }
        //reversing and printing the prints vector
        reverse(prints.begin(), prints.end());
        for (auto i : prints)
            cout << i << " ";

        cout << endl;
        cout << "done" << endl;
    }
    return 0;
}

