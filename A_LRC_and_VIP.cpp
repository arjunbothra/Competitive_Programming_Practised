#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n, maxi=0, k=-1;
        cin >> n;
        vector<int> v(n);
        int checker = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]> maxi){
                maxi = v[i];
                k = i;
            }
            if(i>0 && v[i-1] != v[i])
                checker++;
        }

        if(checker==0)
            cout << "No" << endl;
        else{
            cout << "Yes"<< endl;
            for (int i = 0; i < n; i++)
            {
                if(k==i)
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

