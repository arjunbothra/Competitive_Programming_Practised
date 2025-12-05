#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
/*
    Observations--
    if one number not dividing then just add the difference


    What if 2 numbers not divinding?


*/


bool checker(int n){
    vector<int> d(10, 0);
    int temp = n;
    while (temp != 0)
    {
        int l = temp % 10;
        d[l] = 1;
        temp /= 10;
    }

    for (int i = 1; i <= 9; ++i){
        if(d[i]==1){
            if(n%i != 0)
                return false;
        }
    }
    return true;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
    
        // bool flag = false;
        while (true){
            if(checker(n))
                break;
            else
                n+= 1;
        }

        cout << n << endl;
    }
    return 0;
}

