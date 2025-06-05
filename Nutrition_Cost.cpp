#include<bits/stdc++.h>
using namespace std;

int solve(int ){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, c;
        cin >> n >> c;
        vector<int> val(n), vit(n);
        for (int i = 0; i < n; i++){
            cin >> vit[i];
        }
        for (int i = 0; i < n; i++){
            cin >> val[i];
        }

        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {   
            if(mpp.find(val[i])==mpp.end())
            mpp[vit[i]] = val[i];
        }

    }
    return 0;
}

