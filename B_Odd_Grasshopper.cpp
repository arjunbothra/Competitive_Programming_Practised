#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
/*
    L R R L
 0 -1 1 4 0
    
    R L   L  R
 1 +1 -1 -4  0 
*/
    int t;
    cin >> t;
    while (t--){
        int x, n;
        cin >> x >> n;
        int finish_pos;

        if (n % 4 == 1)
        {
            finish_pos = -n;
        }
        else if(n%4 == 2){
            finish_pos = 1;
        }
        else if(n%4 == 3){
            finish_pos = n + 1;
        }
        else if(n%4 == 0)
            finish_pos = 0;


        
        if(x %2 == 0){
            cout << x + finish_pos << endl;           
        }
        else {
            cout << x - finish_pos << endl;
        }
    }
    return 0;
}


