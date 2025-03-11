#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c%2 !=0){
            if(a+(c/2)+1 > b+(c/2))
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
        else{
            if(b+(c/2)+1 > a+c/2)
                cout << "Second" << endl;
            else
                cout << "First" << endl;
        }
    }
    return 0;
}

