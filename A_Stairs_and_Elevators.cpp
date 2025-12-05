#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer
int n, m , s, l, v;
vector<int> stairs, lift;

bool check1(int x){
    return x >= 0 && x < s;
}

bool check2(int x){
    return x >= 0 && x < l;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
       
        cin >> n >> m >> s >> l >> v;

        for (int i = 0; i < s; ++i){
            int u;
            cin >> u;
            stairs.push_back(u);
        }

        for (int i = 0; i < l; ++i){
            int u;
            cin >> u;
            lift.push_back(u);
        }
        
        int q;
        cin >> q;

        while (q--)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            if(a==c){
                cout << abs(d - b) << endl;
                continue;
            }

            int ans = 1e9, ans2=1e9;
            if(a>c){
                swap(a, c);
                swap(b, d);
            }

            //for stairs
            int temp = lower_bound(stairs.begin(), stairs.end(), b)-stairs.begin();

            ans = min(check1(temp) ? abs(b - stairs[temp]) + abs(d - stairs[temp]) : 1e9,
                check1(temp - 1) ? abs(b - stairs[temp - 1]) + abs(d - stairs[temp - 1]) : 1e9) + (c - a);

            int temp2 = lower_bound(lift.begin(), lift.end(), b) - lift.begin();
            ans2 = min(check2(temp2) ? abs(b - lift[temp2]) + abs(d - lift[temp2]) : 1e9,
                       check2(temp2 - 1) ? abs(b - lift[temp2-1]) + abs(d - lift[temp2-1]) : 1e9) +
                   ((c - a) / v )+ ((c - a) % v!=0);

            int final = min(ans, ans2);
            cout << final << endl;
        }

        return 0;
}




