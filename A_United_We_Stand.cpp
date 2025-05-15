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
        bool check = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            if(i>=1 && v[i]!=v[i-1])
                check = false;
        }


        vector<int> b, c;
        int maxi = *max_element(v.begin(), v.end());
        if(check){
            cout<< -1 << endl;
        }
        else{
        for (int i = 0; i < n; i++){
            if(v[i]==maxi)
                c.push_back(v[i]);
            else
                b.push_back(v[i]);  
        }

        cout << b.size() << " " << c.size() << endl;
        for(auto i: b){
            cout << i << " ";
        }
        cout << endl;
        for(auto i: c){
            cout << i << " ";
        }
        cout << endl;
        }
    }
    return 0;
}

