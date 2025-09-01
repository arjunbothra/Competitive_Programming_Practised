#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

        int a, b;
        cin >> a >> b;

        if(a<b) {
            cout << 0 << endl;
        }

        else if(a==b){
            cout << "infinity" << endl;
        }

        else if(a>b){
            int cnt = 0;
            int d = a - b;
            for (int i = 1; i * i <=d; i++)
            {
                if(d % i == 0){
                    if(i > b)cnt++;
                    if(d/i > b && d/i != i)
                        cnt++;
                }
            }
            cout << cnt << endl;
        }

    return 0;
}

