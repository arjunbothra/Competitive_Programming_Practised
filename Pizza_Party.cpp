#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        int b, g;
        cin >> b >> g;
        int sboys = 4 * (b + 1),
            sgirls = 3 * g;
        int totalslices = sboys + sgirls;
        int pNeeded = totalslices / 8;

        if(totalslices<8)
            cout << 1;
        else if (pNeeded * 8 == totalslices)
        {
            cout << pNeeded << endl;
        }
        else {
            cout << pNeeded + 1 << endl;
        }
    
    return 0;
}

